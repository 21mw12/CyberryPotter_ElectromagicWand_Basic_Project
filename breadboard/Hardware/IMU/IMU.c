#include "IMU.h"
#include <stdio.h>
#include "MPU6050.h"
#include "MPU6050_Register.h"


//#define IMU_OFFSET_TEST
#define IMU_ACC_TRANS_CONSTANT (8192.0)  //+-4g
//+-500 degrees raw value to degree constant is divided by 16.384
//+-500 to radian is divided by (73.537*180/PI) = 4213.359738
//#define IMU_GYRO_TRANS_RADIAN_CONSTANT (4213.359738) 
#define IMU_GYRO_TRANS_RADIAN_CONSTANT (8192.0)


typedef enum IMU_ACC_Index{
	AccX = 0,
	AccY = 1,
	AccZ = 2,
}IMU_ACC_Index;

typedef enum IMU_GYRO_Index{
	Roll = 0,
	Pitch = 1,
	Yaw = 2
}IMU_GYRO_Index;

//measured data beginning with m, d means derivative ,mdAngle is measured angular velovity in this case.
float IMU_Data_mAcc[IMU_DateLength_MAX][3];
float IMU_Data_mGyro[IMU_DateLength_MAX][3];
int16_t IMU_bias[6] = {0,0,0,0,0,0};

#ifndef IMU_OFFSET_TEST
void IMU_GetData(uint8_t Index) {
	uint8_t originData[6];		// MPU6050原始数据
	int16_t IMU_Received[6];	// IMU预处理数据
	
	/*采集加速度计数据*/
	DMP_Read(MPU6050_ADDRESS, MPU6050_ACCEL_XOUTH,6,originData);
	IMU_Received[AccX] = (originData[0] << 8) + originData[1] - IMU_bias[AccX];
	IMU_Received[AccY] = (originData[2] << 8) + originData[3] - IMU_bias[AccY];
	IMU_Received[AccZ] = (originData[4] << 8) + originData[5] - IMU_bias[AccZ];

	IMU_Data_mAcc[Index][AccX] = IMU_Received[AccX] / IMU_ACC_TRANS_CONSTANT;
	IMU_Data_mAcc[Index][AccY] = IMU_Received[AccY] / IMU_ACC_TRANS_CONSTANT;
	IMU_Data_mAcc[Index][AccZ] = IMU_Received[AccZ] / IMU_ACC_TRANS_CONSTANT;

	/*采集角速度计数据*/
	DMP_Read(MPU6050_ADDRESS, MPU6050_GYRO_XOUTH,6,originData);
	IMU_Received[Roll] = (originData[0] << 8) + originData[1] - IMU_bias[Roll];
	IMU_Received[Pitch] = (originData[2] << 8) + originData[3]- IMU_bias[Pitch];
	IMU_Received[Yaw] = (originData[4] << 8) + originData[5]  - IMU_bias[Yaw];
	
	IMU_Data_mGyro[Index][Roll] = IMU_Received[Roll] / IMU_GYRO_TRANS_RADIAN_CONSTANT;
	IMU_Data_mGyro[Index][Pitch] = IMU_Received[Pitch] / IMU_GYRO_TRANS_RADIAN_CONSTANT;
	IMU_Data_mGyro[Index][Yaw] = IMU_Received[Yaw] / IMU_GYRO_TRANS_RADIAN_CONSTANT;
}
#else
void IMU_GetData(uint8_t Index) {
	uint8_t temp[6];
	int16_t IMU_Received[3];
	DMP_Read(MPU6050_ADDRESS,MPU6050_ACCEL_XOUTH,6,temp);
	IMU_Received[AccX] = (temp[0] << 8) + temp[1] - IMU_bias[AccX];
	IMU_Received[AccY] = (temp[2] << 8) + temp[3] - IMU_bias[AccY];
	IMU_Received[AccZ] = (temp[4] << 8) + temp[5] - IMU_bias[AccZ];
	
	printf("AccX:%d AccY:%d AccZ:%d\n",
		IMU_Received[AccX],IMU_Received[AccY],IMU_Received[AccZ]);
}
#endif

void IMU_PrintData(void) {
	printf(IMU_DataPackageHead);
	
	for(uint16_t i = 0; i < IMU_DateLength_MAX; i++){
		printf("%f %f %f %f %f %f\n",
					IMU_Data_mAcc[i][AccX], IMU_Data_mAcc[i][AccY], IMU_Data_mAcc[i][AccZ],
					IMU_Data_mGyro[i][Roll], IMU_Data_mGyro[i][Pitch], IMU_Data_mGyro[i][Yaw]);
	}
}
