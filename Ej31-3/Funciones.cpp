#include "Header1.h"


int cant_roots(int a, int b, int c) {
	/* 1-a) Realizar un programa que pida ingresar por teclado los coeficientes de un polinomio de grado 2 y que a travez
	 de una funcion imprima en pantalla cuantas raices reales tiene el polinomio
								int cant_roots(int a, int b, int c);
	# Se debe crear un archivo header.h donde se guardaran los prototipos de las funciones, includes y defines
	  a usar de ser necesarios
	# Se debe crear un archivo main.c donde se codificara el programa y un archivo funciones.c donde se guardaran
	  las funciones necesarias
	*/
	if((pow(b,2)-4*a*c)>0)
	{
		cout << "\nEl polinomio tiene 2 raices reales"<<endl;
	}
	else {
		cout << "\nEl poliomio no tiene raíces reales"<<endl;
	}
	return 0;
}

void value_roots(int a, int b, int c, int cant_roots, float *root1, float *root2) {
	/*	1-b) Realizar una funcion que calcule los valores de las raices en caso de existir de un polinomio de grado 2
				void value_roots(int a, int b, int c, int cant_roots, float *root1, float *root2);
		# El main debera solo imprimir las raices y el tipo
	*/

	*root1 =  ( - b + sqrt(pow(b, 2) - (4 * a) * c))/(2*a);
	*root2 =  ( - b - sqrt(pow(b, 2) - (4 * a) * c))/(2*a);
	
	cout << "\nX1 = " << *root1 << "\t X2 = " << *root2<<endl;
}

void imaginary_value_roots(int a, int b, int c, float* real_p, float* img_p) {
	/*1-c) Realizar una funcion que calcule las raices imaginarias de un polinomio de grado 2 si las tuviera
				void imaginary_value_roots(int a, int b, int c, float *real_p, float *img_p);
		# El main debera solo imprimir las raices y el tipo
	*/

	*real_p = -b / (2 * a);
	*img_p = (sqrt(-(pow(b, 2) - (4 * a) * c))) / (2 * a);

	cout << "\nX1 = " << *real_p << " + i * " << *img_p << endl;
	cout << "\nX2 = " << *real_p << " - i * " << *img_p << endl;

}

float value_depend(int a, int b, int c, int x) {
	/*1-d) Realizar una funcion que dado un polinomio de grado 2  y el valor de una variable independiente (x) calcule el valor
		de la variable dependiente (y) y la devuelva como parametro
			   float value_depend(int a, int b, int c, int x);
   */
	float y=0;
	y = a * pow(x, 2) + b * x + c;

	return y;
}

float value_independ(int a, int b, int c, int y) {
	/*1-e) Realizar una funcion que dado un polinomio de grado 2  y el valor de una variable dependiente(y) calcule el valor
	 de la variable independiente (x) y la devuelva como parametro
			float value_independ(int a, int b, int c, int y);
	*/
	
	float x=0;
	int c2 = c - y; // 0 = a*x^2 + b*x + c2

	if ((pow(b, 2) - 4 * a * c2) > 0)
	{
		// raices reales
		float val1 = 0, val2 = 0;
		value_roots(a, b, c2, 2, &val1, &val2); // 1-b)

		//retorno una de las dos raices
		x = val1;
	}
	else {
		//raices imaginarias
		float real_ = 0, img_ = 0;
		imaginary_value_roots(a, b, c2, &real_, &img_); //1-c)
		
		// retorno parte real
		x = real_;
		
	}
	return x;

}
