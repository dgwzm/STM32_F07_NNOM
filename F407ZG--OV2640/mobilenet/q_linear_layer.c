#include <stdio.h>
#include "weights.h"
#include "q_linear_layer.h"

static weight_t weight[FC_WEIGHT_NUM] = {
    #include "data/fc_weight_data.h"
};
static bias_t bias[FC_BIAS_NUM] = {
    #include "data/fc_bias.h"
};

void q_linear_layer_forward(input_data_t *input, output_data_t *output)
{
    float M = FC_S_x * FC_S_w / FC_S_a;
    int weight_index = 0;
    int sum;

    for (int i = 0; i < FC_OUT_FEATURE; i++)
    {
        sum = 0;
        for (int j = 0; j < FC_IN_FEATURE; j++)
        {
            sum += weight[weight_index] * (input[j] - FC_Z_x);
            weight_index++;
        }
        output[i] = (uint8_t)(sum * M + bias[i] + 0.5 + FC_Z_a);
    }
}
