#include "i2c.h"
#define ADDRESS_DEVICE 0x68<<1
#define ADDRESS_RES 0x00
uint8_t Decimal2BCD(uint8_t num){
	return ((num/10)<<4)|(num%10);
}
uint8_t BCD2Decimal(uint8_t num){
	return (num>>4)*10+(num&0x0F);
}
void RTC_WRITETIME(i2c_st *data){
	uint8_t buff[8];
	buff[0]=ADDRESS_RES;
	buff[1]=Decimal2BCD(data->Second);
	buff[2]=Decimal2BCD(data->Minute);
	buff[3]=Decimal2BCD(data->Hour);
	buff[4]=Decimal2BCD(data->Day);
	buff[5]=Decimal2BCD(data->Date);
	buff[6]=Decimal2BCD(data->Month);
	buff[7]=Decimal2BCD(data->Year);
	HAL_I2C_Master_Transmit(data->hi2c,ADDRESS_DEVICE,buff,8,200);
}
void RTC_READTIME(i2c_st *data){
	uint8_t buff[7];
	uint8_t address_res=ADDRESS_RES;
	HAL_I2C_Master_Transmit(data->hi2c,ADDRESS_DEVICE,&address_res,1,200);
	HAL_I2C_Master_Receive(data->hi2c,ADDRESS_DEVICE,buff,7,200);
	data->Second=BCD2Decimal(buff[0]);
	data->Minute=BCD2Decimal(buff[1]);
	data->Hour=BCD2Decimal(buff[2]);
	data->Day=BCD2Decimal(buff[3]);
	data->Date=BCD2Decimal(buff[4]);
	data->Month=BCD2Decimal(buff[5]);
	data->Year=BCD2Decimal(buff[6]);
}
void reset_data(i2c_st *data){
	data->Second=0;
	data->Minute=0;
	data->Hour=0;
	data->Day=0;
	data->Date=0;
	data->Month=0;
	data->Year=0;
	RTC_WRITETIME(data);
}
void i2c_init(i2c_st *data,I2C_HandleTypeDef *hi2c){
	data->hi2c=hi2c;
	data->Second=0;
	data->Minute=0;
	data->Hour=0;
	data->Day=0;
	data->Date=0;
	data->Month=0;
	data->Year=0;
	RTC_WRITETIME(data);
}