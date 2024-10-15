#ifndef	_IMU_H_
#define	_IMU_H_

#include "stm32f10x.h"

/* IMU������ */
#define IMU_DateLength_MAX				150				// IMU�������ݳ���
#define IMU_DataPackageHead				"IMU\n"		// IMU���ݸ�ʽͷ

/**
  * @brief IMU�ɼ��������������
  * @param Index ��ǰ���ݲɼ����±�
  * @return ��
  */
void IMU_GetData(uint8_t Index);

/**
  * @brief ��IMU�������������
  * @return ��
  */
void IMU_PrintData(void);

#endif	//_IMU_H_
