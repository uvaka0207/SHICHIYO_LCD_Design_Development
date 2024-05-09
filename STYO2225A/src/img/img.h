
#ifndef  _IMG_H
#define  _IMG_H

#include "img_dat.h"

struct img_data_struct{
    uint8_t *image;
	uint32_t size;
};


extern const uint8_t *GetImageData(int32_t image_id);
extern uint16_t GetImageWidth(int32_t image_id);
extern uint16_t GetImageHeight(int32_t image_id);
extern int GetImageDataSize(int32_t image_id);

#endif

