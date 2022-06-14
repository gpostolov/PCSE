/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SHT3X_DIS_H
#define __SHT3X_DIS_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include "port.h"

/* ADDRESS */
typedef enum sht3x_address_e {
    SHT3X_I2C_ADDRESS_A ,
    SHT3X_I2C_ADDRESS_B
} sht3x_address_t;

/* SINGLE SHOT MODE */
typedef enum sht3x_mode_e {
    SHT3X_I2C_MODE_HIGH_CS_ENABLED,
	SHT3X_I2C_MODE_MEDIUM_CS_ENABLED,
	SHT3X_I2C_MODE_LOW_CS_ENABLED,
    SHT3X_I2C_MODE_HIGH_CS_DISABLED,
	SHT3X_I2C_MODE_MEDIUM_CS_DISABLED,
	SHT3X_I2C_MODE_LOW_CS_DISABLED
} sht3x_mode_t;

typedef struct sht3x_config_s{
	sht3x_address_t address;
	sht3x_mode_t mode;
}sht3x_config_t;

/* Functions */
void SHT3x_DIS_init(sht3x_address_t my_address, sht3x_mode_t my_mode);
void SHT3x_DIS_read_TH(uint32_t *temp,uint32_t *hum);

#ifdef __cplusplus
extern "C" {
#endif

#endif /* __SHT3X_DIS_H */
