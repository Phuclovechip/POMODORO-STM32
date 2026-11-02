#include "machine.h"
#define SEC_MAX 59
static uint16_t sec_current;
static uint16_t min_current;
uint8_t is_time;
void set_time(){
	sec_current=SEC_MAX-data.Second;
	switch(state){
		case(STUDY):min_current=(STUDY_TIME_MAX-1)-data.Minute;break;
		case(REST):min_current=(REST_TIME_MAX-1)-data.Minute;break;
		default:break;
	}
}
void lcd_control(){
	switch(state){
		case(STUDY):{
			char buff[50];
			lcd_put_cursor(0,0,&hi2c1);
			lcd_send_string("STUDY TIME",&hi2c1);
			sprintf(buff,"%02d:%02d",min_current,sec_current);
			lcd_put_cursor(1,0,&hi2c1);
			lcd_send_string(buff,&hi2c1);
			break;
		}
		case(STOP_STUDY):{
			char buff[50];
			lcd_put_cursor(0,0,&hi2c1);
			lcd_send_string("TIME'S UP!",&hi2c1);
			sprintf(buff,"-%02d:%02d",data.Minute,data.Second);
			lcd_put_cursor(1,0,&hi2c1);
			lcd_send_string(buff,&hi2c1);
			break;
		}
		case(STOP_REST):{
			char buff[50];
			lcd_put_cursor(0,0,&hi2c1);
			lcd_send_string("TIME'S UP!",&hi2c1);
			sprintf(buff,"-%02d:%02d",data.Minute,data.Second);
			lcd_put_cursor(1,0,&hi2c1);
			lcd_send_string(buff,&hi2c1);
			break;
		}
		case(REST):{
			char buff[50];
			lcd_put_cursor(0,0,&hi2c1);
			lcd_send_string("REST TIME",&hi2c1);
			sprintf(buff,"%02d:%02d",min_current,sec_current);
			lcd_put_cursor(1,0,&hi2c1);
			lcd_send_string(buff,&hi2c1);
			break;
		}
	}
}
static uint16_t set_is_time(){
	if(min_current==0 && sec_current==0) return 1;
	else return 0;
}
void press_button(uint16_t key_state){
	switch(state){
		case(STOP_STUDY):
			state=REST;
		  reset_data(&data);
		  lcd_clear(&hi2c1);
			set_time();
		  break;
		case(STOP_REST):
			state=STUDY;
		  reset_data(&data);
		  lcd_clear(&hi2c1);
		  set_time();
		  break;
		default:break;
	}
}
void state_control(){
	switch(state){
		case(STUDY):
			RTC_READTIME(&data);
			led_off();
			if(set_is_time()==1){
				state=STOP_STUDY;
				beep_500ms();
				lcd_clear(&hi2c1);
				reset_data(&data);
			}break;
		case(STOP_STUDY):
			RTC_READTIME(&data);
			led_control();
		  break;
		case(STOP_REST):
			RTC_READTIME(&data);
			led_control();
		  break;
		case(REST):
			RTC_READTIME(&data);
			led_off();
			if(set_is_time()==1){
				state=STOP_REST;
				beep_500ms();
				lcd_clear(&hi2c1);
				reset_data(&data);
			}break;
		default:break;
	}
}
void machine_task(){
	set_time();
	lcd_control();
	state_control();
	button_handle(&button);
}
void machine_init(){
	state=STUDY;
}