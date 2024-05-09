
#include "stdinx.h"
#include "image.h"
#include "img.h"

extern const struct img_data_struct img_data[];


const uint8_t *GetImageData(int32_t image_id)
{
	if(image_id >= IMG_FILE){
		return get_usb_image_address(image_id - IMG_FILE);
	}else if(image_id >= 0 && image_id < MAX_IMAGE_FILE){
	    return img_data[image_id].image;
	}else{
		return NULL;
	}
}
int GetImageDataSize(int32_t image_id)
{
	if(image_id >= IMG_FILE){
		return get_usb_image_size(image_id - IMG_FILE);
	}else if(image_id >= 0 && image_id < MAX_IMAGE_FILE){
	    return img_data[image_id].size;
	}else{
		return 0;
	}
}
