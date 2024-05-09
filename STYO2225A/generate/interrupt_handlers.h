                                                                          
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
/************************************************************************/
/*    File Version: V1.02                                               */
/*    Date Generated: 30/05/2019                                        */
/************************************************************************/

#ifndef INTERRUPT_HANDLERS_H
#define INTERRUPT_HANDLERS_H

/* Undefined Instruction */
void INT_Excep_UndefinedInst(void) __attribute__((interrupt, used));

/* SWI*/
void INT_Excep_SWI(void) __attribute__((interrupt, used));

/* PREFETCH_ABORT*/
void INT_Excep_PREFETCH_ABORT(void) __attribute__((interrupt, used));

/* DATA_ABORT*/
void INT_Excep_DATA_ABORT(void) __attribute__((interrupt, used));

/* Reserved*/
void INT_Excep_Reserved(void) __attribute__((interrupt, used));

/* IRQ*/
//void INT_Excep_IRQ(void) __attribute__((interrupt, used));
int INT_Excep_IRQ(void);

/* FIQ*/
void INT_Excep_FIQ(void) __attribute__((interrupt, used));

/*;<<VECTOR DATA START (POWER ON RESET)>>*/
/*;Power On Reset PC*/
extern void _PowerON_Reset(void) __attribute__((interrupt, used));                                                                                                                
/*;<<VECTOR DATA END (_POWER ON RESET)>>*/

#endif
