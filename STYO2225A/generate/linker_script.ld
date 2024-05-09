MEMORY {
    CSx    : ORIGIN = 0x00000000, LENGTH = 0x18000000
    S_ROM (rx)  : ORIGIN = 0x18100000, LENGTH = 63M				/* On-Board S-FLASH ROM                 */
    SRAM  (rwx)    : ORIGIN = 0x20000000, LENGTH = 5M			/* 3.5M */
/*    SRAMNC(rwx)  : ORIGIN = 0x20300000, LENGTH = 2M	 */		/* 1.5M */
}
SECTIONS
{
	.fvectors 0x18100000 : AT (0x18100000)
	{
		KEEP(*(.fvectors))
	} > S_ROM
	.text 0x18100100 : AT (0x18100100)
	{
		*(.text)
        * (INIT_TTB)                /*asm*/
        * (INITCA9CACHE)            /*asm*/
        * (L1_CACHE_OPERATION)		/*asm */
	} > S_ROM
	.rvectors : 
	{
		_rvectors_start = .;
		KEEP(*(.rvectors))
		_rvectors_end = .;
	} > S_ROM
	.init : 
	{
		*(.init)
	} > S_ROM
	.ARM.extab : 
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
		PROVIDE_HIDDEN (__exidx_start = .);
	} > S_ROM
	.ARM.exidx : 
	{
		*(.ARM.exidx .gnu.linkonce.armexidx.*)
		PROVIDE_HIDDEN (__exidx_end = .);
	} > S_ROM
	
	.fini : 
	{
		*(.fini)
	} > S_ROM
	.got : 
	{
		*(.got)
		*(.got.plt)
	} > S_ROM
	.rodata : 
	{
		*(.rodata)
		*(.rodata.*)
		_erodata = .;
	} > S_ROM
	.eh_frame_hdr : 
	{
		*(.eh_frame_hdr)
	} > S_ROM
	.eh_frame : 
	{
		*(.eh_frame)
	} > S_ROM
	.jcr : 
	{
		*(.jcr)
	} > S_ROM
	.tors : 
	{
		__CTOR_LIST__ = .;
		. = ALIGN(2);
		__ctors = .;
		*(.ctors)
		__ctors_end = .;
		__CTOR_END__ = .;
		__DTOR_LIST__ = .;
		___dtors = .;
		*(.dtors)
		___dtors_end = .;
		__DTOR_END__ = .;
		. = ALIGN(2);
		_mdata = .;
	} > S_ROM
	
	.FONT  0x18400000 : AT (0x18400000)
	{
		*(FONT)
	} > S_ROM	
	.IMAGE  0x18800000 : AT (0x18800000)
	{
		*(IMAGE)
	} > S_ROM	
    .stack : {
        . = ALIGN( 0x10 );
        end = .;                            /* referenced by syscalls.c _sbrk() for heap management */
        Image$$ARM_LIB_STACK$$ZI$$Base = .;
        . += 0x00008000;                    /* This area is shared with stack and heap. */
        Image$$ARM_LIB_STACK$$ZI$$Limit = .;

        . = ALIGN( 0x10 );
        Image$$IRQ_STACK$$ZI$$Base = .;
        . += 0x00002000;
        Image$$IRQ_STACK$$ZI$$Limit = .;

        . = ALIGN( 0x10 );
        Image$$FIQ_STACK$$ZI$$Base = .;
        . += 0x00002000;
        Image$$FIQ_STACK$$ZI$$Limit = .;

        . = ALIGN( 0x10 );
        Image$$SVC_STACK$$ZI$$Base = .;
        . += 0x00002000;
        Image$$SVC_STACK$$ZI$$Limit = .;

        . = ALIGN( 0x10 );
        Image$$ABT_STACK$$ZI$$Base = .;
        . += 0x00002000;
        Image$$ABT_STACK$$ZI$$Limit = .;

        . = ALIGN( 0x4000 );
        Image$$TTB$$ZI$$Base = .;
        . += 0x00004000;
        Image$$TTB$$ZI$$Limit = .;
    } > SRAM
	
	.data : AT (_mdata)
	{
		_data = .;
		*(.data)
		*(.data.*)
		_edata = .;
	} > SRAM
	.bss : 
	{
		PROVIDE(__bss_start__ = .);
		_bss = .;
		*(.bss)
		*(.bss.**)
		*(COMMON)
		PROVIDE(__bss_end__ = .);
		_ebss = .;
		_end = .;
		PROVIDE(end = .);
	} > SRAM
	.HEAP (NOLOAD)  : ALIGN(0x10)
	{
		*(HEAP)
	} > SRAM
	.VRAM1 (NOLOAD) : ALIGN(0x1000)
	{
		*(VRAM)
	} > SRAM
	.VRAM2 (NOLOAD) : ALIGN(0x1000)
	{
		*(VRAM)
	} > SRAM
/*	.VRAM2 (NOLOAD) : ALIGN(0x1000)
	{
		*(VRAM)
	} > SRAMNC
	 */
/* .stack 0x20100000 (NOLOAD)  : AT (0x20100000)
	{
		_stack = .;
		*(STACK)
	} > SRAM
	*/

}
