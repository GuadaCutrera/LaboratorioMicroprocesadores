// Ej14-4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include "Header.h"


int main()
{
	int16_t vector[10] = { 1,2,3,4,5,6,7,8,9,10 }, largo_vect = 10, multiplicacion=0, n1 = 500 ,n2 = -500;
	int32_t suma=0;
	// inciso a)
	suma = Sumar_Array( vector,largo_vect);
	cout << "Suma: " << suma << endl;
	// inciso b)
	multiplicacion = Multiplicar_Sat(n1,n2);
	cout << "\nMultiplicacion: " << multiplicacion << endl;
	// inciso c)
	cout << "\naccesos: " << Cuenta_Accesos() << endl;
	cout << "\naccesos: " << Cuenta_Accesos() << endl;

	// 

	return 0;
}

