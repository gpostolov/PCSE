# DRIVER PARA SHT3x-DIS
## `Sensor de temperatura y humedad` ##

## Funciones ##
- Init
- Config
- Reset
- Heater
- Read Status
- Clear Status
- Read Humidity & Temperature 

## Port creado para STM32F4xx ##
## Ejemplo de uso para NUCLEO-F429ZI ##
	..
    #include "sht3x_dis.h"
	..
	I2C_HandleTypeDef hi2c2;
	..
	uint32_t temp = 0;
	uint32_t hum = 0;
	int main(void){
		..
		sht3x_t sht3x_dev;
		I2C_Handle_Port_t i2c;
		i2c.instance = &hi2c2;
		
		SHT3x_DIS_init  (&sht3x_dev, &i2c);
		SHT3x_DIS_config(&sht3x_dev, SHT3X_ADDRESS_A, SHT3X_MODE_HIGH_CS_ENABLED);
		..
		SHT3x_DIS_read_TH(&sht3x_dev,&temp,&hum);
		..
	}

    
