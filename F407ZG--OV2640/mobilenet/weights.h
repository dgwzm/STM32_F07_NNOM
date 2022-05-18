#ifndef WEIGHTS_H
#define WEIGHTS_H

#include "types.h"

// Conv0
#define CONV0_IN_CHANNEL		1
#define CONV0_IN_SIZE			28
#define CONV0_IN_SHAPE			784
#define CONV0_KERNEL_SIZE		3
#define CONV0_KERNEL_SHAPE		9
#define CONV0_WEIGHT_SIZE		144
#define CONV0_STRIDE			1
#define CONV0_OUT_CHANNEL		16
#define CONV0_BIAS_SIZE			CONV0_OUT_CHANNEL
#define CONV0_OUT_SIZE			26
#define CONV0_OUT_SHAPE			676
#define CONV0_OUT_NUM			10816
// 每个输出通道所需的权重数: 输入通道 * 卷积核大小
#define CONV0_KERNEL_OUT		9
#define CONV0_S_x				0.007874015718698502
#define CONV0_Z_x				0
#define CONV0_S_w				0.022858550772070885
#define CONV0_S_a				0.08705828338861465
#define CONV0_Z_a				62
#define RELU0_SIZE		        CONV0_OUT_NUM
#define RELU0_Z_a		        CONV0_Z_a

// Inv1
#define INV1_PW_IN_CHANNEL		CONV0_OUT_CHANNEL
#define INV1_PW_IN_SIZE			CONV0_OUT_SIZE
#define INV1_PW_IN_SHAPE		CONV0_OUT_SHAPE
#define INV1_PW_KERNEL_SIZE		1
#define INV1_PW_KERNEL_SHAPE	1
#define INV1_PW_WEIGHT_SIZE		512
#define INV1_PW_STRIDE			1
#define INV1_PW_OUT_CHANNEL		32
#define INV1_PW_BIAS_SIZE		INV1_PW_OUT_CHANNEL
#define INV1_PW_OUT_SIZE		INV1_PW_IN_SIZE
#define INV1_PW_OUT_SHAPE		INV1_PW_IN_SHAPE
#define INV1_PW_OUT_NUM			21632
// 每个输出通道所需的权重数: 输入通道 * 卷积核大小
#define INV1_PW_KERNEL_OUT		INV1_PW_IN_CHANNEL
#define INV1_PW_S_x				CONV0_S_a
#define INV1_PW_Z_x				CONV0_Z_a
#define INV1_PW_S_w				0.0064495219849050045
#define INV1_PW_S_a				0.04764477163553238
#define INV1_PW_Z_a				73

#define INV1_RELU0_SIZE		    INV1_PW_OUT_NUM
#define INV1_RELU0_Z_a		    INV1_PW_Z_a

#define INV1_DW_IN_CHANNEL		INV1_PW_OUT_CHANNEL
#define INV1_DW_IN_SIZE			INV1_PW_OUT_SIZE
#define INV1_DW_IN_SHAPE		INV1_PW_OUT_SHAPE
#define INV1_DW_KERNEL_SIZE		3
#define INV1_DW_KERNEL_SHAPE	9
#define INV1_DW_WEIGHT_SIZE		288
#define INV1_DW_STRIDE			2
#define INV1_DW_GROUPS			INV1_DW_IN_CHANNEL
#define INV1_DW_OUT_CHANNEL		INV1_DW_IN_CHANNEL
#define INV1_DW_BIAS_SIZE		INV1_DW_IN_CHANNEL
#define INV1_DW_OUT_SIZE		12
#define INV1_DW_OUT_SHAPE		144
#define INV1_DW_OUT_NUM			4608
#define INV1_DW_S_x				INV1_PW_S_a
#define INV1_DW_Z_x				INV1_PW_Z_a
#define INV1_DW_S_w				0.080603688955307
#define INV1_DW_S_a				0.11038363724946976
#define INV1_DW_Z_a				72

#define INV1_RELU1_SIZE		    INV1_DW_OUT_NUM
#define INV1_RELU1_Z_a		    INV1_DW_Z_a

#define INV1_LINEAR_IN_CHANNEL		INV1_DW_OUT_CHANNEL
#define INV1_LINEAR_IN_SIZE			INV1_DW_OUT_SIZE
#define INV1_LINEAR_IN_SHAPE		INV1_DW_OUT_SHAPE
#define INV1_LINEAR_KERNEL_SIZE		1
#define INV1_LINEAR_KERNEL_SHAPE	1
#define INV1_LINEAR_WEIGHT_SIZE		512
#define INV1_LINEAR_STRIDE			1
#define INV1_LINEAR_OUT_CHANNEL		16
#define INV1_LINEAR_BIAS_SIZE		INV1_LINEAR_OUT_CHANNEL
#define INV1_LINEAR_OUT_SIZE		INV1_LINEAR_IN_SIZE
#define INV1_LINEAR_OUT_SHAPE		INV1_LINEAR_IN_SHAPE
#define INV1_LINEAR_OUT_NUM			2304
// 每个输出通道所需的权重数: 输入通道 * 卷积核大小
#define INV1_LINEAR_KERNEL_OUT		INV1_LINEAR_IN_CHANNEL
#define INV1_LINEAR_S_x				INV1_DW_S_a
#define INV1_LINEAR_Z_x				INV1_DW_Z_a
#define INV1_LINEAR_S_w				0.006519565358757973
#define INV1_LINEAR_S_a				0.08859208226203918
#define INV1_LINEAR_Z_a				70

// Inv2
#define INV2_PW_IN_CHANNEL		INV1_LINEAR_OUT_CHANNEL
#define INV2_PW_IN_SIZE			INV1_LINEAR_OUT_SIZE
#define INV2_PW_IN_SHAPE		INV1_LINEAR_OUT_SHAPE
#define INV2_PW_KERNEL_SIZE		1
#define INV2_PW_KERNEL_SHAPE	1
#define INV2_PW_WEIGHT_SIZE		768
#define INV2_PW_STRIDE			1
#define INV2_PW_OUT_CHANNEL		48
#define INV2_PW_BIAS_SIZE		INV2_PW_OUT_CHANNEL
#define INV2_PW_OUT_SIZE		INV2_PW_IN_SIZE
#define INV2_PW_OUT_SHAPE		INV2_PW_IN_SHAPE
#define INV2_PW_OUT_NUM			6912
// 每个输出通道所需的权重数: 输入通道 * 卷积核大小
#define INV2_PW_KERNEL_OUT		INV2_PW_IN_CHANNEL
#define INV2_PW_S_x				INV1_LINEAR_S_a
#define INV2_PW_Z_x				INV1_LINEAR_Z_a
#define INV2_PW_S_w				0.003535709111019969
#define INV2_PW_S_a				0.04394755885004997
#define INV2_PW_Z_a				60

#define INV2_RELU0_SIZE		    INV2_PW_OUT_NUM
#define INV2_RELU0_Z_a		    INV2_PW_Z_a

#define INV2_DW_IN_CHANNEL		INV2_PW_OUT_CHANNEL
#define INV2_DW_IN_SIZE			INV2_PW_OUT_SIZE
#define INV2_DW_IN_SHAPE		INV2_PW_OUT_SHAPE
#define INV2_DW_KERNEL_SIZE		3
#define INV2_DW_KERNEL_SHAPE	9
#define INV2_DW_WEIGHT_SIZE		432
#define INV2_DW_STRIDE			2
#define INV2_DW_GROUPS			INV2_DW_IN_CHANNEL
#define INV2_DW_OUT_CHANNEL		INV2_DW_IN_CHANNEL
#define INV2_DW_BIAS_SIZE		INV2_DW_IN_CHANNEL
#define INV2_DW_OUT_SIZE		5
#define INV2_DW_OUT_SHAPE		25
#define INV2_DW_OUT_NUM			1200
#define INV2_DW_S_x				INV2_PW_S_a
#define INV2_DW_Z_x				INV2_PW_Z_a
#define INV2_DW_S_w				0.05265704542398453
#define INV2_DW_S_a				0.10123392194509506
#define INV2_DW_Z_a				74

#define INV2_RELU1_SIZE		    INV2_DW_OUT_NUM
#define INV2_RELU1_Z_a		    INV2_DW_Z_a

#define INV2_LINEAR_IN_CHANNEL		INV2_DW_OUT_CHANNEL
#define INV2_LINEAR_IN_SIZE			INV2_DW_OUT_SIZE
#define INV2_LINEAR_IN_SHAPE		INV2_DW_OUT_SHAPE
#define INV2_LINEAR_KERNEL_SIZE		1
#define INV2_LINEAR_KERNEL_SHAPE	1
#define INV2_LINEAR_WEIGHT_SIZE		1536
#define INV2_LINEAR_STRIDE			1
#define INV2_LINEAR_OUT_CHANNEL		32
#define INV2_LINEAR_BIAS_SIZE		INV2_LINEAR_OUT_CHANNEL
#define INV2_LINEAR_OUT_SIZE		INV2_LINEAR_IN_SIZE
#define INV2_LINEAR_OUT_SHAPE		INV2_LINEAR_IN_SHAPE
#define INV2_LINEAR_OUT_NUM			800
// 每个输出通道所需的权重数: 输入通道 * 卷积核大小
#define INV2_LINEAR_KERNEL_OUT		INV2_LINEAR_IN_CHANNEL
#define INV2_LINEAR_S_x				INV2_DW_S_a
#define INV2_LINEAR_Z_x				INV2_DW_Z_a
#define INV2_LINEAR_S_w				0.0069420780055224895
#define INV2_LINEAR_S_a				0.08300823718309402
#define INV2_LINEAR_Z_a				68

// Inv3
#define INV3_PW_IN_CHANNEL		INV2_LINEAR_OUT_CHANNEL
#define INV3_PW_IN_SIZE			INV2_LINEAR_OUT_SIZE
#define INV3_PW_IN_SHAPE		INV2_LINEAR_OUT_SHAPE
#define INV3_PW_KERNEL_SIZE		1
#define INV3_PW_KERNEL_SHAPE	1
#define INV3_PW_WEIGHT_SIZE		3072
#define INV3_PW_STRIDE			1
#define INV3_PW_OUT_CHANNEL		96
#define INV3_PW_BIAS_SIZE		INV3_PW_OUT_CHANNEL
#define INV3_PW_OUT_SIZE		INV3_PW_IN_SIZE
#define INV3_PW_OUT_SHAPE		INV3_PW_IN_SHAPE
#define INV3_PW_OUT_NUM			2400
// 每个输出通道所需的权重数: 输入通道 * 卷积核大小
#define INV3_PW_KERNEL_OUT		INV3_PW_IN_CHANNEL
#define INV3_PW_S_x				INV2_LINEAR_S_a
#define INV3_PW_Z_x				INV2_LINEAR_Z_a
#define INV3_PW_S_w				0.002156325615942478
#define INV3_PW_S_a				0.03587406128644943
#define INV3_PW_Z_a				59

#define INV3_RELU0_SIZE		    INV3_PW_OUT_NUM
#define INV3_RELU0_Z_a		    INV3_PW_Z_a

#define INV3_DW_IN_CHANNEL		INV3_PW_OUT_CHANNEL
#define INV3_DW_IN_SIZE			INV3_PW_OUT_SIZE
#define INV3_DW_IN_SHAPE		INV3_PW_OUT_SHAPE
#define INV3_DW_KERNEL_SIZE		3
#define INV3_DW_KERNEL_SHAPE	9
#define INV3_DW_WEIGHT_SIZE		864
#define INV3_DW_STRIDE			1
#define INV3_DW_GROUPS			INV3_DW_IN_CHANNEL
#define INV3_DW_OUT_CHANNEL		INV3_DW_IN_CHANNEL
#define INV3_DW_BIAS_SIZE		INV3_DW_IN_CHANNEL
#define INV3_DW_OUT_SIZE		3
#define INV3_DW_OUT_SHAPE		9
#define INV3_DW_OUT_NUM			864
#define INV3_DW_S_x				INV3_PW_S_a
#define INV3_DW_Z_x				INV3_PW_Z_a
#define INV3_DW_S_w				0.06939755380153656
#define INV3_DW_S_a				0.08724448084831238
#define INV3_DW_Z_a				70

#define INV3_RELU1_SIZE		    INV3_DW_OUT_NUM
#define INV3_RELU1_Z_a		    INV3_DW_Z_a

#define INV3_LINEAR_IN_CHANNEL		INV3_DW_OUT_CHANNEL
#define INV3_LINEAR_IN_SIZE			INV3_DW_OUT_SIZE
#define INV3_LINEAR_IN_SHAPE		INV3_DW_OUT_SHAPE
#define INV3_LINEAR_KERNEL_SIZE		1
#define INV3_LINEAR_KERNEL_SHAPE	1
#define INV3_LINEAR_WEIGHT_SIZE		3072
#define INV3_LINEAR_STRIDE			1
#define INV3_LINEAR_OUT_CHANNEL		32
#define INV3_LINEAR_BIAS_SIZE		INV3_LINEAR_OUT_CHANNEL
#define INV3_LINEAR_OUT_SIZE		INV3_LINEAR_IN_SIZE
#define INV3_LINEAR_OUT_SHAPE		INV3_LINEAR_IN_SHAPE
#define INV3_LINEAR_OUT_NUM			288
// 每个输出通道所需的权重数: 输入通道 * 卷积核大小
#define INV3_LINEAR_KERNEL_OUT		INV3_LINEAR_IN_CHANNEL
#define INV3_LINEAR_S_x				INV3_DW_S_a
#define INV3_LINEAR_Z_x				INV3_DW_Z_a
#define INV3_LINEAR_S_w				0.007411690428853035
#define INV3_LINEAR_S_a				0.08565284311771393
#define INV3_LINEAR_Z_a				67

// Conv4
#define CONV4_IN_CHANNEL		32
#define CONV4_IN_SIZE			3
#define CONV4_IN_SHAPE			9
#define CONV4_KERNEL_SIZE		1
#define CONV4_KERNEL_SHAPE		1
#define CONV4_WEIGHT_SIZE		4096
#define CONV4_STRIDE			1
#define CONV4_OUT_CHANNEL		128
#define CONV4_BIAS_SIZE			CONV4_OUT_CHANNEL
#define CONV4_OUT_SIZE			3
#define CONV4_OUT_SHAPE			9
#define CONV4_OUT_NUM			1152
// 每个输出通道所需的权重数: 输入通道 * 卷积核大小
#define CONV4_KERNEL_OUT		32
#define CONV4_S_x				INV3_LINEAR_S_a
#define CONV4_Z_x				INV3_LINEAR_Z_a
#define CONV4_S_w				0.010665806010365486
#define CONV4_S_a				0.1690828800201416
#define CONV4_Z_a				48
#define RELU4_SIZE		        CONV4_OUT_NUM
#define RELU4_Z_a		        CONV4_Z_a

// Avg
#define AVG_IN_CHANNEL          CONV4_OUT_CHANNEL
#define AVG_IN_SIZE             CONV4_OUT_SIZE
#define AVG_IN_SHAPE            CONV4_OUT_SHAPE

// Fc
#define FC_IN_FEATURE           AVG_IN_CHANNEL          
#define FC_OUT_FEATURE          55          
#define FC_WEIGHT_NUM           7040
#define FC_BIAS_NUM             FC_OUT_FEATURE
#define FC_S_x                  CONV4_S_a
#define FC_Z_x                  CONV4_Z_a
#define FC_S_w                  0.005709699355065823
#define FC_S_a                  0.5211344361305237
#define FC_Z_a                  99

#endif