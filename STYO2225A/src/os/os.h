#ifndef	_OS_H
#define	_OS_H

#include  "stdinx.h"

typedef int (*func_t)(void);
typedef	volatile int	LockObject;


//#define USE_SYSTEM_HEAP							// システムで最初から用意されているHEAPを使用する場合


#define MAX_THREAD		16					// 最大スレッド数

#define RZ
// RXの場合
#ifdef RX
#define init_psw() 			 //set_psw(0x00010000)	// 割り込みが発生するように変更する。
#define set_sp(x)			set_isp(x)						// スタックポインターを設定する。
#endif

// RZの場合


#ifdef RZ
// 割り込みが発生するように変更する。
#define init_psw() 			 //set_psw(0x00010000)
// スタックポインターを設定する。
#define set_sp(x)			 {int val = (int)x; __asm volatile (" MOV     SP, %0": "=r" (val));}
#endif

#ifndef USE_SYSTEM_HEAP


#define HEAP_SIZE		0x80000					// ヒープメモリの容量		MAX 1M
#define MAX_HEAP_NUM	(512)			// ヒープメモリの最大確保数

#define os_malloc		inx_malloc
#define os_free			inx_free

extern uint8_t *inx_malloc(int size);
extern void inx_free(volatile  uint8_t *address);

#else

#define os_malloc		malloc
#define os_free			free


#endif


// ユーザー使用関数

extern void initOS(void);
extern int CreateThread(func_t	func , int stack_size);
extern void KillThread(uint8_t th_id);
extern void Aboot(void);

extern void Sleep(int32_t wait_count);
extern void Sleep_us(int32_t wait_count);
extern void SetPriority(int32_t priority);
extern void Interval(int32_t interval);
extern void WakeUP_Thread(int ThreadID);
extern uint8_t GetThreadID(void);
extern void GetThreadCpuUse(int *buf , int size);
extern uint32_t GetCpuAdditon(void);
extern void ResetCpuAdditon(void);


int Lock(LockObject *l , int timeout);
void UnLock(LockObject *l);

extern void  MEMORY_Flush(void);

// INT割り込み指定

int exe_Thread_Timer(void);
void exe_Thread_SoftwareInt(void);

#define TIMER_MUL			10

#endif

