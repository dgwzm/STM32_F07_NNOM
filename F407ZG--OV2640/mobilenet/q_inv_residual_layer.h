#ifndef Q_INV_RESIDUAL_LAYER_H
#define Q_INV_RESIDUAL_LAYER_H

#include "types.h"

void q_inv_residual_forward_1(
    input_data_t *input, 
    output_data_t *buffer
);

void q_inv_residual_forward_2(
   input_data_t *input,
   output_data_t *buffer
);

void q_inv_residual_forward_3(
   input_data_t *input,
   output_data_t *buffer
);

#endif
