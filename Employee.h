#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void employee_delete();
int employee_sortByID(void* this1, void* this2);
int employee_sortByName(void* thisA, void* thisB);
int employee_sortBySueldo(void* thisA, void* thisB);
int employee_sortByHorasTrabajadas(void* thisA, void* thisB);

#endif // employee_H_INCLUDED
