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
 
	delay_init();	    	 //��ʱ������ʼ��	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
	LED_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ� 
	 KEY_Init();
 
	while(1)
	{
		if(USART_STA==1)
		{					   
			len=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
//			printf("\r\n�����͵���ϢΪ:\r\n");
//			for(t=0;t<len;t++)
//			{
//				USART1->DR=USART_RX_BUF[t];
//				while((USART1->SR&0X40)==0);//�ȴ����ͽ���
//			}
//			printf("\r\n\r\n");//���뻻��
			if(USART_RX_BUF[0]==0xaa&&USART_RX_BUF[1]==0xbb)
			{
			
			process(USART_RX_BUF[3]);
			}
			//USART_RX_BUF[3]=0;USART_RX_BUF[2]=0;USART_RX_BUF[1]=0;USART_RX_BUF[0]=0;
			USART_RX_STA=0;
			USART_STA=0;
		}
		key=KEY_Scan(0);	//�õ���ֵ
	   	if(key)
		{						   
			switch(key)
			{				 
			
					case KEY13_PRES:	//ͬʱ����LED0,LED1��ת 
				
          OUT13=1;
					delay_ms(1000);OUT13=0;
					break;
					case KEY12_PRES:	//ͬʱ����LED0,LED1��ת 
          
					OUT12=1;delay_ms(1000);OUT12=0;
					break;
					case KEY11_PRES:	//ͬʱ����LED0,LED1��ת 
          OUT11=1;delay_ms(1000);OUT11=0;
					break;
					case KEY10_PRES:	//ͬʱ����LED0,LED1��ת 
          OUT10=1;delay_ms(1000);OUT10=0;
					break;
					case KEY9_PRES:	//ͬʱ����LED0,LED1��ת 
		       OUT9=1;delay_ms(1000);OUT9=0;
					break;
					case KEY8_PRES:	//ͬʱ����LED0,LED1��ת 
	
				OUT8=1;delay_ms(1000);OUT8=0;
					break;
					case KEY7_PRES:	//ͬʱ����LED0,LED1��ת 
	        OUT7=1;delay_ms(1000);OUT7=0;
					break;
					case KEY6_PRES:	//ͬʱ����LED0,LED1��ת 
	       
					OUT6=1;delay_ms(1000);OUT6=0;
					break;
					case KEY5_PRES:	//ͬʱ����LED0,LED1��ת 
          OUT5=1;delay_ms(1000);OUT5=0;
	
					break;
					case KEY4_PRES:	//ͬʱ����LED0,LED1��ת 
		
				OUT4=1;delay_ms(1000);OUT4=0;
					break;
					case KEY3_PRES:	//ͬʱ����LED0,LED1��ת 
		        OUT3=1;delay_ms(1000);OUT3=0;
					break;
				case KEY2_PRES:	//����LED0��ת
			   OUT2=1;delay_ms(1000);OUT2=0;
					break;
				case KEY1_PRES:	//����LED1��ת	
          OUT1=1;delay_ms(1000);OUT1=0;
					break;
				case KEY0_PRES:	//ͬʱ����LED0,LED1��ת 
					OUT0=1;delay_ms(1000);OUT0=0;
	
					break;
			}
		}else delay_ms(10); 
	}	 
}


