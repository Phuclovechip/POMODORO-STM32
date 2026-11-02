#ifndef _MACHINE_
#define _MACHINE_
#include "stm32f1xx.h"
#include "buzzer.h"
#include "i2c.h"
#include "i2c_lcd.h"
#include "led.h"
#include "Button.h"
#define STUDY_TIME_MAX 25
#define REST_TIME_MAX 5
typedef enum{
	STUDY,
	STOP_STUDY,
	REST,
	STOP_REST,
}state_st;
extern I2C_HandleTypeDef hi2c1;
extern i2c_st data;
extern state_st state;
extern BUTTON_Typedef button;
void machine_task();
void machine_init();
#endif