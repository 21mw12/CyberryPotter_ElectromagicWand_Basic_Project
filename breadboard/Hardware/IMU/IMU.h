#ifndef	_IMU_H_
#define	_IMU_H_

#include "stm32f10x.h"

/* IMU配置项 */
#define IMU_DateLength_MAX				150				// IMU最大多数据长度
#define IMU_DataPackageHead				"IMU\n"		// IMU数据格式头

/**
  * @brief IMU采集数据输出到串口
  * @param Index 当前数据采集的下标
  * @return 无
  */
void IMU_GetData(uint8_t Index);

/**
  * @brief 将IMU数据输出到串口
  * @return 无
  */
void IMU_PrintData(void);

#endif	//_IMU_H_
