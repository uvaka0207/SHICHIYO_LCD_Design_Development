#ifndef	_EEP_RW_H
#define	_EEP_RW_H

#define EEP_MAXQUE 16L
#define CHECK_CODE 0xA5
#define EEP_BUF_SIZE 1024 + 2


extern int data_read(uint8_t buf[],int address,uint16_t size);
extern int data_write(uint8_t buf[],uint16_t address , uint16_t size);
extern void eep_handle(void);
extern int eep_get_status(void);



#endif
