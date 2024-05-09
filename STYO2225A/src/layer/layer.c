#include "stdinx.h"
#include "layer.h"

extern void L_CODELIST00_LoadLayer(layer_data_t *layer);
extern void L_CONFIGURATION00_LoadLayer(layer_data_t *layer);
extern void L_DETAIL00_LoadLayer(layer_data_t *layer);
extern void L_HOME00_LoadLayer(layer_data_t *layer);
extern void L_KEY00_LoadLayer(layer_data_t *layer);
extern void L_KEY01_LoadLayer(layer_data_t *layer);
extern void L_KEY02_LoadLayer(layer_data_t *layer);
extern void L_PROCESS00_LoadLayer(layer_data_t *layer);
extern void L_PROCESS01_LoadLayer(layer_data_t *layer);
extern void L_W_CONFIG00_LoadLayer(layer_data_t *layer);
extern void L_W_CONFIG01_LoadLayer(layer_data_t *layer);
extern void L_W_MODESELECT00_LoadLayer(layer_data_t *layer);
extern void L_W_SETTING00_LoadLayer(layer_data_t *layer);
extern void L_W_SETTING01_LoadLayer(layer_data_t *layer);
extern void L_W_SETTING02_LoadLayer(layer_data_t *layer);
extern void L_W_SETTING03_LoadLayer(layer_data_t *layer);

void LoadLayer(layer_data_t *layer, int layer_id)
{
	switch (layer_id)
	{
	case L_CODELIST00:
		L_CODELIST00_LoadLayer(layer);
		break;
	case L_CONFIGURATION00:
		L_CONFIGURATION00_LoadLayer(layer);
		break;
	case L_DETAIL00:
		L_DETAIL00_LoadLayer(layer);
		break;
	case L_HOME00:
		L_HOME00_LoadLayer(layer);
		break;
	case L_KEY00:
		L_KEY00_LoadLayer(layer);
		break;
	case L_KEY01:
		L_KEY01_LoadLayer(layer);
		break;
	case L_KEY02:
		L_KEY02_LoadLayer(layer);
		break;
	case L_PROCESS00:
		L_PROCESS00_LoadLayer(layer);
		break;
	case L_PROCESS01:
		L_PROCESS01_LoadLayer(layer);
		break;
	case L_W_CONFIG00:
		L_W_CONFIG00_LoadLayer(layer);
		break;
	case L_W_CONFIG01:
		L_W_CONFIG01_LoadLayer(layer);
		break;
	case L_W_MODESELECT00:
		L_W_MODESELECT00_LoadLayer(layer);
		break;
	case L_W_SETTING00:
		L_W_SETTING00_LoadLayer(layer);
		break;
	case L_W_SETTING01:
		L_W_SETTING01_LoadLayer(layer);
		break;
	case L_W_SETTING02:
		L_W_SETTING02_LoadLayer(layer);
		break;
	case L_W_SETTING03:
		L_W_SETTING03_LoadLayer(layer);
		break;
	}
}
char* GetLayerName(int layer_id)
{
	switch (layer_id)
	{
	case L_CODELIST00:
		return "L_CODELIST00";
	case L_CONFIGURATION00:
		return "L_CONFIGURATION00";
	case L_DETAIL00:
		return "L_DETAIL00";
	case L_HOME00:
		return "L_HOME00";
	case L_KEY00:
		return "L_KEY00";
	case L_KEY01:
		return "L_KEY01";
	case L_KEY02:
		return "L_KEY02";
	case L_PROCESS00:
		return "L_PROCESS00";
	case L_PROCESS01:
		return "L_PROCESS01";
	case L_W_CONFIG00:
		return "L_W_CONFIG00";
	case L_W_CONFIG01:
		return "L_W_CONFIG01";
	case L_W_MODESELECT00:
		return "L_W_MODESELECT00";
	case L_W_SETTING00:
		return "L_W_SETTING00";
	case L_W_SETTING01:
		return "L_W_SETTING01";
	case L_W_SETTING02:
		return "L_W_SETTING02";
	case L_W_SETTING03:
		return "L_W_SETTING03";
	}
	return "";
}
