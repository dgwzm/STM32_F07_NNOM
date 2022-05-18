#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_CONV2D_KERNEL_0 {73, -36, 30, -52, 7, 9, -19, 73, 71, -46, -28, -54, 26, 52, -40, -23, 25, -50, 49, 26, -23, -7, 73, -45, 23, -29, -32, -5, -45, 63, 0, -69, 5, -43, 30, -15, 1, -46, 26, 7, 43, 7, -43, 13, 69, -57, 1, 63}

#define TENSOR_CONV2D_KERNEL_0_DEC_BITS {8}

#define TENSOR_CONV2D_BIAS_0 {0, 0}

#define TENSOR_CONV2D_BIAS_0_DEC_BITS {8}

#define CONV2D_BIAS_LSHIFT {7}

#define CONV2D_OUTPUT_RSHIFT {8}

#define TENSOR_CONV2D_1_KERNEL_0 {41, -55, 29, 20, -56, 63, 66, 66, -12, 9, 52, 34, -59, -2, 55, -48, -2, -24, 38, -51, 55, 58, -35, -28, -35, -25, 46, -16, -53, 55, 1, 73, 55, 48, -31, 44, 17, 9, -44, 9, 25, 64, -60, 3, -33, 39, 58, -15, 48, -53, -47, -18, -60, -6, 34, 28, 8, -72, -6, -60, 23, -69, -30, -13, 29, -60, -54, -22, 55, -35, 72, -42, -23, -66, 38, 18, -19, -27, 54, 3, 16, -39, 65, 69, 74, 69, 31, -64, 55, -24, -30, -23, -56, 19, 51, 18}

#define TENSOR_CONV2D_1_KERNEL_0_DEC_BITS {8}

#define TENSOR_CONV2D_1_BIAS_0 {0, 0, 0, 0}

#define TENSOR_CONV2D_1_BIAS_0_DEC_BITS {8}

#define CONV2D_1_BIAS_LSHIFT {7}

#define CONV2D_1_OUTPUT_RSHIFT {7}


/* output q format for each layer */
#define INPUT_2_OUTPUT_DEC 7
#define INPUT_2_OUTPUT_OFFSET 0
#define CONV2D_OUTPUT_DEC 7
#define CONV2D_OUTPUT_OFFSET 0
#define LEAKY_RE_LU_OUTPUT_DEC 7
#define LEAKY_RE_LU_OUTPUT_OFFSET 0
#define CONV2D_1_OUTPUT_DEC 8
#define CONV2D_1_OUTPUT_OFFSET 0
#define LEAKY_RE_LU_1_OUTPUT_DEC 8
#define LEAKY_RE_LU_1_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data[1000] = {0};

const nnom_shape_data_t tensor_input_2_dim[] = {1, 1000, 1};
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
static int8_t nnom_output_data[248] = {0};

const nnom_shape_data_t tensor_output0_dim[] = {1, 62, 4};
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
static nnom_model_t* nnom_model_create_1(void)
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
