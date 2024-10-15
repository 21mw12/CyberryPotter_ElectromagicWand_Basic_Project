#ifndef __MODEL_H
#define __MODEL_H

#include "stm32f10x.h"

typedef enum eModel_Output{
	Unrecognized = -1,
	RightAngle = 0,
	SharpAngle = 1,
	Lightning = 2,
	Triangle = 3,
	Letter_h = 4,
	letter_R = 5,
	letter_W = 6,
	letter_phi = 7,
	Circle = 8,
	UpAndDown = 9,
	Horn = 10,
	Wave = 11,
	NoMotion = 12
}eModel_Output;

/**
  * @brief 加载模型
  * @return 无
  */
void Model_Load(void);

/**
  * @brief 向模型输入参数
  * @return 无
  */
void Model_InputData(void);

/**
  * @brief 模型向前传播
  * @return 无
  */
void Model_Run(void);

/**
  * @brief 获取模型结果
  * @return 模型结果
  */
int8_t Model_GetOutput(void);

#endif