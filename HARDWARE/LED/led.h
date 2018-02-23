#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 

//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define OUT0 PBout(13)	// PA8
#define OUT1 PBout(14)	// PD2	
#define OUT2 PBout(15)	// PA8
#define OUT3 PCout(6)	// PD2	
#define OUT4 PCout(7)	// PA8
#define OUT5 PAout(12)	// PD2	
#define OUT6 PAout(11)	// PA8
#define OUT7 PCout(9)	// PD2	
#define OUT8 PCout(8)	// PA8
#define OUT9 PCout(11)	// PD2	
#define OUT10 PCout(10)	// PA8
#define OUT11 PAout(15)	// PD2	
#define OUT12 PBout(5)	// PA8
#define OUT13 PBout(4)	// PD2	
#define OUT14 PBout(3)	// PA8
#define OUT15 PCout(12)	// PD2	
#define SET433 PAout(8)	// PA8
#define BESET PAout(1)	// PA8

void LED_Init(void);//≥ı ºªØ
void process(u8 date);

		 				    
#endif
