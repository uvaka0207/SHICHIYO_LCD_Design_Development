#ifndef  TOUCH_CHECK_H
#define  TOUCH_CHECK_H

#define TOUCH_ON        0
#define TOUCH_LONG      1
#define TOUCH_OFF       2
#define TOUCH_SHORT_OFF 3
#define TOUCH_REPEAT    4
#define TOUCH_LONG5      5


void reset_touch(void);
void touch_check_obj(void);
void touch_stop(void);
void touch_start(void);
int get_touch_ok(void);
void touch_enable(void);
void touch_disable(void);

obj_data_t *GetTouchObject(void);

#endif
