#pragma once
#ifndef __Header_h
	#define __Header_h // define el header
	
	// incluye librerías
	using namespace std;
	#include <iostream>
	#define  SAT16_MAX 32757 
	#define SAT16_MIN -32768 
	//#include <stdlib>
	
	// prototipós de funciones
	int32_t Sumar_Array(int16_t* x, int16_t xn);
	int16_t Multiplicar_Sat(int16_t n1, int16_t n2);
	uint16_t Cuenta_Accesos(void);

#endif