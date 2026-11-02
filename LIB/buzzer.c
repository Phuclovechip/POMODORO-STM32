#include "buzzer.h"
void pwm_set_duty(uint32_t duty_level)
{
	uint32_t arr=duty_level*htim1.Init.Period/100;
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	htim1.Instance->CCR1=arr;
}
void beep_500ms(){
	pwm_set_duty(50);
	HAL_Delay(200);
	pwm_set_duty(0);
	HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_1);
}
void buzzer_init(){

}