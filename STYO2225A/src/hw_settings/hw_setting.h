#ifndef	_HW_SETTING_H
#define	_HW_SETTING_H




#define SCIF_CH_NUM_0      (0)
#define SCIF_CH_NUM_1      (1)
#define SCIF_CH_NUM_2      (2)
#define SCIF_CH_NUM_3      (3)
#define SCIF_CH_NUM_4      (4)
#define SCIF_CH_NUM_5      (5)
#define SCIF_CH_NUM_6      (6)
#define SCIF_CH_NUM_7      (7)


#define OSPL_CPG_STBCR_MSTP0               (0x01u)
#define OSPL_CPG_STBCR_MSTP1               (0x02u)
#define OSPL_CPG_STBCR_MSTP2               (0x04u)
#define OSPL_CPG_STBCR_MSTP3               (0x08u)
#define OSPL_CPG_STBCR_MSTP4               (0x10u)
#define OSPL_CPG_STBCR_MSTP5               (0x20u)
#define OSPL_CPG_STBCR_MSTP6               (0x40u)
#define OSPL_CPG_STBCR_MSTP7               (0x80u)



void ADC_PortSetting(void);
void SCIF_PortSetting(const uint32_t ch);
void VDC5_LcdPortSetting(void);
void initTimer(void);

/** \brief  Enable FIQ

    This function enables FIQ interrupts by clearing the F-bit in the CPSR.
    Can only be executed in Privileged modes.
 */
#define __enable_fault_irq()                __asm__ volatile ("cpsie f")


/** \brief  Disable FIQ

    This function disables FIQ interrupts by setting the F-bit in the CPSR.
    Can only be executed in Privileged modes.
 */
#define __disable_fault_irq()               __asm__ volatile ("cpsid f")



#endif
