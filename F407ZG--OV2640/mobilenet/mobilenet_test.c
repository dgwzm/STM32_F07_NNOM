#include "mobilenet_test.h"

#define BUFFER_MAX       21632

float image[] = {
    #include "data/input_data.h"
};
float target[] = {
    #include "data/output_data.h"
};
float res[55];

output_data_t output_buffer_0[BUFFER_MAX];
output_data_t output_buffer_1[BUFFER_MAX];

int Mobilenet()
{
    //for (int j =0;j<100;j++)
    //{
		for (int i = 0; i < 784; i++)
		{
				output_buffer_1[i] = (input_data_t)(image[i] / 0.007874015718698502);
		}
		q_conv_layer_forward_0(output_buffer_1, output_buffer_0);
		q_relu_layer_forward_0(output_buffer_0, output_buffer_0);
		q_inv_residual_forward_1(output_buffer_0, output_buffer_1);
		q_inv_residual_forward_2(output_buffer_1, output_buffer_0);
		q_inv_residual_forward_3(output_buffer_0, output_buffer_1);
		q_conv_layer_forward_4(output_buffer_1, output_buffer_0);
		q_relu_layer_forward_4(output_buffer_0, output_buffer_0);
		q_global_avg_pool_forward(output_buffer_0, output_buffer_1);
		q_linear_layer_forward(output_buffer_1, output_buffer_0);

		for (int i = 0; i < FC_OUT_FEATURE; i++)
		{
				res[i] = FC_S_a * (output_buffer_0[i] - FC_Z_a);
		}

		if (verify_output(res,
				target,
				FC_OUT_FEATURE,
				1) == 0)
		{
				printf("verify sucess!\n");
		}
        //printf("Get %d ",j);
    //}

    return 0;
}

static int verify_output(float *data1, float *data2, int channel, int size)
{
    int count = 0;

    for (int ch = 0; ch < channel; ch++)
    {
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                if (fabsf(data1[ch*size*size + row*size + col] - data2[ch*size*size + row*size + col]) > 1e-3)
                {
                    count++;
                    printf("[error]:[%d;%d] %d %d %d\n", 
                        data1[ch*size*size + row*size + col], 
                        data2[ch*size*size + row*size + col], 
                        ch, row, col);
                }
            }
        }
    }
    if (count != 0)
    {
        printf("error: %f%%", (float)count * 100 / (channel * size * size));
    }
    else
    {
        return 0;
    }
}
