#include "parser.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
	int retorno =-1;
	char id[11];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];
	Employee* newEmployee;
	if(pFile!=NULL && pArrayListEmployee!=NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
		while(!feof(pFile)){//mientras no sea el final del archivo
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
			newEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);//construir el empleado convertir de fila de excel a estructura
			if(newEmployee!=NULL){
				ll_add(pArrayListEmployee, newEmployee);//agregar a linked list(es como el array pero en memoria dinámica)
				retorno=0;
			}
		}
	}
    return retorno;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
	int retorno=-1;
	int retornoFRead;
	Employee* auxEmployee;
	if(pFile!=NULL && pArrayListEmployee!=NULL){
		while(!feof(pFile)){
			auxEmployee = employee_new();
			retornoFRead = fread(auxEmployee,sizeof(Employee),1,pFile);//se guardan datos de 1 empleado
			if(retornoFRead==1 && auxEmployee!=NULL){//retorna ctidad de datos leidos, si es menor a lo pedido=>error
					ll_add(pArrayListEmployee,auxEmployee);
					retorno = 0;
				}
			}
		}
	return retorno;
}
