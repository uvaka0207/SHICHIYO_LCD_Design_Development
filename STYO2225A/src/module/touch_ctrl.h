
extern int touch_ctrl_task(void);
extern int GetTouchXY(int *x , int *y);
extern int GetTouchRealXY(int *x , int *y);


/*
 *		タッチパネルキャリブレーションデータ
 */
struct touch_calibration_struct
{
	int x[4];
	int y[4];
};
extern struct touch_calibration_struct touch_calibration;


// 左上
#define TOUCH_REF_X_0		100
#define TOUCH_REF_Y_0		100

// 右上
#define TOUCH_REF_X_1		500
#define TOUCH_REF_Y_1		100

// 左下
#define TOUCH_REF_X_2		100
#define TOUCH_REF_Y_2		924

// 右下
#define TOUCH_REF_X_3		500
#define TOUCH_REF_Y_3		924

