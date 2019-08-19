#include "key.h"
#include "sys.h"
#include "led.h"
#include "beep.h"
#include "delay.h"

int main (void)
{
	u8 receiver;
	KEY_Init();
	LED_Init();
	BEEP_Init();
	delay_init();
	
	while(1)
	{
		receiver=KEY_Scan(1);
		if(receiver==1)
		{
			while(1)
			{
				LED0=1;LED1=0;delay_ms(500);
				LED0=0;LED1=1;delay_ms(500);
			}
		}
		else if(receiver==2)
		{
			int a = 2000,i;
      while(1)
			{
				for(i=0;i<a;i++)
				{
					LED0=0;LED1=0;
					delay_ms(a-i);
					LED0=1;LED1=1;
					delay_ms(i);
				}
					for(i=0;i<a;i++)
				{
					LED0=0;LED1=0;
					delay_ms(i);
					LED0=1;LED1=1;
					delay_ms(a-i);
				}
			}				
		}
			
		else if(receiver==3)
		{
			LED0=0;LED1=0;BEEP=1;
		}	
		else
					delay_ms(10);
	}

}

