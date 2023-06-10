/*
 * Aplicacion.h
 *
 *  Created on: 5 dic. 2019
 *      Author: Ramiro Palomeque
 */

#ifndef APLICACION_H_
#define APLICACION_H_
/*
	#include "Puertos_InfoII.h"
	#include "DR_GPIOs.h"
	#include "FW_Oscilador.h"
	#include "DR_Interrupciones.h"

	#include "DR_Expansion2.h"
	#include "DR_Expansion3.h"

	#include "DR_ADC.h"
	#include "DR_Teclado.h"
	#include "DR_Relays.h"
	#include "DR_RGB.h"
	#include "DR_UARTs.h"
	#include "DR_LCD.h"

	#include "DR_RTC.h"
	#include "DR_Systick.h"
	#include "DR_Timers.h"
	#include "PR_Temporizaciones.h"

	#include "PR_Strings.h"
*/

//!< ////////////////// PRIMITIVAS  GENERALES //////////////////////////////
 	 void Inicializar_KIT( void );
 	 void SysTick_Handler(void);

 	 void mde_blinky_init(void);
 	 void mde_blynky(void);

 	 void mde_freq_blinky_init( void );
 	 void mde_freq_blinky( void );

 	 //void mde_key_press_init(void);
 	 void mde_key_press(void);

 	 //void mde_key_status_init(void);
 	 void mde_key_status(void);


 	 // MANEJO DE BITS
     int32_t ApagarBit(uint32_t *var, uint8_t nBit);
     int32_t EncenderBit(uint32_t *var, uint8_t nBit);
     uint8_t ConsultarBit(uint32_t *var, uint8_t nBit);
     int32_t InvertirBit(uint32_t *var, uint8_t nBit);

 	 typedef enum{
 		 ON,
		 OFF
 	 }estados_blinky;

 	 typedef enum{
 		ms_100,
		ms_300,
		ms_500,
		ms_1000
 	 }estados_freq_blinky;

 	 typedef enum
 	 {
 		 REPOSO,
		 CAMBIO,
		 CHECK
 	 }estados_key_press;

 	 typedef enum
 	 {
 		 PULSADO,
		 SUELTO,
		 MANTENIDO
 	 }key_status;



//!< //////////////////  DEFINES GENERALES	 //////////////////////////////






#endif /* APLICACION_H_ */
