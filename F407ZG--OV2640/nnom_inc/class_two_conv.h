#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_CONV2D_KERNEL_0 {-47, 19, -41, -17, -55, 6, -59, -9, 19, -71, -54, 43, 33, -1, -36, -65, -44, 60, -46, -28, 3, 73, 60, 61, -3, -20, -43, 32, 67, 30, 56, -53, 54, -34, -46, 21, -27, -44, 8, 12, 52, 9, -24, 12, 49, -10, -6, -68}

#define TENSOR_CONV2D_KERNEL_0_DEC_BITS {8}

#define TENSOR_CONV2D_BIAS_0 {0, 0}

#define TENSOR_CONV2D_BIAS_0_DEC_BITS {8}

#define CONV2D_BIAS_LSHIFT {7}

#define CONV2D_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_1_KERNEL_0 {36, 25, 44, -4, -18, -26, 67, 55, -40, 68, 2, 69, -14, 67, 64, -40, 15, -3, -48, -46, -24, -36, -34, -2, 30, 30, 63, -32, -52, -38, 38, 32, -59, 28, 52, 33, 1, -72, 33, -46, 4, -55, 36, 42, -21, 21, 42, 3, -34, 4, -68, -5, -11, -65, 8, 65, -20, -11, -4, -19, -46, -1, 54, 42, 15, -59, -30, 7, 54, 15, -9, -9, 28, -14, 5, 1, 64, 3, 38, 27, 2, -49, 69, 34, 40, -66, -40, 56, 34, 55, 15, 39, 4, 29, 44, -36}

#define TENSOR_CONV2D_1_KERNEL_0_DEC_BITS {8}

#define TENSOR_CONV2D_1_BIAS_0 {0, 0, 0, 0}

#define TENSOR_CONV2D_1_BIAS_0_DEC_BITS {8}

#define CONV2D_1_BIAS_LSHIFT {6}

#define CONV2D_1_OUTPUT_RSHIFT {6}


/* output q format for each layer */
#define INPUT_2_OUTPUT_DEC 7
#define INPUT_2_OUTPUT_OFFSET 0
#define CONV2D_OUTPUT_DEC 6
#define CONV2D_OUTPUT_OFFSET 0
#define LEAKY_RE_LU_OUTPUT_DEC 6
#define LEAKY_RE_LU_OUTPUT_OFFSET 0
#define CONV2D_1_OUTPUT_DEC 8
#define CONV2D_1_OUTPUT_OFFSET 0
#define LEAKY_RE_LU_1_OUTPUT_DEC 8
#define LEAKY_RE_LU_1_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[800] = {0};

const nnom_shape_data_t tensor_input_2_dim[] = {1, 800, 1};
const nnom_qformat_param_t tensor_input_2_dec[] = {7};
const nnom_qformat_param_t tensor_input_2_offset[] = {0};
const nnom_tensor_t tensor_input_2 = {
    .p_data = (void*)nnom_input_data,
    .dim = (nnom_shape_data_t*)tensor_input_2_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_input_2_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_input_2_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};

const nnom_io_config_t input_2_config = {
    .super = {.name = "input_2"},
    .tensor = (nnom_tensor_t*)&tensor_input_2
};
const int8_t tensor_conv2d_kernel_0_data[] = TENSOR_CONV2D_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_kernel_0_dim[] = {1, 24, 1, 2};
const nnom_qformat_param_t tensor_conv2d_kernel_0_dec[] = TENSOR_CONV2D_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_kernel_0 = {
    .p_data = (void*)tensor_conv2d_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_bias_0_data[] = TENSOR_CONV2D_BIAS_0;

const nnom_shape_data_t tensor_conv2d_bias_0_dim[] = {2};
const nnom_qformat_param_t tensor_conv2d_bias_0_dec[] = TENSOR_CONV2D_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_bias_0 = {
    .p_data = (void*)tensor_conv2d_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_output_shift[] = CONV2D_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_bias_shift[] = CONV2D_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_config = {
    .super = {.name = "conv2d"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_bias_shift, 
    .filter_size = 2,
    .kernel_size = {1, 24},
    .stride_size = {1, 5},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_1_kernel_0_data[] = TENSOR_CONV2D_1_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_1_kernel_0_dim[] = {1, 12, 2, 4};
const nnom_qformat_param_t tensor_conv2d_1_kernel_0_dec[] = TENSOR_CONV2D_1_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_1_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_1_kernel_0 = {
    .p_data = (void*)tensor_conv2d_1_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_1_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_1_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_1_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_1_bias_0_data[] = TENSOR_CONV2D_1_BIAS_0;

const nnom_shape_data_t tensor_conv2d_1_bias_0_dim[] = {4};
const nnom_qformat_param_t tensor_conv2d_1_bias_0_dec[] = TENSOR_CONV2D_1_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_1_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_1_bias_0 = {
    .p_data = (void*)tensor_conv2d_1_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_1_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_1_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_1_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_1_output_shift[] = CONV2D_1_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_1_bias_shift[] = CONV2D_1_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_1_config = {
    .super = {.name = "conv2d_1"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_1_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_1_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_1_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_1_bias_shift, 
    .filter_size = 4,
    .kernel_size = {1, 12},
    .stride_size = {1, 3},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
static int8_t nnom_output_data[196] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {1, 49, 4};
const nnom_qformat_param_t tensor_output0_dec[] = {LEAKY_RE_LU_1_OUTPUT_DEC};
const nnom_qformat_param_t tensor_output0_offset[] = {0};
const nnom_tensor_t tensor_output0 = {
    .p_data = (void*)nnom_output_data,
    .dim = (nnom_shape_data_t*)tensor_output0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_output0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_output0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
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
	nnom_layer_t* layer[6];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);

	layer[0] = input_s(&input_2_config);
	layer[1] = model.hook(conv2d_s(&conv2d_config), layer[0]);
	layer[2] = model.active(act_leaky_relu(0.300000f), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv2d_1_config), layer[2]);
	layer[4] = model.active(act_leaky_relu(0.300000f), layer[3]);
	layer[5] = model.hook(output_s(&output0_config), layer[4]);
	model_compile(&model, layer[0], layer[5]);
	return &model;
}
