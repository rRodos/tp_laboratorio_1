/*
 * library.c
 *
 *  Created on: 24 sept. 2021
 *      Author: Juan
 */
#include "library.h"

void abrirMenu(void)
{
	int opcion;
	int respuesta;
	int x = 0;
	int y = 0;

	do
	{
		respuesta = utn_getNumero(&opcion, "Elija una opción\n1-Ingresar 1er Operando\n2-Ingresar 2do Operando\n3-Sumar\n4-Restar\n5-Dividir\n6-Multiplicar\n7-Factorial\n8-Salir\n ", "Error", 1, 8, 2);
		if(!respuesta)
		{
			switch(opcion)
			{
			case 1:
				utn_getNumero(&x, "Ingrese un numero: ", "Hubo un error, intentalo de nuevo.\n", INT_MIN, INT_MAX, 2);
				break;
			case 2:
				utn_getNumero(&y, "Ingrese un numero: ", "Hubo un error, intentalo de nuevo.\n", INT_MIN, INT_MAX, 2);
				break;
			case 3:
				sumaNumeros(x, y);
				break;
			case 4:
				restaNumeros(x, y);
				break;
			case 5:
				divisionNumeros(x, y);
				break;
			case 6:
				multiplicacionNumeros(x, y);
				break;
			case 7:
				factorialNumeros(x, y);
				break;
			}
		}
		printf("\nA = %d y B = %d\n", x, y);
	}while(opcion != 8);
}

/** \brief Inicializa el menú y pide el numero de opción a elegir por parte del usuario.
* \return void
*
*/

int utn_getNumero(int* pResultado, char* mensaje, char* errorMensaje, int minimo, int maximo, int reintentos)
{
	int ret;
	int num;
	while (reintentos>0)
	{
		printf(mensaje);
		if (scanf( "%d" ,&num)==1)
		{
			if (num<=maximo && num>=minimo)
			{
				break ;
			}
		}
		fflush(stdin);
		reintentos--;
		printf("Hubo un error, intentalo de nuevo.\n");
	}

	if (reintentos==0)
	{
		ret=-1;
	}
	else
	{
	ret=0;
	*pResultado = num;
	}
	return ret;
}

/** \brief Genera el menú y verifica que el usuario haya ingresado el tipo de dato correcto.
* \param pResultado será el espacio en memoria donde se guardará el dato ingresado si es valido.
* \param mensaje genera el menu
* \param errorMensaje da mensaje de error en caso de tipo de dato erroneo ingresado
* \param minimo & maximo establecen rango de posibilidad para la elección del usuario
* \param reintentos establece cantidad de intentos equivocados que puede haber.
* \return Retorna la validación de que el dato ingresado por el usuario sigue o no los parametros.
*
*/


void sumaNumeros(int a, int b)
{
	int resultado;
	resultado = a + b;
	printf("\nEl resultado de la suma es %d", resultado);
}
/** \brief Recibe los dos parametros ingresados por el usuario y los suma.
* \param resultado donde se guardara el valor de la suma entre los dos parametros ingresados
* \return void
*
*/

void restaNumeros(int a, int b)
{
	int resultado;
	resultado = a - b;
	printf("\nEl resultado de la resta es %d", resultado);
}
/** \brief Recibe los dos parametros ingresados por el usuario y los resta.
* \param resultado donde se guardara el valor de la resta entre los dos parametros ingresados
* \return void
*
*/

void divisionNumeros(int a, int b)
{
	if(a <= 0 || b <= 0)
	{
		printf("No se puede dividir por 0.");
	}
	else
	{
		int resultado;
		resultado = a / b;
		printf("\nEl resultado de la división es %d", resultado);
	}
}
/** \brief Recibe los dos parametros ingresados por el usuario y los divide.
* \param resultado donde se guardara el valor de la division entre los dos parametros ingresados
* \return void
*
*/

void multiplicacionNumeros(int a, int b)
{
	int resultado;
	resultado = a * b;
	printf("\nEl resultado de la multiplicación es %d", resultado);
}
/** \brief Recibe los dos parametros ingresados por el usuario y los multiplica.
* \param resultado donde se guardara el valor de la multiplicacion entre los dos parametros ingresados
* \return void
*
*/

void factorialNumeros(int a, int b)
{
	int factorialA, factorialB;
	factorialA = factorialDe(a);
	factorialB = factorialDe(b);
	printf("Factorial de A: %d y B: %d", factorialA, factorialB);
}
/** \brief Recibe los dos parametros ingresados por el usuario y saca sus factoriales.
* \param factorialA recibe el valor de factorial de "a"
* \param factorialB recibe el valor de factorial de "b"
* \return void
*
*/

int factorialDe(int numero)
{
	int respuesta;
	if(numero == 1)
	{
		return 1;
	}
		respuesta = numero * factorialDe(numero - 1);
		return respuesta;
}
/** \brief Recibe un entero y obtiene su factorial
* \param respuesta sera donde se guarde el factorial del numero llegado a la funcion por el argumento.
* \return retorna la respuesta.
*
*/
