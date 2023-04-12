#pragma once
// Includes
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

// Definicion de funciones
int cant_roots(int a, int b, int c);
void value_roots(int a, int b, int c, int cant_roots, float* root1, float* root2);
void imaginary_value_roots(int a, int b, int c, float* real_p, float* img_p);
float value_depend(int a, int b, int c, int x);
float value_independ(int a, int b, int c, int y);