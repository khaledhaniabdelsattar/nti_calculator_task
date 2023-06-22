/*
 * main.c
 *
 *  Created on: Jun 15, 2023
 *      Author: Khaled
 */


#include "key_pad.h"
#include "lcd_interfacing.h"
#include "math.h"
#include <util/delay.h>

void main ()
{

key_pad_init();
lcd_intilization();
send_command(LCD_CLEAR);
go_to_xy(row1, column1);
lcd_display('y');
//lcd_display_num(6500);
u8 clcul_input [3]={0};
u8 op1_buffer[2]={'0'};
u8 op1_counter=0;
u8 op2_buffer[2]={'0'};
u8 op2_counter=0;
u8 operation=0;
u8 equal=0;
u8 displaying_counter=0;
u8 i=0;
//u8 clr_lcd=0;
u8 j=0;
u16 op1=0;
u16 op2=0;
u16 result=0;
f32 result_dev=0;
u8 key_reading=0;
u16 exppo=0;
u16 constant=0;
while(1)
{



	 key_reading=key_pad_read();
		     _delay_ms(250);

		      if(key_reading!=0xff)
		        {
		    	  //_delay_ms(250);
		    	  if(key_reading=='#')
		    	  {

		    		  send_command(LCD_CLEAR);
		    		  equal=0;
		    		  operation=0;
		    		  op1=0;
		    		  op2=0;
		    		  op1_counter=0;
		    		  op2_counter=0;
		    		  displaying_counter=0;

		    		  //key_reading=0xff;
		    	  }

		    	  else if(key_reading=='=')
		    	  {
		    		  equal='=';

		    	  }

		    	  else if((key_reading=='+')||(key_reading=='-')||(key_reading=='*')||(key_reading=='/'))
		    	  		 {

		    	  			 operation=key_reading;


		    	  		 }

		    	  else if((key_reading!='+')||(key_reading!='-')||(key_reading!='*')||key_reading!='/')
		    	  {

		    		  if(operation==0)
		    		  {
		    		  op1_buffer[op1_counter]=key_reading;
		    		  op1_counter++;
		    		  }

		    		  else
		    		 {

		    		 	op2_buffer[op2_counter]=key_reading;
		    		 		  op2_counter++;

		    		 }


		    	  }


		    	  if(key_reading!='#')
		    	  {
		    	  go_to_xy(row1, displaying_counter);
		    	  lcd_display(key_reading);
		    	  displaying_counter++;
		    	  }
		    	  //key_reading=0xff;
		    	  //clcul_input[i]=key_reading;
		    	  //i++;

		        }

   if(equal=='=')
   {
	   op1=0;
	   op2=0;
	   //key_reading=0xff;
	   equal=0;
	   exppo=1;
	   constant=1;
	  // operation=0;
	   //op1_counter=0;
	   //op2_counter=0;
	   //op1=clcul_input[0];
	   //operation=clcul_input[1];
	   //op2=clcul_input[2];
	   for(i=0;i<op1_counter;i++)
	   {
		   //go_to_xy(row1,i+column10);
		   		   //lcd_display(op1_buffer[i]);
		   		// displaying_counter++;
		   constant=1;
		   exppo=(op1_counter-1)-i;

		   if(exppo!=0)
		   {
		   for(j=0;j<exppo;j++)
		   {

			   constant=10*constant;

		   }

		   }

     op1=op1+((op1_buffer[i]-'0')*constant);

	   }

	   for(i=0;i<op2_counter;i++)
	   	   {
		   //go_to_xy(row2,i+column10);
		   //lcd_display(op2_buffer[i]);
		   //displaying_counter++;

		   constant=1;
		   exppo=(op2_counter-1)-i;

		   		   if(exppo!=0)
		   		   {

		   		  for(j=0;j<exppo;j++)
		   		   {

		   			   constant=10*constant;

		   		   }

		   		   }

      op2=op2+((op2_buffer[i]-'0')*constant);

	   	   }
	            //op1=0;
	  	        //op2=0;
	   //op1_buffer[0]=0;
	   //op1_buffer[1]=0;
	   //op1_buffer[2]=0;
	   //op1_buffer[3]=0;
	       //op2_buffer[0]=0;
	   	   //op2_buffer[1]=0;
	   	   //op2_buffer[2]=0;
	   	   //op2_buffer[3]=0;
	  // op2_buffer={0};
	            //operation=0;
	   	      	//op1_counter=0;
	   	      	//op2_counter=0;
	   	      	//displaying_counter=0;
	   	       //go_to_xy(row1,displaying_counter);
	   	       //lcd_display_num(op1);
	   	       //lcd_display_string(op1_buffer);
	   	    //go_to_xy(row2,displaying_counter);
	   	    //lcd_display_num(op2);
	   	 //lcd_display_string(op2_buffer);
	   	 //op1=0;
	   	 //op2=0;
	   switch (operation)
	      {
	   	case '+':
	   		result=op1+op2;
	   		break;

	   	case '-':
	   			result=op1-op2;
	   			break;
	   	case '*':
	   			result=op1*op2;
	   			break;

		case '/':
			result_dev=(f32)op1/(f32)op2;
		   			break;

	      }
	        //operation=0;
	      	//op1_counter=0;
	      	//op2_counter=0;
	      	//displaying_counter=0;
	   if(operation=='/')
	   {
		   go_to_xy(row1,displaying_counter);
		  	       LcdDisplayFloat(result);

	   }
	   else
		   {
		   go_to_xy(row1,displaying_counter);
		    Lcd_DisplayNum(result);
		   }
	          operation=0;
	       	      	op1_counter=0;
	       	      	op2_counter=0;
	       //_delay_ms(1000);
   }



}
}
