#include "Button.h"
__weak  void press_button(uint16_t key_state){
	
}
//Button function
void button_handle(BUTTON_Typedef *Buttonx){
	uint8_t key=HAL_GPIO_ReadPin(Buttonx->GPIOx,Buttonx->GPIO_Pin);
	if(key!=Buttonx->key_filter){
		Buttonx->mark_debounce=HAL_GetTick();
		Buttonx->key_filter=key;
		Buttonx->is_debounce=1;
	}
	if(Buttonx->is_debounce && (HAL_GetTick()-Buttonx->mark_debounce>=20)){
		Buttonx->key_state=Buttonx->key_filter;
		Buttonx->is_debounce=0;
	}
	if(Buttonx->key_last!=Buttonx->key_state){
		//press
		if(Buttonx->key_state==GPIO_PIN_RESET){
			press_button(Buttonx->key_state);
			Buttonx->is_start_press=1;
			Buttonx->mark_start_press=HAL_GetTick();
		}
		Buttonx->key_last=Buttonx->key_state;
	}
}
void Button_init(BUTTON_Typedef *Buttonx,GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin){
	Buttonx->GPIOx=GPIOx;
	Buttonx->GPIO_Pin=GPIO_Pin;	
	Buttonx->key_state=1;
	Buttonx->key_filter=1;
	Buttonx->key_last=1;
	Buttonx->is_debounce=0;
	Buttonx->is_start_press=0;
	Buttonx->mark_debounce=0;
	Buttonx->mark_start_press=0;
}

