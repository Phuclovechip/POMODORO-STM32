#ifndef _BUZZER_
#define _BUZZER_
#include "stm32f1xx.h"
extern TIM_HandleTypeDef htim1;
void beep_500ms();
void buzzer_init();
#endif