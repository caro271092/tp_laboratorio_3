/* InputOutput.h  */
#ifndef INPUTOUTPUT_H_
#define INPUTOUTPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "Employee.h"
#include "LinkedList.h"
/// \fn int ValidacionIngresoDeUnEnteroPositivo(char[])
/// \brief valida que el ingreso sea un n�mero entero positivo
/// \param ingreso ingreso recibido como cadena de caracteres
/// \return 0 si el ingreso es un entero positivo, -1 si no lo es
int ValidacionIngresoDeUnEnteroPositivo(char ingreso[]);

/// \fn int PedirNumeroEntero(int*, char[], char[], int, int, int)
/// \brief solicita al usuario un n�mero entero positivo dentro de un rango
/// \param ingresoValidado devuelve por par�metro el ingreso si es v�lido
/// \param mensaje mensaje para pedir el ingreso
/// \param mensajeError mensaje si el ingreso no es un entero positivo dentro del rango
/// \param minimo m�nimo valor aceptado del ingreso
/// \param maximo mayor valor aceptado del ingreso
/// \param reintentos cantidad de veces que se vuelve a pedir el ingreso en caso de no ser v�lido
/// \return 0 ok, -1 si el ingreso es inv�lido
int PedirNumeroEntero(int* ingresoValidado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

/// \fn int ValidacionIngresoDeUnFlotantePositivo(char[])
/// \brief valida que el ingreso sea un n�mero flotante positivo
/// \param ingreso ingreso recibido como cadena de caracteres
/// \return 0 si el ingreso es un fotante positivo, -1 si no lo es
int ValidacionIngresoDeUnFlotantePositivo(char ingreso[]);

/// \fn int PedirNumeroFlotante(float*, char[], char[], float, float, int)
/// \brief solicita al usuario un n�mero flotante positivo dentro de un rango
/// \param ingresoValidado devuelve por par�metro el ingreso si es v�lido
/// \param mensaje mensaje para pedir el ingreso
/// \param mensajeError mensaje si el ingreso no es un entero positivo dentro del rango
/// \param minimo m�nimo valor aceptado del ingreso
/// \param maximo mayor valor aceptado del ingreso
/// \param reintentos cantidad de veces que se vuelve a pedir el ingreso en caso de no ser v�lido
/// \return 0 ok, -1 si el ingreso es inv�lido
int PedirNumeroFlotante(float* ingresoValidado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);

/// \fn int GetString(char[], char[], int)
/// \brief solicita una cadena de caracteres
/// \param string cadena validada devuelta por par�metro
/// \param message mensaje para solicitar el ingreso
/// \param len largo de la cadena
/// \return
int GetString(char string[], char message[], int len);

/// \fn float ValidacionFloatDentroDeUnRango(float, int, int)
/// \brief valida que el float recibido est� dentro de un rango determinado, sino lo vuelve a pedir
/// \param ingreso valor ingresado
/// \param minimo m�nimo valor aceptado para validar
/// \param maximo m�ximo valor aceptado para validar
/// \return valor validado
float ValidacionFloatDentroDeUnRango(float ingreso, int minimo, int maximo);

/// \fn int ValidacionEnteroDentroDeUnRango(int, int, int)
/// \brief valida que el entero recibido est� dentro de un rango determinado, sino lo vuelve a pedir
/// \param ingreso valor ingresado
/// \param minimo m�nimo valor aceptado para validar
/// \param maximo m�ximo valor aceptado para validar
/// \return valor validado
int ValidacionEnteroDentroDeUnRango(int ingreso,int minimo,int maximo);

/// \fn char ToUpperFirstLetter*(char[])
/// \brief cambia a may�scula la primer letra de la cadena recibida
/// \param cadena cadena recibida
/// \return cadena con primer caracter en may�scula
char* ToUpperFirstLetter(char cadena[]);

/// \fn int PedirNumeroEnteroVersionCorta(char[])
/// \brief valida que el valor recibido sea un entero positivo y lo retorna
/// \param mensaje mensaje para pedir el valor
/// \return valor validado
int PedirNumeroEnteroVersionCorta(char mensaje[]);

/// \fn float PedirNumeroFlotanteVersionCorta(char[])
/// \brief valida que el valor recibido sea un float positivo y lo retorna
/// \param mensaje mensaje para pedir el valor
/// \return valor validado
float PedirNumeroFlotanteVersionCorta(char mensaje[]);

/// \fn void mostrarMenu()
/// \brief imprime el men� de opciones
void mostrarMenu();

/// \fn int cargaMayorIdEnArchivoID(LinkedList*)
/// \brief guarda en un archivo el mayor id registrado en la lista cargada
/// \param pArrayListEmployee
/// \return 0 si pudo guardar, -1 si hubo un error
int cargaMayorIdEnArchivoID(LinkedList* pArrayListEmployee);

/// \fn int generadorID()
/// \brief tomando el mayor id del archivo de la f anterior, genera el siguiente id
/// \return nuevo id, siguiente al �ltimo guardado en el archivo de ids
int generadorID();

/// \fn void menuModificaciones()
/// \brief imprime un menu que se utiliza en f para modificar
void menuModificaciones();

/// \fn void menuCriterioOrdenamiento()
/// \brief imprime un men�
void menuCriterioOrdenamiento();

#endif /* INPUTOUTPUT_H_ */
