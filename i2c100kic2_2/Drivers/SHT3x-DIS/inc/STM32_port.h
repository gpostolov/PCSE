/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PORT_H
#define __PORT_H

/* Functions */
void SHT3x_DIS_write_PORT(uint16_t DevAddress, uint8_t *pData, uint16_t Size);
void SHT3x_DIS_read_PORT(uint16_t DevAddress, uint8_t *pData, uint16_t Size);

#ifdef __cplusplus
extern "C" {
#endif

#endif /* __PORT_H */
