#ifndef _SERIAL_FLASH_H
#define _SERIAL_FLASH_H

#define SERIAL_FLASH_PAGE_SIZE		2048
#define SERIAL_FLASH_REDUNDANCY		64
#define FLASH_PAGE_NUM				64
#define FLASH_BLOCK_NUM				1024




extern struct serial_flash_struct serial_flash;

int serial_flash_read_page(uint16_t page_address , uint8_t buf[] , int size);
int serial_flash_write_page(uint16_t page_address , uint8_t buf[] , int size);
int serial_flash_erase_block(uint16_t page_address);
int serial_flash_copy_page(uint16_t src_page_address , uint16_t dest_page_address );

uint8_t serial_flash_get_status(void);
uint8_t serial_flash_get_feature(uint8_t feature);
uint8_t serial_flash_set_feature(uint8_t feature , uint8_t val);



void serial_flash_reset(void);
#define 	SERIAL_STATUS_ANS_OIP			0x01U
#define 	SERIAL_STATUS_ANS_WEL			0x02U
#define 	SERIAL_STATUS_ANS_ERS_F			0x04U
#define 	SERIAL_STATUS_ANS_PRG_F			0x08U
#define 	SERIAL_STATUS_ANS_ECCS0			0x10U
#define 	SERIAL_STATUS_ANS_ECCS1			0x20U

#endif
