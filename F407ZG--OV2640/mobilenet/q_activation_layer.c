#include "q_activation_layer.h"
#include "weights.h"

void q_relu_layer_forward_0(input_data_t *input, output_data_t *output)
{
    for (size_t i = 0; i < RELU0_SIZE; i++)
    {
        output[i] = (input[i] < RELU0_Z_a) ? RELU0_Z_a : input[i];
    }
}

void q_relu_layer_forward_4(input_data_t *input, output_data_t *output)
{
    for (size_t i = 0; i < RELU4_SIZE; i++)
    {
        output[i] = (input[i] < RELU4_Z_a) ? RELU4_Z_a : input[i];
    }
}
