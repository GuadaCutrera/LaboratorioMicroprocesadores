// Ej31-3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

/*Hacer un programa con menu que pida ingresar por teclado los 3 coeficientes del polinomio y lo que quiere calcular
        'a' - Cantidad de racies
        'b' - Valor de racies (cuales sean)
        'c' - Valor del polinomio en x
        'd' - Valor del polinomio en y
    # El programa debe estar dentro de un loop infinito que se cortara solo si el usuario ingresa '0' o una opcion no
      valida e informara porque se cerro.
*/

#include <iostream>

#include "Header1.h"
#include "Funciones.cpp"

using namespace std;

int main()
{
    char flag_usuario = 'F',op_usuario=' '; // Variables para el menu
    //int a = 1, b = -5, c = 6; //Raices Reales
    int a = 1, b = 2, c = 3; // Raices Img

    do
    {
        cout << "\nMENU: \nElija una de las siguientes opciones:";
        cout << "\n'a' - Cantidad de racies. \n'b' - Valor de racies(cuales sean). \n'c' - Valor del polinomio en x. \n'd' - Valor del polinomio en y. \nPara salir del menu presione otra opcion."<<endl;
        cout << "Opcion: ";
        cin >> op_usuario;

        // para value_depend
        int x1 = 4;
        float y1 = 0;

        //para value_independ
        int y2 = 4;
        float x2 = 0;

        switch (op_usuario) {

        case 'a':
            flag_usuario = 'V';
            // incisos a, b y c
            cant_roots(a, b, c);
            break;
        case 'b':
            flag_usuario = 'V';
            if ((pow(b, 2) - 4 * a * c) > 0)
            {
                float root1 = 0, root2 = 0;
                value_roots(a, b, c, 2, &root1, &root2); // 1-b)
            }
            else {
                float real_p = 0, img_p = 0;
                imaginary_value_roots(a, b, c, &real_p, &img_p); //1-c)
            }
            break;
        case 'c':
            flag_usuario = 'V';
            // inciso d
            y1 = value_depend(a, b, c, x1);
            cout << "\nEl polinomio y = " << a << " * x^2 + " << b << " * x + " << c << ", en x = " << x1 << ", es y = " << y1 << endl;
            break;
        case 'd':
            flag_usuario = 'V';
            // inciso e
            x2 = value_independ(a, b, c, y2);
            cout << "\nEl polinomio y = " << a << " * x^2 + " << b << " * x + " << c-y2  << ", en y = " << y2 << ", es x = " << x2 << endl;
            break;
        default:
            flag_usuario = 'F';
            break;
        }

    } while (flag_usuario=='V');

    _getch();

    return 0;
}
