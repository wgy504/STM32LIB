#ifndef __SYSTEM_H__
#define __SYSTEM_H__


#ifdef __cplusplus
    extern "C" {
#endif

void write_onchip_flash(u32 addr,u8 *p,u16 n);
void read_onchip_flash(u32 addr,u8 *p,u16 n);


void EndianSwap32(void *p);
void EndianSwap16(void *p);
void JTAG_Set(u8 mode);
void Power_ON(void);
void GPRS_Wakeup(void);
void  SysStausCheck(void);
			
void serialCom(void);
#ifdef __cplusplus
    }
#endif
		

#endif 


