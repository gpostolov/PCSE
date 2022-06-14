#include <stdio.h>

// IF NUCLEO - F429ZI
#include "stm32f4xx_hal.h"
extern I2C_HandleTypeDef hi2c2;

void SHT3x_DIS_write_PORT(uint16_t DevAddress, uint8_t *pData, uint16_t Size){
	HAL_StatusTypeDef i2c_status;
	i2c_status = HAL_I2C_Master_Transmit(&hi2c2, DevAddress<<1, pData, Size,2000);
}

void SHT3x_DIS_read_PORT(uint16_t DevAddress, uint8_t *pData, uint16_t Size){
	HAL_StatusTypeDef i2c_status;
	i2c_status = HAL_I2C_Master_Receive(&hi2c2, (DevAddress<<1), pData, Size,2000);
}

