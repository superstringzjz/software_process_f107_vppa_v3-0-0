#ifndef		__UTILS_H
#define		__UTILS_H
#include "stm32f10x.h"

#define		next_line()	putch(0x0d);putch('\n')
void putch(s8 byte);				
void putstr(s8 *addr);		
void prompt(void);
s8 strlen(s8 *s);
s8 strncmp(s8 *s1, s8 *s2, s8 maxlen);
unsigned long strtodec(s8 *str, s8 cnt);
void putsint(u16 byte);
void putslong(u32 byte);
void putchxylarhex(s8 byte);

#endif
