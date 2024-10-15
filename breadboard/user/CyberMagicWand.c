#include "CyberMagicWand.h"
#include "LED.h"
#include <stdio.h>
#include <stdarg.h>

Cyberry_Potter_Status_Typedef Cyberry_Potter_Status = {
	SYSTEM_TRANSMIT,
	KEY_Event_Null,
	IMU_Idle,
	LED_ALWAYS_ON,
	Serial_Idle
};

void Cyberry_Potter_System_Status_Update(void) {
	if(Cyberry_Potter_Status.Button_Status == KEY_Event_LongPress){
		switch(Cyberry_Potter_Status.System_Mode){
			case SYSTEM_IDLE:
				Cyberry_Potter_Status.System_Mode = SYSTEM_TRANSMIT;
				Cyberry_Potter_Status.LED_Status = LED_10HZ;
				printf("SYSTEM_TRANSMIT\n");
				break;
			case SYSTEM_TRANSMIT:
				Cyberry_Potter_Status.System_Mode = SYSTEM_RECORD;
				Cyberry_Potter_Status.LED_Status = LED_5HZ;
				printf("SYSTEM_RECORD\n");
				break;
			case SYSTEM_RECORD:
				Cyberry_Potter_Status.System_Mode = SYSTEM_IDLE;
				Cyberry_Potter_Status.LED_Status = LED_IDLE;
				printf("SYSTEM_IDLE\n");
				break;
		}  
		LED_Blink();
	}
}

void LED_Blink(void) {
	int i = 0;
	if(Cyberry_Potter_Status.LED_Status == LED_5HZ){
		for(i = 0; i < 6; i++){
			State_LED_OFF();
			Delay_ms(100);
			State_LED_ON();  
			Delay_ms(100);		
		}
		Cyberry_Potter_Status.LED_Status = LED_ALWAYS_ON;
	}
	else if(Cyberry_Potter_Status.LED_Status == LED_10HZ){
		for(i = 0; i < 11; i++){
			State_LED_OFF();
			Delay_ms(50);
			State_LED_ON();   
			Delay_ms(50);		
		}
		Cyberry_Potter_Status.LED_Status = LED_ALWAYS_ON;
		}
	else if (Cyberry_Potter_Status.LED_Status == LED_ALWAYS_ON){
		State_LED_ON();
	}
	else{
		State_LED_ON();
		Delay_ms(200);
		State_LED_OFF();
		Delay_ms(500);
		State_LED_ON();
		Delay_ms(300);
		Cyberry_Potter_Status.LED_Status = LED_ALWAYS_ON;
	}
}
