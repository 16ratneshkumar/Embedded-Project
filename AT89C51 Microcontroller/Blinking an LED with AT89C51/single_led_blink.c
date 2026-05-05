#include <reg51.h>

void main(){
	volatile unsigned int i;
	while(1)
	{
		P1=0x01;
		for(i=0;i<30000;i++);
		P1=0x00;
		for(i=0;i<30000;i++);

	}
}
