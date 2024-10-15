#include "stm32f10x.h"
#include "Sys.h"
#include "CyberMagicWand.h"
#include "I2CSoftware.h"
#include "KeyStateMachine.h"
#include "LED.h"
#include "USART1.h"
#include "IMU.h"
#include "MPU6050.h"
#include "Model.h"
#include <stdio.h>

extern KEY_Configure_TypeDef KeyCfg;
extern Cyberry_Potter_Status_Typedef Cyberry_Potter_Status;

int8_t model_output = -1;

void Deal_Model_Output_Function(int8_t model_output) {
	switch(model_output){
		case RightAngle:
			Green_LED_ON();
			break;
		case SharpAngle:
			Green_LED_OFF();
			break;
		case Lightning:
			Red_LED_ON();
			break;
		case Triangle:
			Red_LED_OFF();
			break;
		case Wave:
			Yellow_LED_ON();
			break;
		case letter_R:
			Yellow_LED_OFF();
			break;
		case letter_W:
			White_LED_ON();
			break;
		case letter_phi:
			White_LED_OFF();
			break;
	}
}

int main(void) {
	/* ϵͳӲ����ʼ�� */
	NVIC_Configuration();
	RCC_Configuration();
	I2C_Software_Init();
	USART1_Init();
	LED_Init(); 
	Key_Init();
	MPU6050_Init();
 	MPU6050_INT_Disable();
	State_LED_ON();

	/* ����ģ�� */
	Model_Load();

  printf("Hello Welcome Cyber Magic Wand! \r\n");
  printf("is all ready, push the button to start your journey magic. \r\n");
	
	while(1) {
		if(Cyberry_Potter_Status.Button_Status == KEY_Event_SingleClick) {
			if(Cyberry_Potter_Status.IMU_Status == IMU_Idle) {
				/* ������������IMU�豸���ڿ���ʱ */
				State_LED_OFF();																	// �ر�״ָ̬ʾ��
				MPU6050_INT_Enable();															// ����MPU6050�ж���Ӧ
				Cyberry_Potter_Status.IMU_Status = IMU_Sampling;	// ����IMU�豸Ϊ������
				printf("Start Sample\n");
			}
			Cyberry_Potter_Status.Button_Status = KEY_Event_Null;
		}
		else if(Cyberry_Potter_Status.Button_Status == KEY_Event_LongPress) {
			Cyberry_Potter_System_Status_Update();
			Cyberry_Potter_Status.Button_Status = KEY_Event_Null;
		}

		if(Cyberry_Potter_Status.IMU_Status == IMU_Sampled) {
			/* ��IMU�豸�ɼ����ʱ */
			State_LED_ON();												// ��״ָ̬ʾ��
//			Delay_ms(200);
//			IMU_Data_Print();
			Model_InputData();
			Model_Run();
			model_output = Model_GetOutput();
			printf("%d", model_output);
			Deal_Model_Output_Function(model_output);
			
			Cyberry_Potter_Status.IMU_Status = IMU_Idle;
		}		
	}
}

/* �����жϲ��� */
void TIM3_IRQHandler(void) {
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) {
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		Key_GetState();  //����״̬��
		
		Cyberry_Potter_Status.Button_Status = KeyCfg.KEY_Event;
	}
}

/* MPU6050���в��� */
void EXTI9_5_IRQHandler(void) {
	if(EXTI_GetITStatus(EXTI_Line5)==SET){
		static uint16_t i = 0;
		IMU_GetData(i++);
		
		if(i >= IMU_DateLength_MAX){
			Cyberry_Potter_Status.IMU_Status = IMU_Sampled;
			i = 0;
			MPU6050_INT_Disable();
		}
		EXTI_ClearITPendingBit(EXTI_Line5);	
  }
}
