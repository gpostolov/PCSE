/**
 ******************************************************************************
 * @file      SHT3x_DIS.c
 * @author    Driver para el SHT3x-DIS
 * @brief     Este documento es la base, luego falta el port para cada placa
 ******************************************************************************
 */

/* Includes */
#include <inc/sht3x_dis.h>
#include <stdio.h>

/* Defines */
#define _SHT3X_I2C_ADDRESS_A 0x44
#define _SHT3X_I2C_ADDRESS_B 0x45

#define _SHT3X_I2C_MODE_HIGH_CS_ENABLED_0		0x2C
#define _SHT3X_I2C_MODE_HIGH_CS_ENABLED_1		0x06

#define _SHT3X_I2C_MODE_MEDIUM_CS_ENABLED_0		0x2C
#define _SHT3X_I2C_MODE_MEDIUM_CS_ENABLED_1		0x0D

#define _SHT3X_I2C_MODE_LOW_CS_ENABLED_0		0x2C
#define _SHT3X_I2C_MODE_LOW_CS_ENABLED_1		0x10

#define _SHT3X_I2C_MODE_HIGH_CS_DISABLED_0		0x24
#define _SHT3X_I2C_MODE_HIGH_CS_DISABLED_1		0x00

#define _SHT3X_I2C_MODE_MEDIUM_CS_DISABLED_0	0x24
#define _SHT3X_I2C_MODE_MEDIUM_CS_DISABLED_1	0x0B

#define _SHT3X_I2C_MODE_LOW_CS_DISABLED_0		0x24
#define _SHT3X_I2C_MODE_LOW_CS_DISABLED_1		0x16

#define MAX_LENGHT 4

/* Private */
typedef struct _sht3x_config_s{
	uint16_t address;
	uint8_t command[2];
}_sht3x_config_t;

static void _SHT3x_DIS_write(void);
static void _SHT3x_DIS_read(uint32_t *temp,uint32_t *hum);

/* Variables */
static _sht3x_config_t my_config;

/* Functions */
void SHT3x_DIS_init(sht3x_address_t my_address, sht3x_mode_t my_mode){
	//Address
	if (my_address){
		my_config.address = _SHT3X_I2C_ADDRESS_B;
	}else{
		my_config.address = _SHT3X_I2C_ADDRESS_A;
	}
	//Mode
	switch (my_mode){
	case SHT3X_I2C_MODE_HIGH_CS_ENABLED:
		my_config.command[0] = _SHT3X_I2C_MODE_HIGH_CS_ENABLED_0;
		my_config.command[1] = _SHT3X_I2C_MODE_HIGH_CS_ENABLED_1;
		break;
	case SHT3X_I2C_MODE_MEDIUM_CS_ENABLED:
		my_config.command[0] = _SHT3X_I2C_MODE_MEDIUM_CS_ENABLED_0;
		my_config.command[1] = _SHT3X_I2C_MODE_MEDIUM_CS_ENABLED_1;
		break;
	case SHT3X_I2C_MODE_LOW_CS_ENABLED:
		my_config.command[0] = _SHT3X_I2C_MODE_LOW_CS_ENABLED_0;
		my_config.command[1] = _SHT3X_I2C_MODE_LOW_CS_ENABLED_1;
		break;
	case SHT3X_I2C_MODE_HIGH_CS_DISABLED:
		my_config.command[0] = _SHT3X_I2C_MODE_HIGH_CS_DISABLED_0;
		my_config.command[1] = _SHT3X_I2C_MODE_HIGH_CS_DISABLED_1;
		break;
	case SHT3X_I2C_MODE_MEDIUM_CS_DISABLED:
		my_config.command[0] = _SHT3X_I2C_MODE_MEDIUM_CS_DISABLED_0;
		my_config.command[1] = _SHT3X_I2C_MODE_MEDIUM_CS_DISABLED_1;
		break;
	case SHT3X_I2C_MODE_LOW_CS_DISABLED:
		my_config.command[0] = _SHT3X_I2C_MODE_LOW_CS_DISABLED_0;
		my_config.command[1] = _SHT3X_I2C_MODE_LOW_CS_DISABLED_1;
		break;
	default:
		my_config.command[0] = _SHT3X_I2C_MODE_HIGH_CS_ENABLED_0;
		my_config.command[1] = _SHT3X_I2C_MODE_HIGH_CS_ENABLED_1;
		break;
	}
}

void SHT3x_DIS_read_TH(uint32_t *temp,uint32_t *hum){
	_SHT3x_DIS_write();
	_SHT3x_DIS_read(temp, hum);
}

static void _SHT3x_DIS_write(){
	uint8_t tx_buffer[2];
	tx_buffer[0] = my_config.command[0];
	tx_buffer[1] = my_config.command[1];
	SHT3x_DIS_write_PORT(my_config.address, tx_buffer,2);
}

static void _SHT3x_DIS_read(uint32_t *temp,uint32_t *hum){
	uint8_t rx_buffer[6];

	rx_buffer[0] = 0x00;
	rx_buffer[1] = 0x00;
	rx_buffer[2] = 0x00;
	rx_buffer[3] = 0x00;
	rx_buffer[4] = 0x00;
	rx_buffer[5] = 0x00;

	SHT3x_DIS_read_PORT(my_config.address,rx_buffer,6);

	*temp = (uint32_t)(((rx_buffer[0]*256) + rx_buffer[1])*175)/65535.0-45.0;
	*hum =  (uint32_t)(((rx_buffer[3]*256) + rx_buffer[4]))*100.0/65535.0;
}


