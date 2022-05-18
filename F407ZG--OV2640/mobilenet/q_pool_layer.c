#include <stdio.h>
#include "weights.h"
#include "q_pool_layer.h"

void q_global_avg_pool_forward(input_data_t *input, output_data_t *output)
{
    int input_index = 0;
    float sum;

    for (int ch = 0; ch < AVG_IN_CHANNEL; ch++)
    {
        sum = 0;
        for (int row = 0; row < AVG_IN_SIZE; row++)
        {
            for (int col = 0; col < AVG_IN_SIZE; col++)
            {
                sum += input[input_index];
                input_index++;
            }
        }
        output[ch] = (uint8_t)(sum / AVG_IN_SHAPE + 0.5);
    }
}
