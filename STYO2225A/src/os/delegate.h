#ifndef	_DELEGATE_H
#define	_DELEGATE_H

#define MAX_ARG 16

#define DELEGATE_LIST_SIZE		16


typedef struct {
	volatile int id;
	volatile int stat;
	volatile void *ret;
	volatile void *arg[MAX_ARG];

}delegate;



typedef void (*d_func_t)(volatile delegate *arg);


int call_delegate(int id , d_func_t func , delegate *arg);
void delegate_event(int id);
#endif



