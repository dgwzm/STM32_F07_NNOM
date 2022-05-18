#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_LSTM_LSTM_CELL_KERNEL_0 {33, 73, -59, 57, 39, -39, -41, -56, 6, 63, 89, -58, -22, 21, 73, -31, -83, 28, -99, -40, -83, -4, -95, 1, -3, -60, 37, -10, 34, 101, -83, 45}

#define TENSOR_LSTM_LSTM_CELL_KERNEL_0_DEC_BITS {8}

#define TENSOR_LSTM_LSTM_CELL_RECURRENT_KERNEL_0 {-16, 43, -8, 49, 36, 74, -18, -58, -66, -54, 47, -15, 19, -33, -20, 11, -40, -10, 90, -32, -56, 83, -11, 31, 27, -11, 73, 12, 34, -64, -19, -1, -82, 30, -45, -104, 48, -4, -32, 5, -32, -34, 30, -5, 31, 10, 52, -47, 17, -31, 1, -24, -26, 41, -60, 6, 26, 23, -10, -73, 7, 20, 25, -75, 21, -64, -48, -42, 68, -11, 59, -21, -24, -27, -9, 57, 4, 14, 52, -5, -38, -5, 51, 18, -57, 91, -24, 27, -16, -3, 26, -50, -9, -16, -84, 52, -39, -67, 31, -35, -79, 8, 14, -19, 25, 36, 14, 12, 45, 34, 75, -83, 51, 8, 35, -101, -45, -35, 69, 6, 69, -120, 2, 30, -37, 46, -11, 15, -34, -20, -10, 37, 53, 0, -53, -111, -40, 112, -17, 26, 27, 0, 47, -3, -39, 60, 26, -34, 64, 21, 4, 7, -46, 37, -22, 21, 65, 42, 29, 62, -49, 74, 33, -39, -9, 14, -21, 21, 37, 30, 20, -31, 29, -4, 37, 15, -29, -32, 98, 105, 22, 107, -5, 50, 41, -58, -21, 1, -43, -59, -79, -25, -50, -44, -35, 6, -14, 64, -14, 55, -38, 14, -52, -2, -59, 49, -35, 1, -25, -51, -18, -15, 17, -28, -25, 12, -57, -25, 5, 96, 52, -55, 39, 95, -27, -46, -9, -22, -26, 17, -10, -98, 39, -7, -98, -6, 76, 119, -125, 50, 30, 4, 54, -36, -16, -49, 2, 5, -61, 6, -20, 10, 35, -5, -23, -10}

#define TENSOR_LSTM_LSTM_CELL_RECURRENT_KERNEL_0_DEC_BITS {8}

#define TENSOR_LSTM_LSTM_CELL_BIAS_0 {0, 0, 0, 0, 0, 0, 0, 0, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define TENSOR_LSTM_LSTM_CELL_BIAS_0_DEC_BITS {7}

#define LSTM_BIAS_LSHIFT {8}

#define LSTM_OUTPUT_RSHIFT {7}

#define TENSOR_LSTM_1_LSTM_CELL_1_KERNEL_0 {-42, -1, -27, 4, 80, 58, 63, 16, -54, 31, 34, 55, -69, 41, -58, -8, -24, -44, -70, -61, -15, 36, 77, 26, -35, 14, -36, -16, 30, -20, -52, -73, 20, 6, -42, -4, 43, 58, -20, 70, 31, -18, 2, 38, 67, 65, 50, -3, -28, -27, -55, 17, 53, 5, 83, 48, -32, 41, -79, 76, 0, -45, -7, -33, 76, -9, 68, 82, -78, 14, 56, 32, 60, 52, -36, 26, 38, 56, 66, 58, 62, -58, 41, 50, 77, -73, 63, 30, -16, -19, -53, -36, -48, 6, 68, -16, -47, 16, -31, -80, 38, 24, 56, -38, -3, -83, -26, -61, -73, 42, -18, 71, 7, -49, 9, -2, 30, -20, 44, -71, 83, 32, -41, 57, -20, -11, 59, 74, -44, 48, -74, 12, 55, -32, 60, -49, -73, 44, -73, 18, 82, 62, -82, 6, -26, 2, 11, 19, 2, -52, -21, -14, 25, -64, 73, -63, -74, -22, -15, 61, 73, 50, 20, 66, -55, 13, 10, -66, -45, -1, 59, -49, 15, -59, 70, -53, 50, 63, 66, 53, -29, 84, 7, -63, 70, 59, -29, -31, -38, 43, -54, 68, 44, -72, -38, -80, -23, -28, -9, -9, 71, 48, 61, 55, -17, -63, 30, 6, -40, -30, 33, 16, 69, -71, -72, 46, -65, 24, -43, 29, 1, 69, 56, -76, -60, 4, -28, 12, 10, -55, -24, 45, 63, -7, 50, 27, -61, -52, 59, -73, -48, 25, 34, -58, -4, -39, 11, -54, -83, 65, 14, -64, -42, -67, -29, -54, 45, 49, -12, -49, -76, 50, -77, 21, -48, 68, 55, -36, 56, 25, -50, 58, 53, 51, -61, -52, -48, -69, 3, -15, -26, -20, -19, -49, 77, -75, 66, -11, -46, 43, 56, 33, 12, 52, -12, 3, 54, 62, -55, -26, 16, 33, -70, 61, 72, -58, 5, -11, -81, 81, 64, 28, -32, -64, -6, -50, 10, 41, 46, 10, -8, -58, 53, 72, -47, 65, 53, -26, -74, 58, 55, 25, -67, -7, 77, -37, -79, 17, -4, 34, 76, -47, -75, 30, -52, 21, 19, 61, 22, -70, -5, 43, -70, -68, -13, -8, 46, -26, 42, 5, -78, -36, 3, 78, 78, 11, 5, 36, -12, 73, -34, 31, -62, 17, -13, 0, -25, -39, 50, 16, 81, 55, 56, 70}

#define TENSOR_LSTM_1_LSTM_CELL_1_KERNEL_0_DEC_BITS {8}

#define TENSOR_LSTM_1_LSTM_CELL_1_RECURRENT_KERNEL_0 {-27, -80, 20, 11, 4, 1, 75, -39, 1, -74, -23, -62, -8, 14, -14, -107, -26, -7, 1, 55, 4, 15, -23, -90, 24, 19, -76, 8, 17, 14, 24, 43, -17, -16, 11, 9, 12, -42, -22, 24, 37, 6, 37, -29, -55, 23, -23, -46, 31, -7, 19, -24, 17, -32, 0, 15, 52, 29, 28, 43, 33, 22, 17, 67, 8, -44, 26, -14, -2, -6, 43, 4, -47, 73, 4, -18, 0, 29, 69, 59, -37, -18, -56, -71, 31, 9, 21, 25, 16, 72, 44, -15, 55, 47, 31, -15, 30, -5, -47, -43, -52, -51, -27, 45, -76, -9, -39, -47, 7, -17, 35, -5, -53, 9, 58, 27, -41, -83, -37, 6, 2, -49, 52, 9, -62, -29, -21, -3, 21, -3, -59, 24, -33, -22, 22, 24, 46, -29, 42, -7, 11, 41, 15, -10, -75, -24, 73, -2, -50, 6, -39, 7, 3, -48, 12, 54, -15, 55, 21, -30, 7, -2, -24, -29, 62, 37, 3, 11, -64, 8, 42, -29, -11, -18, -62, -49, -41, -22, -7, 32, 15, -37, 48, -27, 32, -22, -15, -16, -27, 50, -35, 24, 0, -56, -12, 34, -41, -77, 32, -65, -31, 18, -2, 29, -77, -5, 62, -5, -29, -20, 4, 16, -6, 42, -4, 54, 61, 52, -24, 15, 39, -30, 34, 53, -69, 19, 72, -59, -16, -88, -43, -30, -2, -23, -2, 21, -37, 53, 14, -17, -23, 16, 14, 1, 48, -6, -25, -24, -11, 24, -81, -33, -40, 26, 55, -22, 50, 13, -8, 72, 35, -40, 28, -62, 98, -32, -13, 8, 26, -3, 2, -16, 23, -26, -73, -16, -80, -7, 16, 42, 33, -17, -3, 39, 43, 57, -35, -5, -44, -27, 41, 22, -68, -7, 12, -21, -12, 6, -32, -10, 123, -54, -18, -42, -7, -20, 19, 28, 6, 24, 39, -3, -19, -20, -25, 8, 5, -40, 15, -1, -35, 45, -14, 51, -57, -41, -5, -52, 38, 21, -4, 46, -53, -31, -8, 48, 37, -5, 32, -6, 22, -28, -38, -67, 16, 15, -32, 19, -25, -8, 52, -22, -92, 50, -14, -54, -56, -19, -42, 8, -32, -39, 36, -37, -35, 25, 12, -31, -16, -15, 1, -17, -59, 22, -72, -34, -48, -15, -21, 52, -21, -16, -44, 12, 47, 26, 14, -7, 5, -15, -17, 4, -26, -48, 11, -5, 22, -56, 4, -30, -19, 38, -23, -16, -32, -58, 18, -46, 9, -60, 18, 14, 23, -50, 11, -15, -62, 24, 46, 0, 2, 31, -15, -42, 58, 51, 80, -33, -10, -10, 30, -8, 42, -26, 58, 2, 33, -46, 36, 85, 22, 4, -18, -10, 23, -21, -32, -21, 1, 18, -18, -54, -12, 39, 0, -58, 15, 67, 67, 55, 13, -23, -87, 23, -17, -11, 20, 27, -41, 24, -30, -20, 11, 16, 3, -42, 10, 19, -67, 41, -13, -14, 3, 36, 52, -13, 80, -7, -5, -37, 19, 50, -38, -13, 1, -43, -16, 59, 14, 6, 17, -17, 99, 46, 30, -19, -23, -6, 1, -22, -22, 13, -57, -4, -1, -12, -6, -8, 28, 58, -59, -11, 41, -35, 19, -37, -66, -13, 48, 52, 42, 20, -15, -11, -35, 41, -42, 23, -23, -10, 8, -1, 27, 3, 64, 7, -34, -1, 59, -41, -11, 16, 15, -40, -14, 13, -32, -22, 5, -93, -65, -21, 7, -59, 64, 32, -9, -8, -8, 3, 84, -93, 51, 73, -12, 0}

#define TENSOR_LSTM_1_LSTM_CELL_1_RECURRENT_KERNEL_0_DEC_BITS {8}

#define TENSOR_LSTM_1_LSTM_CELL_1_BIAS_0 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define TENSOR_LSTM_1_LSTM_CELL_1_BIAS_0_DEC_BITS {7}

#define LSTM_1_BIAS_LSHIFT {9}

#define LSTM_1_OUTPUT_RSHIFT {6}

#define TENSOR_DENSE_KERNEL_0 {-63, -66, 78, 47, -66, 75, -39, 57, -66, -15, 30, 16, -55, -17, 14, -31, 7, 69, -61, 84, -76, -30, -66, -55}

#define TENSOR_DENSE_KERNEL_0_DEC_BITS {7}

#define TENSOR_DENSE_BIAS_0 {0, 0}

#define TENSOR_DENSE_BIAS_0_DEC_BITS {7}

#define DENSE_BIAS_LSHIFT {10}

#define DENSE_OUTPUT_RSHIFT {6}


/* output q format for each layer */
#define INPUT_2_OUTPUT_DEC 7
#define INPUT_2_OUTPUT_OFFSET 0
#define LSTM_OUTPUT_DEC 8
#define LSTM_OUTPUT_OFFSET 0
#define DROPOUT_OUTPUT_DEC 8
#define DROPOUT_OUTPUT_OFFSET 0
#define LSTM_1_OUTPUT_DEC 10
#define LSTM_1_OUTPUT_OFFSET 0
#define DROPOUT_1_OUTPUT_DEC 10
#define DROPOUT_1_OUTPUT_OFFSET 0
#define DENSE_OUTPUT_DEC 11
#define DENSE_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[200] = {0};

const nnom_shape_data_t tensor_input_2_dim[] = {200, 1};
const nnom_qformat_param_t tensor_input_2_dec[] = {7};
const nnom_qformat_param_t tensor_input_2_offset[] = {0};
const nnom_tensor_t tensor_input_2 = {
    .p_data = (void*)nnom_input_data,
    .dim = (nnom_shape_data_t*)tensor_input_2_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_input_2_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_input_2_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};

const nnom_io_config_t input_2_config = {
    .super = {.name = "input_2"},
    .tensor = (nnom_tensor_t*)&tensor_input_2
};
const int8_t tensor_lstm_lstm_cell_kernel_0_data[] = TENSOR_LSTM_LSTM_CELL_KERNEL_0;

const nnom_shape_data_t tensor_lstm_lstm_cell_kernel_0_dim[] = {1, 32};
const nnom_qformat_param_t tensor_lstm_lstm_cell_kernel_0_dec[] = TENSOR_LSTM_LSTM_CELL_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_lstm_cell_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_lstm_cell_kernel_0 = {
    .p_data = (void*)tensor_lstm_lstm_cell_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_lstm_cell_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_lstm_cell_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_lstm_cell_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_lstm_cell_recurrent_kernel_0_data[] = TENSOR_LSTM_LSTM_CELL_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_lstm_cell_recurrent_kernel_0_dim[] = {8, 32};
const nnom_qformat_param_t tensor_lstm_lstm_cell_recurrent_kernel_0_dec[] = TENSOR_LSTM_LSTM_CELL_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_lstm_cell_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_lstm_cell_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_lstm_cell_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_lstm_cell_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_lstm_cell_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_lstm_cell_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_lstm_cell_bias_0_data[] = TENSOR_LSTM_LSTM_CELL_BIAS_0;

const nnom_shape_data_t tensor_lstm_lstm_cell_bias_0_dim[] = {32};
const nnom_qformat_param_t tensor_lstm_lstm_cell_bias_0_dec[] = TENSOR_LSTM_LSTM_CELL_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_lstm_cell_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_lstm_cell_bias_0 = {
    .p_data = (void*)tensor_lstm_lstm_cell_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_lstm_cell_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_lstm_cell_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_lstm_cell_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_lstm_cell_config = {
    .super = {.name = "lstm"},
    .weights = (nnom_tensor_t*)&tensor_lstm_lstm_cell_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_lstm_cell_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_lstm_cell_bias_0,
    .q_dec_z = 6,
    .q_dec_h = 8,
    .q_dec_c = 7,
    .units = 8
};

const nnom_rnn_config_t lstm_config = {
    .super = {.name = "lstm"},
    .return_sequence = true,
    .stateful = true,
    .go_backwards = false
};
const int8_t tensor_lstm_1_lstm_cell_1_kernel_0_data[] = TENSOR_LSTM_1_LSTM_CELL_1_KERNEL_0;

const nnom_shape_data_t tensor_lstm_1_lstm_cell_1_kernel_0_dim[] = {8, 48};
const nnom_qformat_param_t tensor_lstm_1_lstm_cell_1_kernel_0_dec[] = TENSOR_LSTM_1_LSTM_CELL_1_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_1_lstm_cell_1_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_1_lstm_cell_1_kernel_0 = {
    .p_data = (void*)tensor_lstm_1_lstm_cell_1_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_1_lstm_cell_1_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_1_lstm_cell_1_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_1_lstm_cell_1_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_1_lstm_cell_1_recurrent_kernel_0_data[] = TENSOR_LSTM_1_LSTM_CELL_1_RECURRENT_KERNEL_0;

const nnom_shape_data_t tensor_lstm_1_lstm_cell_1_recurrent_kernel_0_dim[] = {12, 48};
const nnom_qformat_param_t tensor_lstm_1_lstm_cell_1_recurrent_kernel_0_dec[] = TENSOR_LSTM_1_LSTM_CELL_1_RECURRENT_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_1_lstm_cell_1_recurrent_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_1_lstm_cell_1_recurrent_kernel_0 = {
    .p_data = (void*)tensor_lstm_1_lstm_cell_1_recurrent_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_1_lstm_cell_1_recurrent_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_1_lstm_cell_1_recurrent_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_1_lstm_cell_1_recurrent_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_lstm_1_lstm_cell_1_bias_0_data[] = TENSOR_LSTM_1_LSTM_CELL_1_BIAS_0;

const nnom_shape_data_t tensor_lstm_1_lstm_cell_1_bias_0_dim[] = {48};
const nnom_qformat_param_t tensor_lstm_1_lstm_cell_1_bias_0_dec[] = TENSOR_LSTM_1_LSTM_CELL_1_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_lstm_1_lstm_cell_1_bias_0_offset[] = {0};
const nnom_tensor_t tensor_lstm_1_lstm_cell_1_bias_0 = {
    .p_data = (void*)tensor_lstm_1_lstm_cell_1_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_lstm_1_lstm_cell_1_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_lstm_1_lstm_cell_1_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_lstm_1_lstm_cell_1_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_lstm_cell_config_t lstm_1_lstm_cell_config = {
    .super = {.name = "lstm_1"},
    .weights = (nnom_tensor_t*)&tensor_lstm_1_lstm_cell_1_kernel_0,
    .recurrent_weights = (nnom_tensor_t*)&tensor_lstm_1_lstm_cell_1_recurrent_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_lstm_1_lstm_cell_1_bias_0,
    .q_dec_z = 6,
    .q_dec_h = 9,
    .q_dec_c = 8,
    .units = 12
};

const nnom_rnn_config_t lstm_1_config = {
    .super = {.name = "lstm_1"},
    .return_sequence = false,
    .stateful = true,
    .go_backwards = false
};
const int8_t tensor_dense_kernel_0_data[] = TENSOR_DENSE_KERNEL_0;

const nnom_shape_data_t tensor_dense_kernel_0_dim[] = {12, 2};
const nnom_qformat_param_t tensor_dense_kernel_0_dec[] = TENSOR_DENSE_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_dense_kernel_0 = {
    .p_data = (void*)tensor_dense_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 2,
    .bitwidth = 8
};
const int8_t tensor_dense_bias_0_data[] = TENSOR_DENSE_BIAS_0;

const nnom_shape_data_t tensor_dense_bias_0_dim[] = {2};
const nnom_qformat_param_t tensor_dense_bias_0_dec[] = TENSOR_DENSE_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_dense_bias_0_offset[] = {0};
const nnom_tensor_t tensor_dense_bias_0 = {
    .p_data = (void*)tensor_dense_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_dense_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_dense_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_dense_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t dense_output_shift[] = DENSE_OUTPUT_RSHIFT;
const nnom_qformat_param_t dense_bias_shift[] = DENSE_BIAS_LSHIFT;
const nnom_dense_config_t dense_config = {
    .super = {.name = "dense"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_dense_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_dense_bias_0,
    .output_shift = (nnom_qformat_param_t *)&dense_output_shift,
    .bias_shift = (nnom_qformat_param_t *)&dense_bias_shift
};
static int8_t nnom_output_data[2] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {2};
const nnom_qformat_param_t tensor_output0_dec[] = {DENSE_OUTPUT_DEC};
const nnom_qformat_param_t tensor_output0_offset[] = {0};
const nnom_tensor_t tensor_output0 = {
    .p_data = (void*)nnom_output_data,
    .dim = (nnom_shape_data_t*)tensor_output0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_output0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_output0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_io_config_t output0_config = {
    .super = {.name = "output0"},
    .tensor = (nnom_tensor_t*)&tensor_output0
};
/* model version */
#define NNOM_MODEL_VERSION (10000*0 + 100*4 + 3)

/* nnom model */
static nnom_model_t* nnom_model_create(void)
{
	static nnom_model_t model;
	nnom_layer_t* layer[5];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&input_2_config);
	layer[1] = model.hook(rnn_s(lstm_cell_s(&lstm_lstm_cell_config), &lstm_config), layer[0]);
	layer[2] = model.hook(rnn_s(lstm_cell_s(&lstm_1_lstm_cell_config), &lstm_1_config), layer[1]);
	layer[3] = model.hook(dense_s(&dense_config), layer[2]);
	layer[4] = model.hook(output_s(&output0_config), layer[3]);
	model_compile(&model, layer[0], layer[4]);
	return &model;
}
