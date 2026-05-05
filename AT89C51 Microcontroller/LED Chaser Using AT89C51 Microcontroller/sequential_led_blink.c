#include <reg51.h>

void main()
{
	unsigned char x,y;
	volatile unsigned int i;
	
	P1 = 0x00;
	
	while(1)
	{
		x=0x01;
		for(y=0;y<8;y++)
		{
			P1=x;
			for(i=0;i<35000;i++);
			x=x<<1;
		}
	}
}
