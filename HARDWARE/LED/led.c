#include "led.h"
#include "delay.h"
	   

//��ʼ��PB5��PE5Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��PA,PD�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_8|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_15;				 //LED0-->PA.8 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.8
 GPIO_ResetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_8|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_15);						 //PA.8 �����

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13| GPIO_Pin_14|GPIO_Pin_15|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;	    		 //LED1-->PD.2 �˿�����, �������
 GPIO_Init(GPIOB, &GPIO_InitStructure);	  				 //������� ��IO���ٶ�Ϊ50MHz
 GPIO_ResetBits(GPIOB,GPIO_Pin_13| GPIO_Pin_14|GPIO_Pin_15|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5); 						 //PD.2 ����� 
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6| GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;	    		 //LED1-->PD.2 �˿�����, �������
 GPIO_Init(GPIOC, &GPIO_InitStructure);	  				 //������� ��IO���ٶ�Ϊ50MHz
 GPIO_ResetBits(GPIOC, GPIO_Pin_6| GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12); 
}
void process(u8 date)
{
/*if(date==1)
{
		OUT0=1;delay_ms(1000);OUT0=0;
}
else if(date==2)
{
   OUT1=1;delay_ms(1000);OUT1=0;

}else if(date==3)
{
  OUT2=1;delay_ms(1000);OUT2=0;

}else if(date==4)
{
 OUT3=1;delay_ms(1000);OUT3=0;

}else if(date==5)
{
OUT4=1;delay_ms(1000);OUT4=0;

}else if(date==6)
{
OUT5=1;delay_ms(1000);OUT5=0;

}else if(date==7)
{
OUT6=1;delay_ms(1000);OUT6=0;

}else if(date==8)
{
OUT7=1;delay_ms(1000);OUT7=0;

}else if(date==9)
{

OUT8=1;delay_ms(1000);OUT8=0;
}else if(date==0x0a)
{

OUT9=1;delay_ms(1000);OUT9=0;
}else if(date==0x0b)
{
OUT10=1;delay_ms(1000);OUT10=0;

}else if(date==0x0c)
{
OUT11=1;delay_ms(1000);OUT11=0;

}else if(date==0x0d)
{
OUT12=1;delay_ms(1000);OUT12=0;

}else if(date==0x0e)
{
OUT13=1;delay_ms(1000);OUT13=0;

}else if(date==0x0f)
{

OUT14=1;delay_ms(1000);OUT14=0;
}*/
switch(date)
			{				 
			
				case 0x10:	//ͬʱ����LED0,LED1��ת 
				
          OUT15=1;
					delay_ms(1000);OUT15=0;
					break;
					case 0x0f:	//ͬʱ����LED0,LED1��ת 
				
          OUT14=1;
					delay_ms(1000);OUT14=0;
					break;
					case 0x0e:	//ͬʱ����LED0,LED1��ת 
				
          OUT13=1;
					delay_ms(1000);OUT13=0;
					break;
					case 0x0d:	//ͬʱ����LED0,LED1��ת 
          
					OUT12=1;delay_ms(1000);OUT12=0;
					break;
					case 0x0c:	//ͬʱ����LED0,LED1��ת 
          OUT11=1;delay_ms(1000);OUT11=0;
					break;
					case 0x0b:	//ͬʱ����LED0,LED1��ת 
          OUT10=1;delay_ms(1000);OUT10=0;
					break;
					case 0x0a:	//ͬʱ����LED0,LED1��ת 
		       OUT9=1;delay_ms(1000);OUT9=0;
					break;
					case 0x09:	//ͬʱ����LED0,LED1��ת 
	
				OUT8=1;delay_ms(1000);OUT8=0;
					break;
					case 0x08:	//ͬʱ����LED0,LED1��ת 
	        OUT7=1;delay_ms(1000);OUT7=0;
					break;
					case 0x07:	//ͬʱ����LED0,LED1��ת 
	       
					OUT6=1;delay_ms(1000);OUT6=0;
					break;
					case 0x06:	//ͬʱ����LED0,LED1��ת 
          OUT5=1;delay_ms(1000);OUT5=0;
	
					break;
					case 0X05:	//ͬʱ����LED0,LED1��ת 
		
				OUT4=1;delay_ms(1000);OUT4=0;
					break;
					case 0x04:	//ͬʱ����LED0,LED1��ת 
		        OUT3=1;delay_ms(1000);OUT3=0;
					break;
				case 0x03:	//����LED0��ת
			  // OUT2=1;delay_ms(1000);OUT2=0;
					OUT2=!OUT2;
					break;
				case 0x02:	//����LED1��ת	
          //OUT1=1;delay_ms(1000);OUT1=0;
					OUT1=!OUT1;
					break;
				case 0x01:	//ͬʱ����LED0,LED1��ת 
					//OUT0=1;delay_ms(1000);OUT0=0;
				OUT0=!OUT0;
	
					break;
			}


}
 
