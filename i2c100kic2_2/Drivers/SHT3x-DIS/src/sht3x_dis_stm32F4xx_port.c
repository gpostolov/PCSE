#include "inc/sht3x_dis_stm32f4xx_port.h"

#define TIMEOUT 2000

void _SHT3x_DIS_write_PORT_Error_Handler (HAL_StatusTypeDef error);

char * const cadena_HAL_ERROR 	= " ! HAL_ERROR\n";
char * const cadena_HAL_BUSY 	= " ! HAL_BUSY\n";
char * const cadena_HAL_TIMEOUT = " ! HAL_TIMEOUT\n";

void SHT3x_DIS_write_PORT(uint16_t DevAddress, uint8_t *pData, uint16_t Size, I2C_Handle_Port_t * const i2c_handle){
	HAL_StatusTypeDef i2c_status;
	i2c_status = HAL_I2C_Master_Transmit(i2c_handle->instance, DevAddress<<1, pData, Size,TIMEOUT);
	if(i2c_status != HAL_OK){
		_SHT3x_DIS_write_PORT_Error_Handler(i2c_status);
	}
}

void SHT3x_DIS_read_PORT(uint16_t DevAddress, uint8_t *pData, uint16_t Size, I2C_Handle_Port_t * const i2c_handle){
	HAL_StatusTypeDef i2c_status;
	i2c_status = HAL_I2C_Master_Receive(i2c_handle->instance, (DevAddress<<1), pData, Size,TIMEOUT);
	if(i2c_status != HAL_OK){
		_SHT3x_DIS_write_PORT_Error_Handler(i2c_status);
	}
}

void _SHT3x_DIS_write_PORT_Error_Handler (HAL_StatusTypeDef error){
	switch (error) {
		case HAL_ERROR:
			printf(&cadena_HAL_ERROR);
			break;
		case HAL_BUSY:
			printf(&cadena_HAL_BUSY);
			break;
		case HAL_TIMEOUT:
			printf(&cadena_HAL_TIMEOUT);
			break;
		default:
			break;
	}
}