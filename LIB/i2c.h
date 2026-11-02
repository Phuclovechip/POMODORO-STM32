#ifndef _I2C_
#define _I2C_
#include "stm32f1xx.h"
typedef struct{
	uint16_t Second;
	uint16_t Minute;
	uint16_t Hour;
	uint16_t Day;
	uint16_t Date;
	uint16_t Month;
	uint16_t Year;
	I2C_HandleTypeDef *hi2c;
}i2c_st;
void RTC_WRITETIME(i2c_st *data);
void RTC_READTIME(i2c_st *data);
void reset_data(i2c_st *data);
void i2c_init(i2c_st *data,I2C_HandleTypeDef *hi2c);
#endif