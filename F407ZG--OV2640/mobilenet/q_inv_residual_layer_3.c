#include "q_inv_residual_layer.h"
#include "weights.h"

static void q_conv_layer_forward_0(input_data_t *input, output_data_t *output);
static void q_conv_layer_forward_1(input_data_t *input, output_data_t *output);
static void q_conv_layer_forward_2(input_data_t *input, output_data_t *output);
static void q_relu_layer_forward_0(input_data_t *input, output_data_t *output);
static void q_relu_layer_forward_1(input_data_t *input, output_data_t *output);

void q_inv_residual_forward_3(
    input_data_t *input, 
    output_data_t *buffer
)
{
    // pw
    q_conv_layer_forward_0(input, buffer);
    q_relu_layer_forward_0(buffer, buffer);
    // dw
    q_conv_layer_forward_1(buffer, input);
    q_relu_layer_forward_1(input, input);
	// linear
	q_conv_layer_forward_2(input, buffer);
}

static weight_t pw_weight[INV3_PW_WEIGHT_SIZE] = {
    #include "data/inv3_0_weight_data.h"
};
static bias_t pw_bias[INV3_PW_BIAS_SIZE] = {
    #include "data/inv3_0_bias.h"
};

static void q_conv_layer_forward_0(input_data_t *input, output_data_t *output)
{
    int sum = 0;
    int kernel_index;
    int input_index;
    int output_index = 0;

	float M = INV3_PW_S_x * INV3_PW_S_w / INV3_PW_S_a;

	// 输出通道
	LOOP_OUT_CH:for (int out_c = 0; out_c < INV3_PW_OUT_CHANNEL; out_c++)
	{
		// 输出数据(2D)行
		LOOP_OUT_ROW:for (int row = 0; row < INV3_PW_OUT_SIZE; row++)
		{
#pragma HLS pipeline
			// 输出数据(2D)列
			LOOP_OUT_COL:for (int col = 0; col < INV3_PW_OUT_SIZE; col++)
			{
				sum = 0;
				// 单次卷积运算对应卷积核的起始索引(左上角)
				kernel_index = (out_c * INV3_PW_KERNEL_OUT);
				// 单次卷积运算所需输入数据的起始索引
				input_index = (row * INV3_PW_STRIDE * INV3_PW_IN_SIZE) + (col * INV3_PW_STRIDE);
				// 输入通道
				LOOP_IN_CH:for (int in_c = 0; in_c < INV3_PW_IN_CHANNEL; in_c++)
				{
					// 单次卷积运算结果累加
					sum += (input[input_index] - INV3_PW_Z_x) * pw_weight[kernel_index];
					kernel_index++;
					input_index += INV3_PW_IN_SHAPE;
				}
				output[output_index] = (uint8_t)(sum * M + pw_bias[out_c] + 0.5 + INV3_PW_Z_a);
				output_index++;
			}
		}
	}
}

static weight_t dw_weight[INV3_DW_WEIGHT_SIZE] = {
    #include "data/inv3_2_weight_data.h"
};
static bias_t dw_bias[INV3_DW_BIAS_SIZE] = {
    #include "data/inv3_2_bias.h"
};

static void q_conv_layer_forward_1(input_data_t *input, output_data_t *output)
{
    int sum = 0;
    int kernel_index_start;
    int kernel_index;
    int input_index_start;
    int input_index;
    int output_index = 0;

    float M = INV3_DW_S_x * INV3_DW_S_w / INV3_DW_S_a;

    // 组
    LOOP_OUT_G:for (int g = 0; g < INV3_DW_GROUPS; g++)
    {
		// 输出数据(2D)行
		LOOP_OUT_ROW:for (int row = 0; row < INV3_DW_OUT_SIZE; row++)
		{
			// 输出数据(2D)列
			LOOP_OUT_COL:for (int col = 0; col < INV3_DW_OUT_SIZE; col++)
			{
				// 单次卷积运算所需输入数据的起始索引
				input_index_start = (g * INV3_DW_IN_SHAPE) + (row * INV3_DW_STRIDE * INV3_DW_IN_SIZE) + (col * INV3_DW_STRIDE);
				// 单次卷积运算对应卷积核的起始索引(左上角)
				kernel_index = g * INV3_DW_KERNEL_SHAPE;
				sum = 0;
				// 卷积核(2D)行
				LOOP_K_ROW:for (int kernel_row = 0; kernel_row < INV3_DW_KERNEL_SIZE; kernel_row++)
				{
					// 输入数据索引
					input_index = input_index_start + kernel_row * INV3_DW_IN_SIZE;
					// 卷积核(2D)列
					LOOP_K_COL:for (int kernel_col = 0; kernel_col < INV3_DW_KERNEL_SIZE; kernel_col++)
					{
						// 单次卷积运算结果累加
						sum += (input[input_index] - INV3_DW_Z_x) * dw_weight[kernel_index];
						input_index++;
						kernel_index++;
					}
				}
				output[output_index] = (uint8_t)(sum * M + dw_bias[g] + 0.5 + INV3_DW_Z_a);
				output_index++;
			}
		}
	}
}

static weight_t linear_weight[INV3_LINEAR_WEIGHT_SIZE] = {
    #include "data/inv3_4_weight_data.h"
};
static bias_t linear_bias[INV3_LINEAR_BIAS_SIZE] = {
    #include "data/inv3_4_bias.h"
};

static void q_conv_layer_forward_2(input_data_t *input, output_data_t *output)
{
    int sum = 0;
    int kernel_index;
    int input_index;
    int output_index = 0;

	float M = INV3_LINEAR_S_x * INV3_LINEAR_S_w / INV3_LINEAR_S_a;

	// 输出通道
	LOOP_OUT_CH:for (int out_c = 0; out_c < INV3_LINEAR_OUT_CHANNEL; out_c++)
	{
		// 输出数据(2D)行
		LOOP_OUT_ROW:for (int row = 0; row < INV3_LINEAR_OUT_SIZE; row++)
		{
#pragma HLS pipeline
			// 输出数据(2D)列
			LOOP_OUT_COL:for (int col = 0; col < INV3_LINEAR_OUT_SIZE; col++)
			{
				sum = 0;
				// 单次卷积运算对应卷积核的起始索引(左上角)
				kernel_index = (out_c * INV3_LINEAR_KERNEL_OUT);
				// 单次卷积运算所需输入数据的起始索引
				input_index = (row * INV3_LINEAR_STRIDE * INV3_LINEAR_IN_SIZE) + (col * INV3_LINEAR_STRIDE);
				// 输入通道
				LOOP_IN_CH:for (int in_c = 0; in_c < INV3_LINEAR_IN_CHANNEL; in_c++)
				{
					// 单次卷积运算结果累加
					sum += (input[input_index] - INV3_LINEAR_Z_x) * linear_weight[kernel_index];
					kernel_index++;
					input_index += INV3_LINEAR_IN_SHAPE;
				}
				output[output_index] = (uint8_t)(sum * M + linear_bias[out_c] + 0.5 + INV3_LINEAR_Z_a);
				output_index++;
			}
		}
	}
}


static void q_relu_layer_forward_0(input_data_t *input, output_data_t *output)
{
    for (size_t i = 0; i < INV3_RELU0_SIZE; i++)
    {
        output[i] = (input[i] < INV3_RELU0_Z_a) ? INV3_RELU0_Z_a : input[i];
    }
}

static void q_relu_layer_forward_1(input_data_t *input, output_data_t *output)
{
    for (size_t i = 0; i < INV3_RELU1_SIZE; i++)
    {
        output[i] = (input[i] < INV3_RELU1_Z_a) ? INV3_RELU1_Z_a : input[i];
    }
}
