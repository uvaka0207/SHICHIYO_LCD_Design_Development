#include "stdinx.h"
#include "mode.h"


// 関数宣言
extern void change_mode_home(void);
extern void change_mode_codelist(void);
extern void change_mode_key00(void);
extern void change_mode_key01(void);
extern void change_mode_key02(void);
extern void change_detail(void);
extern void change_process00(void);
extern void change_process01(void);
extern void change_mode_config(void);

void change_mode_exe(int new_mode)
{
	switch(new_mode)
	{
	case MODE_HOME:			//
		change_mode_home();
		break;
	case MODE_CODELIST:
		change_mode_codelist();
		break;
	case MODE_KEY00:
		change_mode_key00();
		break;
	case MODE_KEY01:
		change_mode_key01();
		break;
	case MODE_KEY02:
		change_mode_key02();
		break;
	case MODE_DETAIL:
		change_mode_detail();
		break;
	case MODE_PROCESS00:
		change_mode_process00();
		break;
	case MODE_PROCESS01:
		change_mode_process01();
		break;
	case MODE_CONFIG:
		change_mode_config();
	}

}





