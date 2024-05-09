#include "stdinx.h"
#include "font_data.h"


const uint8_t *get_font_address(int font_id)
{ 
    switch(font_id){
	case 0:
		return font_data_00;
	}
	return NULL;
}
