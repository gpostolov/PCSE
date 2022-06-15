/**
 ******************************************************************************
 * @file      SHT3x_DIS.c
 * @author    Driver para el SHT3x-DIS
 * @brief
 ******************************************************************************
 */

/* Includes */
#include <inc/sht3x_dis.h>
#include <stdio.h>

/* Defines */

#define MAX_LENGHT 4

/* Private */
typedef struct _sht3x_config_s{
	sht3x_address_t address;
	sht3x_mode_t mode;
}_sht3x_config_t;

static void _SHT3x_DIS_write(uint8_t *data);
static void _SHT3x_DIS_read_TH(uint32_t *temp,uint32_t *hum);
static void _SHT3x_DIS_read_STATUS(uint32_t *status);

/* Variables */
static _sht3x_config_t my_config;

/* Functions */
void SHT3x_DIS_config(sht3x_address_t my_address, sht3x_mode_t my_mode){
	//Address
	if ((my_address == SHT3X_ADDRESS_A) || (my_address == SHT3X_ADDRESS_B)){
		my_config.address = my_address;
	}else{
		my_config.address = SHT3X_ADDRESS_A;
	}

	//Mode
	switch (my_mode){
	//Single Shot
	case SHT3X_MODE_HIGH_CS_ENABLED:
	case SHT3X_MODE_MEDIUM_CS_ENABLED:
	case SHT3X_MODE_LOW_CS_ENABLED:
	case SHT3X_MODE_HIGH_CS_DISABLED:
	case SHT3X_MODE_MEDIUM_CS_DISABLED:
	case SHT3X_MODE_LOW_CS_DISABLED:
	//Periodic
	case SHT3X_MODE_HIGH_MPS005:
	case SHT3X_MODE_MEDIUM_MPS005:
	case SHT3X_MODE_LOW_MPS005:
	case SHT3X_MODE_HIGH_MPS010:
	case SHT3X_MODE_MEDIUM_MPS010:
	case SHT3X_MODE_LOW_MPS010:
	case SHT3X_MODE_HIGH_MPS020:
	case SHT3X_MODE_MEDIUM_MPS020:
	case SHT3X_MODE_LOW_MPS020:
	case SHT3X_MODE_HIGH_MPS040:
	case SHT3X_MODE_MEDIUM_MPS040:
	case SHT3X_MODE_LOW_MPS040:
	case SHT3X_MODE_HIGH_MPS100:
	case SHT3X_MODE_MEDIUM_MPS100:
	case SHT3X_MODE_LOW_MPS100:
		my_config.mode = my_mode;
		break;
	default:
		my_config.mode = SHT3X_MODE_HIGH_CS_ENABLED;
		break;
	}
}

void SHT3x_DIS_reset(void){
	uint8_t tx_buffer[2];
	tx_buffer[0] = (SHT3X_COMMAND_SOFT_RESET & 0xFF00u) >> 8u;
	tx_buffer[1] =  SHT3X_COMMAND_SOFT_RESET & 0x00FFu;
	_SHT3x_DIS_write(tx_buffer);
}

void SHT3x_DIS_heater(bool enabled){
	uint8_t tx_buffer[2];
	if(enabled){
		tx_buffer[0] = (SHT3X_COMMAND_HEATER_ENABLED & 0xFF00u) >> 8u;
		tx_buffer[1] =  SHT3X_COMMAND_HEATER_ENABLED & 0x00FFu;
	}else{
		tx_buffer[0] = (SHT3X_COMMAND_HEATER_DISABLED & 0xFF00u) >> 8u;
		tx_buffer[1] =  SHT3X_COMMAND_HEATER_DISABLED & 0x00FFu;
	}
	_SHT3x_DIS_write(tx_buffer);
}

void SHT3x_DIS_read_status(uint32_t *status){
	uint8_t tx_buffer[2];
	tx_buffer[0] = (SHT3X_COMMAND_READ_STATUS & 0xFF00u) >> 8u;
	tx_buffer[1] =  SHT3X_COMMAND_READ_STATUS & 0x00FFu;
	_SHT3x_DIS_write(tx_buffer);
	_SHT3x_DIS_read_STATUS(status);
}

void SHT3x_DIS_clear_status(void){
	uint8_t tx_buffer[2];
	tx_buffer[0] = (SHT3X_COMMAND_CLEAR_STATUS & 0xFF00u) >> 8u;
	tx_buffer[1] =  SHT3X_COMMAND_CLEAR_STATUS & 0x00FFu;
	_SHT3x_DIS_write(tx_buffer);
}

void SHT3x_DIS_read_TH(uint32_t *temp,uint32_t *hum){
	uint8_t tx_buffer[2];
	tx_buffer[0] = (my_config.mode & 0xFF00u) >> 8u;
	tx_buffer[1] =  my_config.mode & 0x00FFu;
	_SHT3x_DIS_write(tx_buffer);
	_SHT3x_DIS_read_TH(temp, hum);
}



static void _SHT3x_DIS_write(uint8_t *data){
	SHT3x_DIS_write_PORT(my_config.address, data,2);
}

static void _SHT3x_DIS_read_TH(uint32_t *temp,uint32_t *hum){
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

static void _SHT3x_DIS_read_STATUS(uint32_t *status){
	uint8_t rx_buffer[6];

	rx_buffer[0] = 0x00;
	rx_buffer[1] = 0x00;
	rx_buffer[2] = 0x00;
	rx_buffer[3] = 0x00;
	rx_buffer[4] = 0x00;
	rx_buffer[5] = 0x00;

	SHT3x_DIS_read_PORT(my_config.address,rx_buffer,6);

	*status = *rx_buffer;
}
