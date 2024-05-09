#ifndef  LAYER_H
#define  LAYER_H

#include "graphics_obj.h"

#define L_CODELIST00 1
#define L_CONFIGURATION00 2
#define L_DETAIL00 3
#define L_HOME00 4
#define L_KEY00 5
#define L_KEY01 6
#define L_KEY02 7
#define L_PROCESS00 8
#define L_PROCESS01 9
#define L_W_CONFIG00 10
#define L_W_CONFIG01 11
#define L_W_MODESELECT00 12
#define L_W_SETTING00 13
#define L_W_SETTING01 14
#define L_W_SETTING02 15
#define L_W_SETTING03 16

extern void LoadLayer(layer_data_t *layer , int layer_id);
extern char* GetLayerName(int layer_id);

#endif
