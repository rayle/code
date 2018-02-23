#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "key.h"

u8 txbuffer[4];
 int main(void)
 {	
	u8 t;
	u8 len;	
 	vu8 key=0;	
	u16 times=0; 
 
	delay_init();	    	 //延时函数初始化	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	uart_init(9600);	 //串口初始化为9600
	LED_Init();		  	 //初始化与LED连接的硬件接口 
	 KEY_Init();
 
	while(1)
	{
		if(USART_STA==1)
		{					   
			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
//			printf("\r\n您发送的消息为:\r\n");
//			for(t=0;t<len;t++)
//			{
//				USART1->DR=USART_RX_BUF[t];
//				while((USART1->SR&0X40)==0);//等待发送结束
//			}
//			printf("\r\n\r\n");//插入换行
			if(USART_RX_BUF[0]==0xaa&&USART_RX_BUF[1]==0xbb)
			{
			
			process(USART_RX_BUF[3]);
			}
			//USART_RX_BUF[3]=0;USART_RX_BUF[2]=0;USART_RX_BUF[1]=0;USART_RX_BUF[0]=0;
			USART_RX_STA=0;
			USART_STA=0;
		}
		key=KEY_Scan(0);	//得到键值
	   	if(key)
		{						   
			switch(key)
			{				 
			
					case KEY13_PRES:	//同时控制LED0,LED1翻转 
				
          OUT13=1;
					delay_ms(1000);OUT13=0;
					break;
					case KEY12_PRES:	//同时控制LED0,LED1翻转 
          
					OUT12=1;delay_ms(1000);OUT12=0;
					break;
					case KEY11_PRES:	//同时控制LED0,LED1翻转 
          OUT11=1;delay_ms(1000);OUT11=0;
					break;
					case KEY10_PRES:	//同时控制LED0,LED1翻转 
          OUT10=1;delay_ms(1000);OUT10=0;
					break;
					case KEY9_PRES:	//同时控制LED0,LED1翻转 
		       OUT9=1;delay_ms(1000);OUT9=0;
					break;
					case KEY8_PRES:	//同时控制LED0,LED1翻转 
	
				OUT8=1;delay_ms(1000);OUT8=0;
					break;
					case KEY7_PRES:	//同时控制LED0,LED1翻转 
	        OUT7=1;delay_ms(1000);OUT7=0;
					break;
					case KEY6_PRES:	//同时控制LED0,LED1翻转 
	       
					OUT6=1;delay_ms(1000);OUT6=0;
					break;
					case KEY5_PRES:	//同时控制LED0,LED1翻转 
          OUT5=1;delay_ms(1000);OUT5=0;
	
					break;
					case KEY4_PRES:	//同时控制LED0,LED1翻转 
		
				OUT4=1;delay_ms(1000);OUT4=0;
					break;
					case KEY3_PRES:	//同时控制LED0,LED1翻转 
		        OUT3=1;delay_ms(1000);OUT3=0;
					break;
				case KEY2_PRES:	//控制LED0翻转
			   OUT2=1;delay_ms(1000);OUT2=0;
					break;
				case KEY1_PRES:	//控制LED1翻转	
          OUT1=1;delay_ms(1000);OUT1=0;
					break;
				case KEY0_PRES:	//同时控制LED0,LED1翻转 
					OUT0=1;delay_ms(1000);OUT0=0;
	
					break;
			}
		}else delay_ms(10); 
	}	 
}


