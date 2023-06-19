/*
 * timer0_interfacing.c
 *
 *  Created on: Jul 10, 2022
 *      Author: Khaled
 */

#include "timer0_interfacing.h"

void timer0_preload(u8 preload)
{

	TIMER0_VALUE_REG=preload;

}
 void start_timer0(timer0_prescalers prescaler)

{

	TIMER0_CONTROL_REG=TIMER0_CONTROL_REG|prescaler;

}
void enable_time0_interrupt()

{

	SET_BIT(TIMER0_INTERRUPT_MASK_REG,0);

}


void disable_time0_interrupt()

{

  CLEAR_BIT(TIMER0_INTERRUPT_MASK_REG,0);

}


void enable_time0_CTC_interrupt()

{

	SET_BIT(TIMER0_INTERRUPT_MASK_REG,1);

}

void disable_time0_CTC_interrupt()

{

	CLEAR_BIT(TIMER0_INTERRUPT_MASK_REG,1);

}



void select_timer0_mode(timer0_modes mode)

{

	TIMER0_CONTROL_REG=TIMER0_CONTROL_REG|mode;

}

void stop_timer0()

{

	TIMER0_CONTROL_REG|=timer0_stop;

}

