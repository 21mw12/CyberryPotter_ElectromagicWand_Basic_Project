#ifndef __LED_H
#define __LED_H

///////////////////////////////////////////////////////////
//
// �ļ����ܣ�LED����ع��ܺ���
// �汾��V1.1
// ���ߣ�īε��MW��
// �޸�ʱ�䣺2023/04/27
//
///////////////////////////////////////////////////////////

#include "stm32f10x.h"

/* LED����������Ϣ */
#define All_LED_Periph		RCC_APB2Periph_GPIOA		// ����ʱ��
#define All_LED_Port			GPIOA										// IO�˿���
#define State_LED_Pin 		GPIO_Pin_7							// IO�˿�
#define Green_LED_Pin 		GPIO_Pin_6							// IO�˿�
#define Red_LED_Pin 			GPIO_Pin_5							// IO�˿�
#define Yellow_LED_Pin 		GPIO_Pin_4							// IO�˿�
#define White_LED_Pin 		GPIO_Pin_3							// IO�˿�

/**
  * @brief LED��ʼ��
  * @return ��
  */
void LED_Init(void);

void State_LED_ON(void);
void State_LED_OFF(void);

void Green_LED_ON(void);
void Green_LED_OFF(void);

void Red_LED_ON(void);
void Red_LED_OFF(void);

void Yellow_LED_ON(void);
void Yellow_LED_OFF(void);

void White_LED_ON(void);
void White_LED_OFF(void);

#endif

///////////////////////////////////////////////////////////
//
// ������־��
// V1.0: 2023/04/21
//				ʵ����LED�������Լ�LED����˸����
// V1.1: 2023/04/27
//				ʵ����LED��״̬��ת����
//
///////////////////////////////////////////////////////////
