#ifndef __CYBER_MAGIC_WAND_H
#define __CYBER_MAGIC_WAND_H

#include "stm32f10x.h"

#include "Delay.h"
#include "KeyStateMachine.h"

typedef enum eSystem_Mode{
	SYSTEM_IDLE = 0,
	SYSTEM_RECORD = 1,
	SYSTEM_TRANSMIT = 2
}eSystem_Mode;

typedef enum eIMU_STATUS{
	IMU_Idle = 0,
	IMU_Sampling = 1,
	IMU_Sampled = 2,
	IMU_Sample = 3
}eIMU_STATUS;

typedef enum eLED_LED{
	LED_IDLE = 0,
	LED_5HZ = 1,
	LED_10HZ = 2,
	LED_ALWAYS_ON = 3
}eLED_STATUS;

typedef enum eSerial_Status{
	Serial_Idle = 0,
	Serial_Receiving = 1,
	Serial_Received = 2
}eSerial_Status;

typedef struct Cyberry_Potter_Status_Typedef{
	eSystem_Mode System_Mode;
	KEY_EventList_TypeDef Button_Status;
	eIMU_STATUS IMU_Status;
	eLED_STATUS LED_Status;
	eSerial_Status Serial_Status;
}Cyberry_Potter_Status_Typedef;

void Cyberry_Potter_System_Status_Update(void);
void LED_Blink(void);

#endif
