#ifndef APLICACION_H_
#define APLICACION_H_

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

    //otras funciones
    uint8_t GetPIN();
    void RGB_LEDXpresso(uint8_t nBit,uint8_t modo);


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

    #define key_time 500 // 500 ms
    #define OFF 0
    #define ON 1




#endif /* APLICACION_H_ */
