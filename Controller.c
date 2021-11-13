#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
	int retorno = -1;
	FILE* pFile=NULL;
	int parser;
	if(path!=NULL && pArrayListEmployee!=NULL){
		pFile = fopen(path,"r"); //
		if(pFile != NULL){
			parser = parser_EmployeeFromText(pFile,pArrayListEmployee);//para parsear a estructura
			if(parser==0){
				retorno=0;
				fflush(pFile);
				fclose(pFile);
			}
		}else{
			printf("\n--->No se pudo leer el archivo.");
		}
	}
	return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
	int retorno= -1;
	FILE* pFile=NULL;
	int parser;
	pFile = fopen(path,"rb");
	if(pFile != NULL && pArrayListEmployee!=NULL){
		parser = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
		if(parser==0){
			retorno=0;
			fclose(pFile);
		}
	}else{
		printf("\n--->Error.");
	}
	return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee){
	int retorno=-1;
	Employee* auxEmployee;
	auxEmployee= employee_new();
	int auxId;
	int auxSueldo;
	char auxNombre[128];
	int auxHoras;
		if(pArrayListEmployee!=NULL && auxEmployee!=NULL){
			GetString(auxNombre,"\n-->Ingrese el nombre del empleado: ",128);
			ToUpperFirstLetter(auxNombre);
			employee_setNombre(auxEmployee,auxNombre);
			PedirNumeroEntero(&auxHoras,"\n-->Ingrese las horas de trabajo del empleado: ", "-->Error.", 1,600,2);
			employee_setHorasTrabajadas(auxEmployee,auxHoras);
			PedirNumeroEntero(&auxSueldo,"\n-->Ingrese el sueldo del empleado: ", "-->Error.",1000,3000000,2);
			employee_setSueldo(auxEmployee,auxSueldo);
			auxId=generadorID();
				if(auxId!=-1){
				employee_setId(auxEmployee,auxId);
				}else{
				printf("\nError al generar ID\n");
				}
			ll_add(pArrayListEmployee,auxEmployee);
			retorno=0;
			printf("\n-->El empleado se cargó exitosamente\n\n");
		}else{
			employee_delete(auxEmployee);
			auxEmployee=NULL;
			printf("\n-->No se pudo cargar correctamente el empleado\n\n");
		}
	    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee){
	int retorno=-1;
	Employee* auxEmployee;
	int index;
	int idIngresado;
	int opcionIngresada;
	char newName[50];
	int newHoras;
	int newSueldo;
	if(pArrayListEmployee!=NULL){
		controller_ListEmployee(pArrayListEmployee);
		PedirNumeroEntero(&idIngresado, "\n--->Ingrese el Id. del empleado que desea modificar: \n", "--->ERROR.", 1, INT_MAX,2);
		index = GetIndexById(pArrayListEmployee, idIngresado);
		if(index!=-1){
		auxEmployee = ll_get(pArrayListEmployee,index);
			if(auxEmployee!=NULL){
				menuModificaciones();
				PedirNumeroEntero(&opcionIngresada,"\n--->Ingrese la opción que desea ejecutar: \n","---> ERROR. Ingrese una opción válida.", 1, 4, 2);
				switch(opcionIngresada){
				case 1:
					GetString(newName, "\nIngrese el nuevo nombre: \n", 51);
					ToUpperFirstLetter(newName);
					employee_setNombre(auxEmployee,newName);
					if(ll_set(pArrayListEmployee,index,auxEmployee)==0){
						printf("\n-->El empleado se modificó exitosamente\n\n");
					}
					break;
				case 2:
					PedirNumeroEntero(&newHoras, "\nIngrese las horas trabajadas del empleado: \n", "-->ERROR.", 1, 1000,2);
					employee_setHorasTrabajadas(auxEmployee,newHoras);
					if(ll_set(pArrayListEmployee,index,auxEmployee)==0){
						printf("\n-->El empleado se modificó exitosamente\n\n");
					}
					break;
				case 3:
					PedirNumeroEntero(&newSueldo,"\nIngrese el nuevo sueldo del empleado: \n","-->ERROR.",1,1000000,2);
					employee_setSueldo(auxEmployee,newSueldo);
					if(ll_set(pArrayListEmployee,index,auxEmployee)==0){
						printf("\n-->El empleado se modificó exitosamente\n\n");
					}
					break;
				case 4:
					printf("\n-->Se canceló la modificación\n");
					break;
				}
				retorno = 0;
			}else{
				printf("\n-->El ID ingresado es incorrecto\n");
			}
		}
	}
	return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee){
	int retorno=-1;
	int idIngresado;
	int index;
	char confirmacion;
	controller_ListEmployee(pArrayListEmployee);
	PedirNumeroEntero(&idIngresado, "--->Ingrese el Id. del empleado que desea dar de baja: ", "--->ERROR.", 1, INT_MAX,2);
	index = GetIndexById(pArrayListEmployee, idIngresado);
	if(index!=-1){
		printf("--->Ingrese s para confirmar la baja: ");
		fflush(stdin);
		scanf("%c", &confirmacion);
			if(confirmacion=='s'){
				ll_remove(pArrayListEmployee,index);
				printf("\n-->El empleado se dió de baja exitosamente\n\n");
			}else{
				printf("\n-->Se canceló la baja\n\n");
			}
	}else{
	    printf("\n-->El ID ingresado no existe en la base de datos\n");
	}
    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee){
	int retorno =-1;
	int i;
	Employee* pEmployee;
	int id;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;
	int tamLinkedList;
	tamLinkedList = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL){
		for(i=0;i<tamLinkedList;i++){
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmployee,&id);
			employee_getNombre(pEmployee,nombre);
			employee_getHorasTrabajadas(pEmployee,&horasTrabajadas);
			employee_getSueldo(pEmployee,&sueldo);
			printf("%-10d %-20s %-20d %10d\n", id, nombre, horasTrabajadas, sueldo);
		}
		retorno =0;
	}
    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int retorno=-1;
    int criterio;
    int criterio2;
    if(pArrayListEmployee!=NULL){
	menuCriterioOrdenamiento();
	PedirNumeroEntero(&criterio,"\n--->Ingrese el criterio de ordenamiento: ","---> ERROR. Ingrese una opción válida.", 1, 4, 2);
	PedirNumeroEntero(&criterio2,"\n--->Ingrese 1 para ordenar de forma ascendente y 0 para ordenar descendentemente: ","---> ERROR. Ingrese una opción válida.", 0, 1, 2);
		switch(criterio){
			case 1:
				if(criterio2== 1){
					ll_sort(pArrayListEmployee,employee_sortByID, 1);
					printf("-->La lista se ordenó exitosamente\n\n");
				}else{
					ll_sort(pArrayListEmployee,employee_sortByID,0);
					printf("-->La lista se ordenó exitosamente\n\n");
				}
			break;
			case 2:
				if(criterio2== 1){
					ll_sort(pArrayListEmployee, employee_sortByName, 1);
					printf("\n-->La lista se ordenó exitosamente\n\n");
				}else{
					ll_sort(pArrayListEmployee, employee_sortByName, 0);
					printf("\n-->La lista se ordenó exitosamente\n\n");
				}
			break;
			case 3:
				if(criterio2== 1){
					ll_sort(pArrayListEmployee,employee_sortByHorasTrabajadas, 1);
					printf("\n-->La lista se ordenó exitosamente\n\n");
				}else{
					ll_sort(pArrayListEmployee,employee_sortByHorasTrabajadas, 0);
					printf("\n-->La lista se ordenó exitosamente\n\n");
				}
			break;
			case 4:
				if(criterio2== 1){
					ll_sort(pArrayListEmployee,employee_sortBySueldo, 1);
					printf("\n-->La lista se ordenó exitosamente\n\n");
				}else{
					ll_sort(pArrayListEmployee,employee_sortBySueldo, 0);
					printf("\n-->La lista se ordenó exitosamente\n\n");
				}
			break;
		}
		retorno = 0;
	}
	return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
	int retorno =-1;
	FILE* pFile;
	int i;
	int lenLinkedList;
	int id;
	char nombre[128];
	int horas;
	int sueldo;
	Employee* auxEmployee;
	lenLinkedList = ll_len(pArrayListEmployee);
	pFile = fopen(path,"w");
	if(pFile!=NULL && pArrayListEmployee!=NULL){
		for(i=0;i<lenLinkedList;i++){
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(auxEmployee, &id);
			employee_getNombre(auxEmployee,nombre);
			employee_getHorasTrabajadas(auxEmployee,&horas);
			employee_getSueldo(auxEmployee,&sueldo);
			fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);
		}
		retorno=0;
		fflush(pFile);
		fclose(pFile);
	}
	return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
	int retorno =-1;
	FILE* pFile;
	int i;
	int lenLinkedList;
	Employee* auxEmployee;
	lenLinkedList = ll_len(pArrayListEmployee);
	pFile = fopen(path,"wb");
	if(pFile!=NULL && pArrayListEmployee!=NULL){
		for(i=0;i<lenLinkedList;i++){
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			fwrite(auxEmployee,sizeof(Employee),1,pFile);
/*fwrite se escribe en binario,
 * por lo que el espacio ocupado por los datos escritos se determina de acuerdo con el tipo de datos
*/
		}
		retorno=0;
		fflush(pFile);
		fclose(pFile);
	}
	return retorno;
}

int GetIndexById(LinkedList* pArrayListEmployee, int idIngresado){
	int retorno=-1;
    Employee* employee;
    int len;
    int i;
    int idObtenido;
    len=ll_len(pArrayListEmployee);
    for(i=0;i<len;i++){
        employee=ll_get(pArrayListEmployee,i);
        employee_getId(employee,&idObtenido);
        if(idObtenido == idIngresado){
            retorno = i;
        }
    }
    return retorno;
}
