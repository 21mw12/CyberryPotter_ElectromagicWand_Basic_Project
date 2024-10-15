#ifndef __LED_H
#define __LED_H

///////////////////////////////////////////////////////////
//
// 文件功能：LED的相关功能函数
// 版本：V1.1
// 作者：墨蔚（MW）
// 修改时间：2023/04/27
//
///////////////////////////////////////////////////////////

#include "stm32f10x.h"

/* LED引脚配置信息 */
#define All_LED_Periph		RCC_APB2Periph_GPIOA		// 总线时钟
#define All_LED_Port			GPIOA										// IO端口组
#define State_LED_Pin 		GPIO_Pin_7							// IO端口
#define Green_LED_Pin 		GPIO_Pin_6							// IO端口
#define Red_LED_Pin 			GPIO_Pin_5							// IO端口
#define Yellow_LED_Pin 		GPIO_Pin_4							// IO端口
#define White_LED_Pin 		GPIO_Pin_3							// IO端口

/**
  * @brief LED初始化
  * @return 无
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
// 更新日志：
// V1.0: 2023/04/21
//				实现了LED的亮灭以及LED的闪烁功能
// V1.1: 2023/04/27
//				实现了LED的状态反转功能
//
///////////////////////////////////////////////////////////
