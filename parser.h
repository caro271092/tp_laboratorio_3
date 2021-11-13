#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "LinkedList.h"
#include "Employee.h"
/// \fn int parser_EmployeeFromText(FILE*, LinkedList*)
/// \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
/// \param pFile puntero al archivo a parsear
/// \param pArrayListEmployee puntero a listado donde se guarda la información parseada
/// \return -1 si hubo algún problema, 0 si se parseo ok
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/// \fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
/// \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
/// \param pFile puntero al archivo a parsear
/// \param pArrayListEmployee puntero a listado donde se guarda la información parseada
/// \return -1 si hubo algún problema, 0 si se parseo ok
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
