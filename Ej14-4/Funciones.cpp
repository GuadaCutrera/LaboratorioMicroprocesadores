#include "Header.h"

int16_t Cont_accesos = 0; // se incrementa en la funcion de cuenta accesos

/* 1) Realizar una función que me permita realizar la sumatoria de un array de enteros con signo
de 16 bits y devuelva un entero de 32 bits. Debe recibir la dirección del array a sumar y su
largo */
int32_t Sumar_Array(int16_t* x, int16_t xn)
{
	int32_t cont = 0;
	for (int i = 0; i<xn; i++ ) {
		cont += (int32_t)x[i];
	}
	return cont;
}

/*Agregar al archivo anterior una función que me permita realizar la multiplicación de dos enteros de 16 bits con signo saturando el resultado a 16 bits. 
La función recibe los dos números a multiplicar y devuelve el resultado de la multiplicación saturado. 
Guardar los valores máximos y mínimos a saturar en dos constantes llamadas SAT16_MAX y SAT16_MIN.*/
int16_t Multiplicar_Sat(int16_t n1, int16_t n2) {
	int16_t multiplicacion = 0;
	char flag = 'p'; // las flags indican si los numeros son positivos o negativos
	if ((n1 < 0 && n2 < 0) || (n1 > 0 && n2 > 0))
	{
		flag = 'p';
	}
	else
	{
		flag = 'n';
	}

	multiplicacion = n1 * n2;

	if ((flag == 'p' && multiplicacion < 0)  ) {
		
		multiplicacion = SAT16_MAX;
	
	}
	else if (flag == 'n' && multiplicacion > 0) {
		multiplicacion = SAT16_MIN;
	}
	Cont_accesos = Cuenta_Accesos();
	return multiplicacion;

}

/* 5) Agregar una función que devuelva un entero sin signo de 16 bits que me permita contar la
cantidad de veces que fue llamada la misma. Comprobar el lugar de memoria que ocupan cada
una de las variables creadas en el mapa general */
uint16_t Cuenta_Accesos(void) {
	static uint16_t cont_acc = 0;
	cont_acc++;
	return cont_acc;
}
