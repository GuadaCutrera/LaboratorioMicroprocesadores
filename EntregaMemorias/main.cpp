/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "Header.h"

extern char edata, etext, end;
int32_t varGlobal; //Variable Global ej 2
int32_t varGlobal_2 = 34; //Variable Global ej 3



int main ()
{
  // -----------------------MANEJO DE MEMORIAS ---------------------------------
  // 1)
  printf ("La dirección de etext: %p\n", &etext);
  
  int32_t a=0, b=0;
  std::cout << "Ingrese dos numeros: "<<std::endl;
  std::cin >> a >> b;
  std::cout << "La suma de "<<a<<" + "<<b<<" = "<<Suma(a, b)<< std::endl;

  int32_t (*dir_suma) (int32_t, int32_t) = Suma; // apunto a Suma
  printf ("La dirección de Suma: %p\n", dir_suma);
  printf("La dirección del Main: %p\n",&main);
  
  // 2)
  printf ("La dirección de edata: %p\n", &edata);
  int32_t varLocal;
  printf ("La dirección de varLocal: %p\n", &varLocal);
  printf ("La dirección de varGlobal: %p\n", &varGlobal);

  // 3)
  printf ("La dirección de end: %p\n", &end);
  printf ("La dirección de varGlobal_2: %p\n", &varGlobal_2);
  
  return 0;
}
