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
  * @brief ����ģ��
  * @return ��
  */
void Model_Load(void);

/**
  * @brief ��ģ���������
  * @return ��
  */
void Model_InputData(void);

/**
  * @brief ģ����ǰ����
  * @return ��
  */
void Model_Run(void);

/**
  * @brief ��ȡģ�ͽ��
  * @return ģ�ͽ��
  */
int8_t Model_GetOutput(void);

#endif