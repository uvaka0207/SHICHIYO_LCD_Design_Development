#include "stdinx.h"
#include "mode.h"
#include "layer/layer.h"
#include "graphics_ctrl.h"
#include "common.h"
#include "touch_ctrl.h"
#include "touch_check.h"



/*
 *		このモードに移った場合の動作
 */
static void mode_change_callback(void)
{
	SetBackColor(0xFF323232);
	mode.layer[0] = L_CONFIGURATION00;
	mode.layer[1] = 0;
	mode.layer[2] = 0;
	mode.layer[3] = 0;
	SetBackLight(100);
}

/*
 *		モード制御用の動作
 */
static void mode_always_callback(void)
{
	mode.layer[0] = L_CONFIGURATION00;
	// SINGLEタイプの場合

}
/*
 *		このモードから別のモードに移る場合の動作
 */
static void mode_move_callback(void)
{


}

/*
 *		IO制御用の動作
 */
static void mode_action_callback(void)
{
	

}

void change_mode_config(void)
{
	mode_data.always_callback = (VOID_CALLBACK)mode_always_callback;
	mode_data.move_callback = (VOID_CALLBACK)mode_move_callback;
	mode_data.action_callback = (VOID_CALLBACK)mode_action_callback;
	mode_change_callback();
}
