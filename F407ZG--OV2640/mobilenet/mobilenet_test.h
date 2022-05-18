#ifndef __MOBILENET_TEST_H__
#define __MOBILENET_TEST_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
//#include <cmath.h>
#include <stdio.h>
#include "q_conv_layer.h"
#include "q_activation_layer.h"
#include "q_inv_residual_layer.h"
#include "q_pool_layer.h"
#include "q_linear_layer.h"
#include "weights.h"

static int verify_output(float *data1, float *data2, int channel, int size);
int Mobilenet(void);

#endif
