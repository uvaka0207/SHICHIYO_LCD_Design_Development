#ifndef IO_H
#define IO_H


#define GPIO_BIT_N0  (1u <<  0)
#define GPIO_BIT_N1  (1u <<  1)
#define GPIO_BIT_N2  (1u <<  2)
#define GPIO_BIT_N3  (1u <<  3)
#define GPIO_BIT_N4  (1u <<  4)
#define GPIO_BIT_N5  (1u <<  5)
#define GPIO_BIT_N6  (1u <<  6)
#define GPIO_BIT_N7  (1u <<  7)
#define GPIO_BIT_N8  (1u <<  8)
#define GPIO_BIT_N9  (1u <<  9)
#define GPIO_BIT_N10 (1u << 10)
#define GPIO_BIT_N11 (1u << 11)
#define GPIO_BIT_N12 (1u << 12)
#define GPIO_BIT_N13 (1u << 13)
#define GPIO_BIT_N14 (1u << 14)
#define GPIO_BIT_N15 (1u << 15)


#define GPIO_SET_BIT_N0			0x00010001
#define GPIO_SET_BIT_N1			0x00020002
#define GPIO_SET_BIT_N2			0x00040004
#define GPIO_SET_BIT_N3			0x00080008
#define GPIO_SET_BIT_N4			0x00100010
#define GPIO_SET_BIT_N5			0x00200020
#define GPIO_SET_BIT_N6			0x00400040
#define GPIO_SET_BIT_N7			0x00800080
#define GPIO_SET_BIT_N8			0x01000100
#define GPIO_SET_BIT_N9			0x02000200
#define GPIO_SET_BIT_N10		0x04000400
#define GPIO_SET_BIT_N11		0x08000800
#define GPIO_SET_BIT_N12		0x10001000
#define GPIO_SET_BIT_N13		0x20002000
#define GPIO_SET_BIT_N14		0x40004000
#define GPIO_SET_BIT_N15		0x80008000

#define GPIO_RESET_BIT_N0		0x00010000
#define GPIO_RESET_BIT_N1		0x00020000
#define GPIO_RESET_BIT_N2		0x00040000
#define GPIO_RESET_BIT_N3		0x00080000
#define GPIO_RESET_BIT_N4		0x00100000
#define GPIO_RESET_BIT_N5		0x00200000
#define GPIO_RESET_BIT_N6		0x00400000
#define GPIO_RESET_BIT_N7		0x00800000
#define GPIO_RESET_BIT_N8		0x01000000
#define GPIO_RESET_BIT_N9		0x02000000
#define GPIO_RESET_BIT_N10		0x04000000
#define GPIO_RESET_BIT_N11		0x08000000
#define GPIO_RESET_BIT_N12		0x10000000
#define GPIO_RESET_BIT_N13		0x20000000
#define GPIO_RESET_BIT_N14		0x40000000
#define GPIO_RESET_BIT_N15		0x80000000



void initIO(void);

// 出力

extern void O_TOUCH_X_VCC(int on_off);
extern void O_TOUCH_X_GND(int on_off);
extern void O_TOUCH_Y_VCC(int on_off);
extern void O_TOUCH_Y_GND(int on_off);
extern void O_TOUCH_Y_PULLDOWN(int on_off);

extern void O_BACKLIGHT(int on_off);
extern void O_WD(int on_off);
extern void O_BUZZER(int on_off);



extern void O_RS485_ENABLE1(int on_off);
extern void O_RS485_ENABLE2(int on_off);
extern void O_RS485_ENABLE3(int on_off);

extern void O_RESET_AR(int on_off);


extern void O_SF_SCK(int on_off);
extern void O_SF_CS(int on_off);
extern void O_SF_SI(int on_off);
extern void O_SF_WP(int on_off);
extern void O_SF_HOLD(int on_off);
extern int I_SF_SO(void);
extern int I_SF_SO0(void);
extern int I_SF_SO1(void);
extern int I_SF_SO2(void);
extern int I_SF_SO3(void);
extern void SF_SI_MODE_IN(void);
extern void SF_SI_MODE_OUT(void);


extern int I_VOLT(void);

extern int I_CH(void);

extern int I_DIPSW1(void);
extern int I_DIPSW2(void);
extern int I_DIPSW3(void);
extern int I_DIPSW4(void);



void O_RTC_CE(int on_off);
void O_RTC_CLK(int on_off);
void O_RTC_DI(int on_off);
int I_RTC_DO(void);


void BACK_LIGHT_PWM(int par);



#define N_SCAN					4			// スキャンでLEDの出力する数を指定する。(スキャンの数)

#define N_SCAN_LED				8			// スキャンでLEDの出力する数を指定する。(スキャンの数)
#define N_INPUT_KEY				1
#define N_INPUT_IP				2


#define MAX_CYCLE				4



struct scan_data{
	bit_fld8 scan;			// 入力データ
	bit_fld8 ch;			// 入力バッファ
	bit_fld8 in;			// 結果データ
};



struct iodata{
#if		N_SCAN_LED > 0
	union {
		uint8_t byte;
		bit_fld8 bit;
	}scan_out[N_SCAN_LED];				// LED出力

	union {
		uint8_t byte;
		bit_fld8 bit;
	}scan_out_buf[N_SCAN_LED];			// LED出力バッファ
	uint8_t bright[N_SCAN_LED];		// 明るさ
#endif


#if		N_INPUT_KEY > 0
	struct scan_data key_sw[N_INPUT_KEY];
#endif


#if		N_INPUT_IP > 0
	struct scan_data input_port[N_INPUT_IP];
#endif

};

extern struct iodata io;





void init_bu2090(void);


/*
 *		12bitの通信データを送信する
 */
void trans_bu2090(uint16_t trans[]);



extern void exc_io_handler(void);					// IO用の割り込みハンドラー





#endif
