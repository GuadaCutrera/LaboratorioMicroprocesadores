//!< ////////////////// HEADERS //////////////////////////////
#include "Aplicacion.h"

//!< ////////////////// VARIABLES GLOBALES //////////////////////////////

//DIR DE MEMORIA DE REGISTROS DE CONFIGURACION PARA GPIO:

volatile uint32_t * PINSEL_1 		= (volatile uint32_t * )0x4002C004UL; 	// - configurar entrada como GPIO
volatile uint32_t * PINSEL_4 		= (volatile uint32_t * )0x4002c010UL;	// - configurar entrada como GPIO

volatile uint32_t * PINMODEO_OD_0	= (volatile uint32_t * )0x4002C068UL; 	// - configurar el modo electrico del pin
volatile uint32_t * PINMODEO_OD_2	= (volatile uint32_t * )0x4002c070UL;	// - configurar el modo electrico del pin

volatile uint32_t * FIODIR_0 		= (volatile uint32_t * )0x2009C000UL;	// - configurar si es entrada (0) o salida (1)
volatile uint32_t * FIODIR_2 		= (volatile uint32_t * )0x2009c040UL;	// - configurar si es entrada (0) o salida (1)

//DIR DE MEMORIA DE REGISTROS DE LECTURA/ESCRITURA DE LOS PINS:
volatile uint32_t * FIOPIN_0		= (volatile uint32_t * )0x2009C014UL;	// - configurar el estado del pin o leer el estado del pin
volatile uint32_t * FIOPIN_2		= (volatile uint32_t * )0x2009C054UL;	//


//!< ////////////////// VARIABLES EXTERNAS //////////////////////////////
	//extern volatile uint32_t SysTicks;
	volatile uint32_t SysTicks=0;
	volatile uint32_t cont_mantenido = 0; // cuenta los ms de rebote
	
	//LED
	volatile uint8_t 	timeout;
	volatile uint32_t	led_time;
	
	estados_blinky 		estados;
	estados_freq_blinky estados_freq;
	
	//KEY
	volatile KEYXpresso_value = 0;  //todo el tiempo se actualiza en check
	key_status 			key_stat;
	uint8_t flag_cambio_key=ON; //ON=hubo un cambio en la tecla, OFF=quedo presionada o suelta


//!< ////////////////// INICIALIZACION MDE //////////////////////////////
	 void mde_blinky_init(void)
	 {
		 RGB_LEDXpresso(FIOPIN_0,ON);
		 estados = ON;
		 timeout = 0;
		 return;
	 }

 	 void mde_freq_blinky_init( void ){

 		 estados_freq=ms_100;
 		 led_time=100;
 		 return;

 	 }

 //////////////////////INICIALIZAR PERIFERICOS///////////////
 	
 	 void Inicializar_KIT( void )
 	 {
 		 //LED
 		 // quiero PONER 00 bit 12 y 13 para el P0,22
 		 ApagarBit(PINSEL_1, 12);
 		 ApagarBit(PINSEL_1, 13);
 		 // quiero PONER 0 el bit 22 para el P0,22
 		 ApagarBit(PINMODEO_OD_0, 22);
 		 // quiero PONER 1 el bit 22 para el P0,22
 		 EncenderBit(FIODIR_0,22);
 		 // quiero PONER 1(OFF)/0(ON) el bit 22 para el P0,22
 		InvertirBit(FIOPIN_0,22);
 		 
 		 
 		 //KEY
 		 // quiero PONER 00 bit 20 y 21 para el P2,10
		 ApagarBit(PINSEL_4, 20);
		 ApagarBit(PINSEL_4, 21);
 		 // quiero PONER 0 el bit 22 para el P2,10
 		 ApagarBit(PINMODEO_OD_2, 22);
 		 // quiero PONER 0 el bit 10 para el P2,10
 		 ApagarBit(FIODIR_2, 10);
 		 // quiero LEER el estado del pin P2,10
 		 ConsultarBit(FIOPIN_2, 10);


 	 }
 	/////////////////// SYSTICKS ///////////////////////////
 	void SysTick_Handler(void)
 	{
 			SysTicks++;
 			
 			if(SysTicks>=led_time)
 			{
 				timeout=1;
 				SysTicks=0;

 			}
 			
 			mde_key_press();
	        mde_key_status(); 
 			return;
 	}
 

 	// -------------------MANEJO DE BITS -------------------------------------------
 	int32_t ApagarBit(uint32_t *var, uint8_t nBit)
 	{
 	    // Forzar el bit nBit a 0
 	    *var = *var & (~(0x01 << nBit));
 	    return ConsultarBit(var,nBit);
 	}
 	int32_t EncenderBit(uint32_t *var, uint8_t nBit)
 	{
 	    // Forzar el bit nBit a 1
 	    *var = *var | (0x01 << nBit);
 	    return ConsultarBit(var,nBit);
 	}
 	uint8_t ConsultarBit(uint32_t *var, uint8_t nBit)
 	{
 	    // Para consultar uso un AND: fuerzo todos los bits a 0 excepto el nBit
 	    if( (*var & (0x01<<nBit)) == 0)
 	    {
 	        //si el resultado es 0, el bit consultado era 0.
 	        return 0;
 	    } else {
 	        // si el resultado es 1, el bit consultado era 1
 	        return 1;
 	    }
 	}
 	int32_t InvertirBit(uint32_t *var, uint8_t nBit)
 	{
 	    // Para invertir uso un XOR:
 	        //si el resultado es 0, el nBit era 1.
 	        // si el resultado es 1, el nBit era 0
 	    *var = *var ^ (0x01 << nBit);
 	    return ConsultarBit(var,nBit);
 	}

    uint8_t GetPIN(uint32_t * pin)
    {   uint8_t pin;
        pin=ConsultarBit(pin, 10);
        return pin;
    }
    
    void RGB_LEDXpresso(uint32_t * pin,uint8_t modo)
    {
        if(modo==ON)
        {
            EncenderBit(pin,22);
        }
        else
        {
            ApagarBit(pin,22);
        }
        return;
    }
    
 	//!< //////////////////  MDE //////////////////////////////
	 void mde_freq_blinky( void )
	 {
		 switch(estados_freq)
		 {
		 	 case ms_100:
		 		 if(GetPIN(FIOPIN_2)==1)
		 		 {
					 estados_freq=ms_300;
					 led_time=300;
		 		 }
		 		 break;
		 	 case ms_300:
		 		 if(GetPIN(FIOPIN_2)==1)
				 {
		 			 estados_freq=ms_500;
		 			 led_time=500;
				 }
		 		break;
		 	 case ms_500:
		 		if(GetPIN(FIOPIN_2)==1)
		 		{
					 estados_freq=ms_1000;
					 led_time=1000;
		 		}
		 		 break;
		 	 case ms_1000:
		 		if(GetPIN(FIOPIN_2)==1)
		 		{
					 estados_freq=ms_100;
					 led_time=100;
		 		}
		 		 break;
		 	 default:
		 		 mde_freq_blinky_init();
		 		 break;
		 }

		 return;
	 }

	 void mde_blynky(void)
	 {
		 switch (estados)
		 {
		 	 case ON:
		 		 if(timeout==1)
		 		 {
		 			 RGB_LEDXpresso(FIOPIN_0, OFF);
		 			 estados = OFF;
		 			 timeout = 0;
		 		 }
		 		 break;
		 	 case OFF:
		 		 if(timeout==1)
		 		 {
		 			 RGB_LEDXpresso(FIOPIN_0, ON);
		 			 estados = ON;
		 			 timeout = 0;
		 		 }
		 		 break;
		 	 default:
		 		mde_blinky_init();
		 		 break;
		 }

		 return;

	 }

	 void mde_key_press(void)
	 { 		
		 static uint_32    				edo_keyViejo;
		 uint_32    	 				edo_keyActual;
		 static estados_key_press	    estado_key=REPOSO;
		 edo_keyActual = GetPIN(FIOPIN_2);
		 static uint_8 cont_key=0; // cuantas veces la tecla estuvo en el mismo estado
	 
		 switch (estado_key)
		 {
			 case REPOSO:
			 	 if(edo_keyActual!=edo_keyViejo)
			 	 {
			 		estado_key=CAMBIO;
			 		edo_keyViejo=edo_keyActual;
			 	 }		 
				 break;
				 
			 case CAMBIO:
			 	 // si no volvio a cambiar la posicion del boton va a check
			 	 	if(edo_keyActual==edo_keyViejo)
			 	 	{
						estado_key=CHECK;
					}
			 	 	edo_keyViejo=edo_keyActual;
				 	 
				 break;

			 case CHECK:
			 
			 	 if(edo_keyActual!=edo_keyViejo)
			 	 {	// si volvio a cambiar la posicion del boton
			 		 estado_key=CAMBIO;
			 		 edo_keyViejo=edo_keyActual;
			 	 }
			 	 else 
			 	 {	//el boton se quedo en la misma posicion 5 veces
			 		if (cont_key==5) //si se quedo 5 veces dentro del mismo estado
			 		{
			 			KEYXpresso_value=edo_keyActual; // se setea la posicion del boton (pulsado o suelto)
			 			edo_keyViejo=edo_keyActual;
			 			estado_key= REPOSO;
			 			cont_key=0;
			 		}
			 		else 
			 		{
			 			cont_key++;
			 		}
			 	 }
			 
			 	 break;
			 default:
	 			estado_key = REPOSO;
			 break;
		 }
		 
		 return;
		 
	 }

	 void mde_key_status(void)
	 {
		 
		 switch(key_stat)
		 {
		 	 case SUELTO:
		 		 if(KEYXpresso_value==0)
				 {
				     if(flag_cambio_key==ON)
				     {
    				     key_stat= MANTENIDO;
    				     cont_mantenido=0;
				     }
				 }
				 else
				 {
				     key_stat= PULSADO;
				     flag_cambio_key=ON;
				 }
		 		 break;
		 	 case PULSADO:
		 		if(KEYXpresso_value==1)
				 {
				     if(flag_cambio_key==ON) // en OFF implica que no la tecla estuvo en reposo
				     {
				        key_stat= MANTENIDO;
				        cont_mantenido=0;
				     }
				     
				 }
				 else
				 {
				     key_stat= SUELTO;
				     flag_cambio_key=ON;
				 }
				 
		 		 break;
		 	 case MANTENIDO:
		 		 
		 		if(cont_mantenido<=key_time)
		 		{
		 		    if(KEYXpresso_value==1)
		 		    {
		 		        key_stat=PULSADO;
		 		        flag_cambio_key=OFF;
		 		    }
		 		    else
		 		    {
		 		        key_stat=SUELTO;
		 		        flag_cambio_key=OFF;
		 		    }
		 		}
		 		else 
		 		{
		 		    cont_mantenido++;
		 		}
		 		
		 		
		 		 break;
		 	 default:
		 		 key_stat=MANTENIDO;


		 }
	 }



		 }
	 }
