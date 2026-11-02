#include "led.h"
static uint32_t mark_time;
void led_control(){
	if(HAL_GetTick()-mark_time>=500){
		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_1);
		mark_time=HAL_GetTick();
	}
}
void led_off(){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,0);
}