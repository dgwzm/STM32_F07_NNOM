#include <stdio.h>
#include "weights.h"
#include "q_conv_layer.h"

// Conv0
static weight_t conv0_weight[CONV0_WEIGHT_SIZE] = {
    #include "data/conv0_0_weight_data.h"
};
static bias_t conv0_bias[CONV0_BIAS_SIZE] = {
    #include "data/conv0_0_bias.h"
};

void q_conv_layer_forward_0(input_data_t *input, output_data_t *output)
{
    int sum = 0;
    int kernel_index;
    int input_index_start;
    int input_index;
    int output_index = 0;

	float M = CONV0_S_x * CONV0_S_w / CONV0_S_a;

	// 输出通道
	LOOP_OUT_CH:for (int out_c = 0; out_c < CONV0_OUT_CHANNEL; out_c++)
	{
		// 输出数据(2D)行
		LOOP_OUT_ROW:for (int row = 0; row < CONV0_OUT_SIZE; row++)
		{
#pragma HLS pipeline
			// 输出数据(2D)列
			LOOP_OUT_COL:for (int col = 0; col < CONV0_OUT_SIZE; col++)
			{
				sum = 0;
				// 输入通道
				LOOP_IN_CH:for (int in_c = 0; in_c < CONV0_IN_CHANNEL; in_c++)
				{
					// 单次卷积运算所需输入数据的起始索引
					input_index_start = (in_c * CONV0_IN_SHAPE) + (row * CONV0_STRIDE * CONV0_IN_SIZE) + (col * CONV0_STRIDE);
					// 单次卷积运算对应卷积核的起始索引(左上角)
					kernel_index = (out_c * CONV0_KERNEL_OUT) + (in_c * CONV0_KERNEL_SHAPE);
					// 卷积核(2D)行
					LOOP_K_ROW:for (int kernel_row = 0; kernel_row < CONV0_KERNEL_SIZE; kernel_row++)
					{
						// 输入数据索引
						input_index = input_index_start + kernel_row * CONV0_IN_SIZE;
						// 卷积核(2D)列
						LOOP_K_COL:for (int kernel_col = 0; kernel_col < CONV0_KERNEL_SIZE; kernel_col++)
						{
							// 单次卷积运算结果累加
							sum += (input[input_index] - CONV0_Z_x) * conv0_weight[kernel_index];
							kernel_index++;
							input_index++;
						}
					}
				}
				output[output_index] = (uint8_t)(sum * M + conv0_bias[out_c] + 0.5 + CONV0_Z_a);
				output_index++;
			}
		}
	}
}

// Conv1
static weight_t conv4_weight[CONV4_WEIGHT_SIZE] = {
    #include "data/conv4_0_weight_data.h"
};
static bias_t conv4_bias[CONV4_BIAS_SIZE] = {
    #include "data/conv4_0_bias.h"
};

void q_conv_layer_forward_4(input_data_t *input, output_data_t *output)
{
    int sum = 0;
    int kernel_index;
    int input_index;
    int output_index = 0;

	float M = CONV4_S_x * CONV4_S_w / CONV4_S_a;

	// 输出通道
	LOOP_OUT_CH:for (int out_c = 0; out_c < CONV4_OUT_CHANNEL; out_c++)
	{
		// 输出数据(2D)行
		LOOP_OUT_ROW:for (int row = 0; row < CONV4_OUT_SIZE; row++)
		{
#pragma HLS pipeline
			// 输出数据(2D)列
			LOOP_OUT_COL:for (int col = 0; col < CONV4_OUT_SIZE; col++)
			{
				sum = 0;
				// 单次卷积运算对应卷积核的起始索引(左上角)
				kernel_index = (out_c * CONV4_KERNEL_OUT);
				// 单次卷积运算所需输入数据的起始索引
				input_index = (row * CONV4_STRIDE * CONV4_IN_SIZE) + (col * CONV4_STRIDE);
				// 输入通道
				LOOP_IN_CH:for (int in_c = 0; in_c < CONV4_IN_CHANNEL; in_c++)
				{
					// 单次卷积运算结果累加
					sum += (input[input_index] - CONV4_Z_x) * conv4_weight[kernel_index];
					kernel_index++;
					input_index += CONV4_IN_SHAPE;
				}
				output[output_index] = (uint8_t)(sum * M + conv4_bias[out_c] + 0.5 + CONV4_Z_a);
				output_index++;
			}
		}
	}
}
