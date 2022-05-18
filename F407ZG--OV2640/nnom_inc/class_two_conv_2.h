#include "nnom.h"

/* Weights, bias and Q format */
#define TENSOR_CONV2D_2_KERNEL_0 {83, 20, 58, 36, -8, -40, -32, 31, -77, 72, 36, 45, 60, 46, -39, -69, -35, 2, -4, 25, -77, 38, 1, -7, 58, 25, -15, 20, 22, 1, -20, 48, 34, -59, 68, 11, 43, -74, 6, 84, -42, 44, -3, -37, 6, -50, 67, -33, 52, 41, 55, -69, -70, 84, 64, -13, 11, 51, 28, 78, 29, -10, 70, 59, -79, -3, 32, -71, -24, 80, -35, 19, -56, 63, 32, -83, 83, -42, 78, 35, -71, 29, 55, -79, -4, -28, 59, 23, -80, -48, -16, -76, 36, -39, -79, 56, -45, -52, 9, 32, 53, 40, -72, 17, -54, 53, -23, -45, -25, -62, 29, 5, -17, 74, 64, 67, 46, 72, 81, -81}

#define TENSOR_CONV2D_2_KERNEL_0_DEC_BITS {8}

#define TENSOR_CONV2D_2_BIAS_0 {0, 0, 0, 0, 0, 0}

#define TENSOR_CONV2D_2_BIAS_0_DEC_BITS {8}

#define CONV2D_2_BIAS_LSHIFT {7}

#define CONV2D_2_OUTPUT_RSHIFT {9}

#define TENSOR_CONV2D_3_KERNEL_0 {-36, -66, -37, -65, 46, 6, 64, -43, -43, 59, 46, -30, -71, 16, -50, -63, 7, -55, 34, 8, -43, -33, 4, -72, -65, -30, -38, -39, 71, 73, -44, 17, -28, 2, 74, -28, -62, -29, 50, 49, 28, -66, 71, 62, 44, -70, -8, -66, 18, -56, 29, -70, -13, -59, 68, 57, 28, -52, -64, 15, 18, 72, 39, -49, 46, -65, 44, -44, -45, -2, 23, 56, 30, 27, 54, 19, 69, 64, -29, -2, 38, -34, -10, -15, -31, -62, 20, -64, 8, 9, 47, -42, 50, -6, -19, 38, -25, -21, 1, -53, 6, 66, -32, 15, -23, 53, -71, 63, 24, -24, 32, 67, -13, 57, -20, 36, 69, -42, 49, 13, -55, 57, -62, 74, 71, -1, -9, -51, 42, 8, 6, 74, 33, -16, -25, -11, -74, 42, 39, 13, -19, -42, 74, -7, 71, 62, -19, 16, -24, -16, 10, 3, 27, -50, 60, -56, 33, -10, -2, 71, 50, 68, 36, -22, -74, -31, -18, -44, -33, -25, -55, 31, -63, -6, -65, -30, 22, 32, -70, -61, 1, 30, -1, -24, -73, -71, 38, 29, 38, -37, -21, 57, -3, 34, 53, -36, 8, 44, -56, 22, 69, 38, -70, -37, 45, -4, -58, -45, 43, 67, 65, -10, 44, -69, 5, -10, -25, 20, -48, -46, 48, 11, 24, -24, -65, 55, -44, -15, 37, -27, -1, 22, 11, 17, 0, 17, -6, -10, -68, -31}

#define TENSOR_CONV2D_3_KERNEL_0_DEC_BITS {8}

#define TENSOR_CONV2D_3_BIAS_0 {0, 0, 0, 0, 0, 0, 0, 0}

#define TENSOR_CONV2D_3_BIAS_0_DEC_BITS {8}

#define CONV2D_3_BIAS_LSHIFT {6}

#define CONV2D_3_OUTPUT_RSHIFT {8}


/* output q format for each layer */
#define INPUT_3_OUTPUT_DEC 7
#define INPUT_3_OUTPUT_OFFSET 0
#define CONV2D_2_OUTPUT_DEC 6
#define CONV2D_2_OUTPUT_OFFSET 0
#define LEAKY_RE_LU_2_OUTPUT_DEC 6
#define LEAKY_RE_LU_2_OUTPUT_OFFSET 0
#define CONV2D_3_OUTPUT_DEC 6
#define CONV2D_3_OUTPUT_OFFSET 0
#define LEAKY_RE_LU_3_OUTPUT_DEC 6
#define LEAKY_RE_LU_3_OUTPUT_OFFSET 0

/* bias shift and output shift for none-weighted layer */

/* tensors and configurations for each layer */
static int8_t nnom_input_data_2[248] = {0};

nnom_shape_data_t tensor_input_3_dim[3];// = {1, 62, 4};
//nnom_shape_data_t *tensor_input_3_dim=(nnom_shape_data_t *) malloc(3 * sizeof(nnom_shape_data_t));

const nnom_qformat_param_t tensor_input_3_dec[] = {7};
const nnom_qformat_param_t tensor_input_3_offset[] = {0};
const nnom_tensor_t tensor_input_3 = {
    .p_data = (void*)nnom_input_data_2,
    //.dim = (nnom_shape_data_t*)tensor_input_3_dim,
		.dim = (nnom_shape_data_t*)tensor_input_3_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_input_3_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_input_3_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};

const nnom_io_config_t input_3_config = {
    .super = {.name = "input_3"},
    .tensor = (nnom_tensor_t*)&tensor_input_3
};
const int8_t tensor_conv2d_2_kernel_0_data[] = TENSOR_CONV2D_2_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_2_kernel_0_dim[] = {1, 5, 4, 6};
const nnom_qformat_param_t tensor_conv2d_2_kernel_0_dec[] = TENSOR_CONV2D_2_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_2_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_2_kernel_0 = {
    .p_data = (void*)tensor_conv2d_2_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_2_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_2_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_2_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_2_bias_0_data[] = TENSOR_CONV2D_2_BIAS_0;

const nnom_shape_data_t tensor_conv2d_2_bias_0_dim[] = {6};
const nnom_qformat_param_t tensor_conv2d_2_bias_0_dec[] = TENSOR_CONV2D_2_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_2_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_2_bias_0 = {
    .p_data = (void*)tensor_conv2d_2_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_2_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_2_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_2_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_2_output_shift[] = CONV2D_2_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_2_bias_shift[] = CONV2D_2_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_2_config = {
    .super = {.name = "conv2d_2"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_2_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_2_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_2_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_2_bias_shift, 
    .filter_size = 6,
    .kernel_size = {1, 5},
    .stride_size = {1, 2},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
const int8_t tensor_conv2d_3_kernel_0_data[] = TENSOR_CONV2D_3_KERNEL_0;

const nnom_shape_data_t tensor_conv2d_3_kernel_0_dim[] = {1, 5, 6, 8};
const nnom_qformat_param_t tensor_conv2d_3_kernel_0_dec[] = TENSOR_CONV2D_3_KERNEL_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_3_kernel_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_3_kernel_0 = {
    .p_data = (void*)tensor_conv2d_3_kernel_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_3_kernel_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_3_kernel_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_3_kernel_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 4,
    .bitwidth = 8
};
const int8_t tensor_conv2d_3_bias_0_data[] = TENSOR_CONV2D_3_BIAS_0;

const nnom_shape_data_t tensor_conv2d_3_bias_0_dim[] = {8};
const nnom_qformat_param_t tensor_conv2d_3_bias_0_dec[] = TENSOR_CONV2D_3_BIAS_0_DEC_BITS;
const nnom_qformat_param_t tensor_conv2d_3_bias_0_offset[] = {0};
const nnom_tensor_t tensor_conv2d_3_bias_0 = {
    .p_data = (void*)tensor_conv2d_3_bias_0_data,
    .dim = (nnom_shape_data_t*)tensor_conv2d_3_bias_0_dim,
    .q_dec = (nnom_qformat_param_t*)tensor_conv2d_3_bias_0_dec,
    .q_offset = (nnom_qformat_param_t*)tensor_conv2d_3_bias_0_offset,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 1,
    .bitwidth = 8
};

const nnom_qformat_param_t conv2d_3_output_shift[] = CONV2D_3_OUTPUT_RSHIFT;
const nnom_qformat_param_t conv2d_3_bias_shift[] = CONV2D_3_BIAS_LSHIFT;
const nnom_conv2d_config_t conv2d_3_config = {
    .super = {.name = "conv2d_3"},
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .weight = (nnom_tensor_t*)&tensor_conv2d_3_kernel_0,
    .bias = (nnom_tensor_t*)&tensor_conv2d_3_bias_0,
    .output_shift = (nnom_qformat_param_t *)&conv2d_3_output_shift, 
    .bias_shift = (nnom_qformat_param_t *)&conv2d_3_bias_shift, 
    .filter_size = 8,
    .kernel_size = {1, 5},
    .stride_size = {1, 2},
    .padding_size = {0, 0},
    .dilation_size = {1, 1},
    .padding_type = PADDING_VALID
};
static int8_t nnom_output_data_2[104] = {0};

const nnom_shape_data_t tensor_output0_dim_2[] = {1, 13, 8};
const nnom_qformat_param_t tensor_output0_dec_2[] = {LEAKY_RE_LU_3_OUTPUT_DEC};
const nnom_qformat_param_t tensor_output0_offset_2[] = {0};
const nnom_tensor_t tensor_output0_2 = {
    .p_data = (void*)nnom_output_data_2,
    .dim = (nnom_shape_data_t*)tensor_output0_dim_2,
    .q_dec = (nnom_qformat_param_t*)tensor_output0_dec_2,
    .q_offset = (nnom_qformat_param_t*)tensor_output0_offset_2,
    .qtype = NNOM_QTYPE_PER_TENSOR,
    .num_dim = 3,
    .bitwidth = 8
};

const nnom_io_config_t output0_config_2 = {
    .super = {.name = "output0"},
    .tensor = (nnom_tensor_t*)&tensor_output0_2
};
/* model version */
#define NNOM_MODEL_VERSION (10000*0 + 100*4 + 3)

/* nnom model */
static nnom_model_t* nnom_model_create_2(void)
{
	static nnom_model_t model;
	nnom_layer_t* layer[6];

	check_model_version(NNOM_MODEL_VERSION);
	new_model(&model);
	tensor_input_3_dim[0]=1;
	tensor_input_3_dim[1]=62;
	tensor_input_3_dim[2]=4;
	layer[0] = input_s(&input_3_config);
	layer[1] = model.hook(conv2d_s(&conv2d_2_config), layer[0]);
	layer[2] = model.active(act_leaky_relu(0.300000f), layer[1]);
	layer[3] = model.hook(conv2d_s(&conv2d_3_config), layer[2]);
	layer[4] = model.active(act_leaky_relu(0.300000f), layer[3]);
	layer[5] = model.hook(output_s(&output0_config_2), layer[4]);
	model_compile(&model, layer[0], layer[5]);
	return &model;
}
