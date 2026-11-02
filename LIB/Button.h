#ifndef BUTTON_H
#define BUTTON_H
#include "stm32f1xx.h"

//Normal button
typedef struct{
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
	uint32_t mark_debounce;
	uint8_t key_state;
	uint8_t key_last;
	uint8_t key_filter;
	uint8_t is_debounce;
	uint8_t is_start_press; 
	uint32_t mark_start_press;
}BUTTON_Typedef;
void Button_init(BUTTON_Typedef *Buttonx,GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void press_button(uint16_t key_state);
void button_handle(BUTTON_Typedef *Buttonx);
#endif