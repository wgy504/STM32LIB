#pragma once

// for roundf()
#define __USE_C99_MATH

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>


#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_dma.h"
#include "stm32f10x_flash.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_pwr.h"
#include "misc.h"


typedef unsigned char UINT8;
typedef signed char   INT8;
typedef unsigned short int UINT16;
typedef unsigned int UINT32;
typedef short int INT16;
typedef int INT32;
typedef float FLOAT32 ;

#include "Global.h"
#include "ucos_ii.h"
#include "ublox_ubx.h"
#include "jacTypeDef.h"
#include "UcloudMsgTypeDef.h"


#ifndef __CC_ARM
// only need this garbage on gcc
#define USE_LAME_PRINTF
#include "printf.h"
#endif



#include "usart.h"
#include "bsp.h"
#include "system.h"
#include "adc.h"

#define U_ID_0 (*(uint32_t*)0x1FFFF7E8)
#define U_ID_1 (*(uint32_t*)0x1FFFF7EC)
#define U_ID_2 (*(uint32_t*)0x1FFFF7F0)

#define LED0_GPIO   GPIOA
#define LED0_PIN    GPIO_Pin_12 // PB3 (LED)
#define LED1_GPIO   GPIOB
#define LED1_PIN    GPIO_Pin_4 // PB4 (LED)
#define BEEP_GPIO   GPIOE
#define BEEP_PIN    GPIO_Pin_11 // PE11 (Buzzer) pwm1


/************************  function  ***************************/
#define LED0
#define BEEP
#define USART1_ON
#define USART2_ON
#define UART5_ON
#define USART_DMA 1

#define digitalHi(p, i)     { p->BSRR = i; }
#define digitalLo(p, i)     { p->BRR = i; }
#define digitalToggle(p, i) { p->ODR ^= i; }
#define digitalIn(p, i)     (p->IDR & i)


// Helpful macros
#ifdef LED0
#define LED0_TOGGLE              digitalToggle(LED0_GPIO, LED0_PIN);
#define LED0_OFF                 digitalLo(LED0_GPIO, LED0_PIN);
#define LED0_ON                  digitalHi(LED0_GPIO, LED0_PIN);
#else
#define LED0_TOGGLE
#define LED0_OFF
#define LED0_ON
#endif

#ifdef LED1
#define LED1_TOGGLE              digitalToggle(LED1_GPIO, LED1_PIN);
#define LED1_OFF                 digitalHi(LED1_GPIO, LED1_PIN);
#define LED1_ON                  digitalLo(LED1_GPIO, LED1_PIN);
#else
#define LED1_TOGGLE
#define LED1_OFF
#define LED1_ON
#endif

#ifdef BEEP_GPIO
#define BEEP_TOGGLE              digitalToggle(BEEP_GPIO, BEEP_PIN);
#define BEEP_OFF                 digitalHi(BEEP_GPIO, BEEP_PIN);
#define BEEP_ON                  digitalLo(BEEP_GPIO, BEEP_PIN);
#else
#define BEEP_TOGGLE              ;
#define BEEP_OFF                 ;
#define BEEP_ON                  ;
#endif

#ifdef INV_GPIO
#define INV_OFF                  digitalLo(INV_GPIO, INV_PIN);
#define INV_ON                   digitalHi(INV_GPIO, INV_PIN);
#else
#define INV_OFF                 ;
#define INV_ON                  ;
#endif


#define KEY_POWER_CLK         RCC_APB2Periph_GPIOA
#define KEY_POWER_GPIO        GPIOA
#define KEY_POEWR_PIN         GPIO_Pin_0
#define KEY_POWER_SOURCE      GPIO_PortSourceGPIOA
#define KEY_POWER_PIN_SOURCE  GPIO_PinSource0
#define KEY_POEWR_EXTI        EXTI_Line0
#define KEY_POWER_IRQChannel  EXTI0_IRQn

#define GPRS_POWER_ON()  GPIO_SetBits(GPIOB,GPIO_Pin_5)
#define GPRS_POWER_OFF() GPIO_ResetBits(GPIOB,GPIO_Pin_5)

#define POWER_ON()  GPIO_SetBits(GPIOB,GPIO_Pin_3)
#define POWER_OFF() GPIO_ResetBits(GPIOB,GPIO_Pin_3)


