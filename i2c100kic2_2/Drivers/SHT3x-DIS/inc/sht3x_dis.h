/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SHT3X_DIS_H
#define __SHT3X_DIS_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "STM32_port.h"

/* ADDRESS */
typedef enum sht3x_address_e {
    SHT3X_ADDRESS_A = 0x44,
    SHT3X_ADDRESS_B = 0x45,
} sht3x_address_t;

/* MODE */
typedef enum sht3x_mode_e {
	/* SINGLE SHOT MODE */
    SHT3X_MODE_HIGH_CS_ENABLED		= 0x2C06,	//Clock Stretching enabled  - Repeatability High
	SHT3X_MODE_MEDIUM_CS_ENABLED	= 0x2C0D,	//Clock Stretching enabled  - Repeatability Medium
	SHT3X_MODE_LOW_CS_ENABLED		= 0x2C10,	//Clock Stretching enabled  - Repeatability Low
    SHT3X_MODE_HIGH_CS_DISABLED		= 0x2400,	//Clock Stretching disabled - Repeatability High
	SHT3X_MODE_MEDIUM_CS_DISABLED	= 0x240B,	//Clock Stretching disabled - Repeatability Medium
	SHT3X_MODE_LOW_CS_DISABLED		= 0x2416,	//Clock Stretching disabled - Repeatability Low
	/* PERIODIC MODE */
	SHT3X_MODE_HIGH_MPS005			= 0x2032,	//mps 0.5 - Repeatability High
	SHT3X_MODE_MEDIUM_MPS005		= 0x2024,	//mps 0.5 - Repeatability Medium
	SHT3X_MODE_LOW_MPS005			= 0x202F,	//mps 0.5 - Repeatability Low
	SHT3X_MODE_HIGH_MPS010			= 0x2130,	//mps 1   - Repeatability High
	SHT3X_MODE_MEDIUM_MPS010		= 0x2126,	//mps 1   - Repeatability Medium
	SHT3X_MODE_LOW_MPS010			= 0x212D,	//mps 1   - Repeatability Low
	SHT3X_MODE_HIGH_MPS020			= 0x2236,	//mps 2   - Repeatability High
	SHT3X_MODE_MEDIUM_MPS020		= 0x2220,	//mps 2   - Repeatability Medium
	SHT3X_MODE_LOW_MPS020			= 0x222B,	//mps 2   - Repeatability Low
	SHT3X_MODE_HIGH_MPS040			= 0x2334,	//mps 4   - Repeatability High
	SHT3X_MODE_MEDIUM_MPS040		= 0x2322,	//mps 4   - Repeatability Medium
	SHT3X_MODE_LOW_MPS040			= 0x2329,	//mps 4   - Repeatability Low
	SHT3X_MODE_HIGH_MPS100			= 0x2737,	//mps 10  - Repeatability High
	SHT3X_MODE_MEDIUM_MPS100		= 0x2721,	//mps 10  - Repeatability Medium
	SHT3X_MODE_LOW_MPS100			= 0x272a	//mps 10  - Repeatability Low
} sht3x_mode_t;

/* COMMAND */
typedef enum sht3x_command_e {
    SHT3X_COMMAND_SOFT_RESET		= 0x30A2,	//Soft Reset / Re-Initialization
	SHT3X_COMMAND_HEATER_ENABLED	= 0x306D,	//Heater enable
	SHT3X_COMMAND_HEATER_DISABLED	= 0x3066,	//Heater disable
	SHT3X_COMMAND_READ_STATUS		= 0xF32D,	//Read Status Register
	SHT3X_COMMAND_CLEAR_STATUS		= 0xF32D	//Clear Status Register
} sht3x_command_t;

//typedef struct sht3x_handle_s{
//	I2C_HandleTypeDef *i2c_handle;
//	uint16_t device_address;
//} sht3x_handle_t;

/* FUNCTIONS */
void SHT3x_DIS_config(sht3x_address_t my_address, sht3x_mode_t my_mode);
void SHT3x_DIS_reset(void);
void SHT3x_DIS_heater(bool enabled);
void SHT3x_DIS_read_status(uint32_t *status);
void SHT3x_DIS_clear_status(void);

void SHT3x_DIS_read_TH(uint32_t *temp,uint32_t *hum);

#ifdef __cplusplus
extern "C" {
#endif

#endif /* __SHT3X_DIS_H */
