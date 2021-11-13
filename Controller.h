#ifndef __CONTROLLER_H_
#define __CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "LinkedList.h"
#include "Employee.h"
#include "InputOutput.h"
#include "parser.h"
/// \fn int controller_loadFromText(char*, LinkedList*)
/// \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
/// \param path nombre del archivo o ruta hacia él en caso que no esté en la misma carpeta de ejecucion del programa
/// \param pArrayListEmployee array de empleados (puntero al inicio)
/// \return -1 si no logró la acción, 0 si ok
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/// \fn int controller_loadFromBinary(char*, LinkedList*)
/// \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
/// \param path nombre del archivo o ruta hacia él en caso que no esté en la misma carpeta de ejecucion del programa
/// \param pArrayListEmployee array de empleados
/// \return -1 si no logró la acción, 0 si ok
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/// \fn int controller_addEmployee(LinkedList*)
/// \brief agrega un empleado al listado
/// \param pArrayListEmployee array de empleados
/// \return -1 si no logró la acción, 0 si ok
int controller_addEmployee(LinkedList* pArrayListEmployee);
/// \fn int controller_editEmployee(LinkedList*)
/// \brief modifica datos de empleado
/// \param pArrayListEmployee array de empleados
/// \return -1 si no logró la acción, 0 si ok
int controller_editEmployee(LinkedList* pArrayListEmployee);
/// \fn int controller_removeEmployee(LinkedList*)
/// \brief remueve un empleado del array
/// \param pArrayListEmployee array de empleados
/// \return -1 si no logró la acción, 0 si ok
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/// \fn int controller_ListEmployee(LinkedList*)
/// \brief muestra un listado de los empleados
/// \param pArrayListEmployee array de empleados a mostrar
/// \return -1 si no logró listar, 0 ok
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/// \fn int controller_sortEmployee(LinkedList*)
/// \brief ordenar empleados
/// \param pArrayListEmployee listado de empleados
/// \return 0 si se ordenó segun algun criterio, -1 si no se pudo ordenar
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/// \fn int controller_saveAsText(char*, LinkedList*)
/// \brief Guarda los datos de los empleados en el archivo data.csv (modo texto)
/// \param path archivo
/// \param pArrayListEmployee listado de empleados
/// \return -1 si algo salió mal, 0 si ok
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/// \fn int controller_saveAsBinary(char*, LinkedList*)
/// \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
/// \param path archivo
/// \param pArrayListEmployee listado de empleados
/// \return -1 si algo salió mal, 0 si ok
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/// \fn int GetIndexById(LinkedList*, int)
/// \brief mediante el id del dato, devuelve su posicion en la lista
/// \param pArrayListEmployee lista de empleados
/// \param idIngresado id a encontrar
/// \return -1 si el id ingresado no coincide con ninguno del listado, index si coincide
int GetIndexById(LinkedList* pArrayListEmployee,int idIngresado);
#endif
