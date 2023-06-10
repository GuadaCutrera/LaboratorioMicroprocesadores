/*
===============================================================================
 Name        : LPC_1769_2019.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif


//!< ////////////////// HEADERS //////////////////////////////
#include <cr_section_macros.h>
#include "Aplicacion.h"

//!< ////////////////// VARIABLES GLOBALES //////////////////////////////


//!< ////////////////// VARIABLES EXTERNAS //////////////////////////////
	extern volatile uint32_t SysTicks;


	int main(void) {


		Inicializar_KIT();
		// MDE
		mde_freq_blinky_init();
		mde_blinky_init();
		//uint8_t Key_value;
		//mde_key_press_init();


		while(1)
		{
			mde_key_press();
			mde_key_status();

			mde_freq_blinky();
			mde_blynky();



		}
		return 0 ;
	}



