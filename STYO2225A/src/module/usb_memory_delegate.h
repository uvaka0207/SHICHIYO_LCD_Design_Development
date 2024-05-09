
#ifndef _R_USB_MEMORY_DELEGATE_H
#define _R_USB_MEMORY_DELEGATE_H
#include "os/delegate.h"
#include "ff.h"





FRESULT usb_f_open (FIL* fp, TCHAR* path, BYTE mode);

FRESULT usb_f_write (FIL* fp, void* buff, UINT btw, UINT* bw);
FRESULT usb_f_read (FIL* fp, void* buff, UINT btr, UINT* br);
FRESULT usb_f_close (FIL* fp);
FRESULT usb_f_lseek (FIL* fp, FSIZE_t ofs);
FRESULT usb_f_truncate (FIL* fp);
FRESULT usb_f_sync (FIL* fp);


#define usb_f_size(fp) f_size(fp)
#endif







