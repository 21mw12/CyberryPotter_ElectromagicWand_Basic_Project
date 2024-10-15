#include "LED.h"
#include "Delay.h"

void LED_Init(void) {
	RCC_APB2PeriphClockCmd(All_LED_Periph, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;
	GPIO_InitStructure.GPIO_Pin = State_LED_Pin | Green_LED_Pin | Red_LED_Pin | Yellow_LED_Pin | White_LED_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init(All_LED_Port, &GPIO_InitStructure);
	
	State_LED_OFF();
	Green_LED_OFF();
	Red_LED_OFF();
	Yellow_LED_OFF();
	White_LED_OFF();
}

void State_LED_ON(void) {	
	GPIO_SetBits(All_LED_Port, State_LED_Pin);
}

void State_LED_OFF(void) {	
	GPIO_ResetBits(All_LED_Port, State_LED_Pin);
}

void Green_LED_ON(void) {	
	GPIO_SetBits(All_LED_Port, Green_LED_Pin);
}

void Green_LED_OFF(void) {	
	GPIO_ResetBits(All_LED_Port, Green_LED_Pin);
}

void Red_LED_ON(void) {	
	GPIO_SetBits(All_LED_Port, Red_LED_Pin);
}

void Red_LED_OFF(void) {	
	GPIO_ResetBits(All_LED_Port, Red_LED_Pin);
}

void Yellow_LED_ON(void) {	
	GPIO_SetBits(All_LED_Port, Yellow_LED_Pin);
}

void Yellow_LED_OFF(void) {	
	GPIO_ResetBits(All_LED_Port, Yellow_LED_Pin);
}

void White_LED_ON(void) {	
	GPIO_SetBits(All_LED_Port, White_LED_Pin);
}

void White_LED_OFF(void) {	
	GPIO_ResetBits(All_LED_Port, White_LED_Pin);
}
