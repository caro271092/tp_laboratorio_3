#include "Employee.h"

Employee* employee_new(){ //CONSTRUCTOR por defecto, para el espacio
    Employee* newEmployee = NULL; //si devuelve null es que no se pudo cargar
    newEmployee= (Employee*)malloc(sizeof(Employee));
    if(newEmployee != NULL){
    	employee_setId(newEmployee,0);
    	employee_setNombre(newEmployee,"\0");
    	employee_setHorasTrabajadas(newEmployee,0);
    	employee_setSueldo(newEmployee,0);
    }
    return newEmployee;
}

//Recibe texto del archivo
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo){//CONSTRUCTOR parametrizado
    Employee* newEmployee=employee_new();
    if(newEmployee!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL){
    	employee_setId(newEmployee,atoi(idStr));
    	employee_setNombre(newEmployee,nombreStr);
    	employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr));
    	employee_setSueldo(newEmployee,atoi(sueldo));
    }else{
    	employee_delete(newEmployee);
    	newEmployee=NULL;
    }
    return newEmployee;
}

int employee_setId(Employee* this,int id){
	int retorno=-1;
	if(this != NULL && id >= 0){
		this->id = id;
		retorno=0;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id){
	int retorno=-1;
	if(this!=NULL && id!=NULL){
		*id = this->id;
		retorno=0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
	int retorno=-1;
	if(this!= NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		retorno=0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre){
	int retorno=-1;
	if(this!=NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		retorno=0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno=-1;
	if(this!=NULL && horasTrabajadas>0){
		this->horasTrabajadas = horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno=-1;
	if(this !=NULL && horasTrabajadas != NULL){
		*horasTrabajadas = this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this, int sueldo){
	int retorno=-1;
	if(this!=NULL && sueldo>0){
		this->sueldo = sueldo;
		retorno=0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo){
	int retorno=-1;
	if(this!=NULL && sueldo!=NULL){
		*sueldo = this->sueldo;
		retorno=0;
	}
	return retorno;
}

void employee_printEmployee(void* this){
	int id;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;
	if(this!=NULL){
		if(employee_getId(this,&id)== 0 && employee_getNombre(this,nombre)== 0 && employee_getHorasTrabajadas(this, &horasTrabajadas)== 0 && employee_getSueldo(this,&sueldo)== 0){
			printf("\n%d%15s%15d%15d\n",id,nombre,horasTrabajadas,sueldo);
		}
	}
}

void employee_delete(Employee* this){
	if(this!=NULL){
		free(this);
	}
}

int employee_sortByID(void* this1, void* this2){
	int criterio;
	int id1;
	int id2;
	employee_getId(this1,&id1);
	employee_getId(this2,&id2);
	if(id1>id2){
		criterio =1;
	}else if(id1==id2){
		criterio =0;
	}else{
		criterio=-1;
	}
	return criterio;
}

int employee_sortByName(void* thisA, void* thisB){
	int criterio = -1;
	char nombre1[50];
	char nombre2[50];
	employee_getNombre(thisA,nombre1);
	employee_getNombre(thisB,nombre2);
	if(strcmp(nombre1,nombre2) == 0){
		criterio =0;
	}else if(strcmp(nombre1,nombre2)>0){
		criterio=1;
	}else{
		criterio=-1;
	}
	return criterio;
}

int employee_sortBySueldo(void* thisA, void* thisB){
	int criterio;
	int sueldo1;
	int sueldo2;
	employee_getSueldo(thisA,&sueldo1);
	employee_getSueldo(thisB,&sueldo2);
	if(sueldo1==sueldo2){
		criterio =0;
	}else if(sueldo1>sueldo2){
		criterio=1;
	}else{
		criterio=-1;
	}
	return criterio;
}

int employee_sortByHorasTrabajadas(void* thisA, void* thisB){
	int criterio;
	int horas1;
	int horas2;
	employee_getHorasTrabajadas(thisA,&horas1);
	employee_getHorasTrabajadas(thisB,&horas2);
	if(horas1 == horas2){
		criterio = 0;
	}else if(horas1>horas2){
		criterio=1;
	}else{
		criterio=-1;
	}
	return criterio;
}

