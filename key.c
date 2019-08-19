#include "key.h"
#include "stm32f10x.h"
#include "delay.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
}
u8 KEY_Scan(u8 mode)
{
	static u8 kup=1;
	if(mode) kup=1;
	if(kup&&(WAUP==1||KEY0==0||KEY1==0))
	{
		delay_ms(10);
		kup=0;
		if(WAUP==0)return 1;
		else if(KEY0==1)return 2;
		else if(KEY1==1)return 3;
	}
	else if(WAUP==0&&KEY0==1&&KEY1==1)
		kup==1;
		return 0;
}



