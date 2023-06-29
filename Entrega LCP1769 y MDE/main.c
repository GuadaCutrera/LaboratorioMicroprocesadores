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
		
			mde_freq_blinky();
			mde_blynky();
		}
		return 0 ;
	}



