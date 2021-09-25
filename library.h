/*
 * library.h
 *
 *  Created on: 24 sept. 2021
 *      Author: Juan Rodríguez Peluffo
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void sumaNumeros(int a, int b);

void restaNumeros(int a, int b);

void divisionNumeros(int a, int b);

void multiplicacionNumeros(int a, int b);

void factorialNumeros(int a, int b);

int factorialDe(int numero);

int utn_getNumero(int* pResultado, char* mensaje, char* errorMensaje, int minimo, int maximo, int reintentos);

void abrirMenu(void);

#endif /* LIBRARY_H_ */
