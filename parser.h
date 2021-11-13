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
/// \brief
///
/// \param pFile
/// \param pArrayListEmployee
/// \return
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/// \fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
/// \brief
///
/// \param pFile
/// \param pArrayListEmployee
/// \return
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
