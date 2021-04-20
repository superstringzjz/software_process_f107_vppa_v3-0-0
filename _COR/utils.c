#include	"utils.h"
#include "stm32f10x_dbgmcu.h"

s8 strlen(s8 *s){
	s8 i = 0;
	for(;*s != '\0'; s++)
		i++;
	return i;
}

s8 strncmp(s8 *s1, s8 *s2, s8 maxlen){
	s8 i;
	if(strlen(s1)!=strlen(s2))	return -1;
	for(i = 0; i < maxlen; i++){
		if(s1[i] != s2[i])	return ((s32) s1[i]) - ((s32) s2[i]);
		if(s1[i] == 0)			return 0;
	}
	return 0;
}

unsigned long strtodec(s8 *str, s8 cnt){
	u32 i;
	unsigned long number = 0;
	if(str[0]=='-'){
		for(i=1; i<cnt; i++){
			number *= 10;
			if(str[i]<'0'||str[i]>'9')	return (unsigned long)-1;
			number += str[i]-'0';
		}
		number=~number+1;
	}
	else if((str[0]=='0')&&((str[1]=='x')||(str[1]=='X'))){
		for(i=2;i<cnt;i++){
			number<<=4;
			number&=0xfffffff0;
			if((str[i]>='0')&&(str[i]<='9'))	          number+=str[i]-'0';
			else if((str[i]>='a')&&(str[i]<='f'))				number+=(str[i]-87);
			else if((str[i]>='A')&&(str[i]<='F'))				number+=(str[i]-55);
			else				                                return (unsigned long)-1;
		}
	}
	else{
		for(i=0; i<cnt; i++){
			number *= 10;
			if(str[i]<'0'||str[i]>'9')				return (unsigned long)-1;
			number += str[i]-'0';
		}
	}
	return number;
}



