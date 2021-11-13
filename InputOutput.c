/* InputOutput.c
 * Author: Alvarez Carolina*/
#include "InputOutput.h"
#define TRUE 1
#define FALSE 0

int ValidacionIngresoDeUnEnteroPositivo(char ingreso[]){
	int i;
	int retorno = -1;
	int longitud;
	longitud = strlen(ingreso);
		for(i=0; i< longitud; i++){
			if(isdigit(ingreso[i]) != 0){
				retorno = 0;
				break;
			}
		}
	return retorno;
}

int PedirNumeroEntero(int* ingresoValidado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos){
	int retorno = -1;
	char ingreso[50];
	int buffer;
	if(ingresoValidado!=NULL && mensaje!=NULL && mensajeError != NULL && minimo<=maximo && reintentos >= 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]", ingreso);
			if(ValidacionIngresoDeUnEnteroPositivo(ingreso)==0){
				buffer = atoi(ingreso);
			}if(buffer>=minimo && buffer<=maximo){
					*ingresoValidado = buffer;
					retorno = 0;
					break;
			}else{
				printf("%s", mensajeError);
				}
		reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

int ValidacionIngresoDeUnFlotantePositivo(char ingreso[]){
	int i;
	int retorno;
	int longitud;
	longitud = strlen(ingreso);
	int contadorDePuntos = 0;
		for(i=0; i<longitud; i++){
			if(isdigit(ingreso[i]) == 0){
				if(ingreso[i] == '.'){
					contadorDePuntos++;
				}
				if(ingreso[i] != '.' || contadorDePuntos > 1){
					retorno = -1;
					break;
				}
		}
		retorno = 0;
	}
	return retorno;
}

int PedirNumeroFlotante(float* ingresoValidado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos){
	int retorno = -1;
	char ingreso[50];
	float buffer;
	if(ingresoValidado!=NULL && mensaje!=NULL && mensajeError != NULL && minimo<=maximo && reintentos >= 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]", ingreso);
			if(ValidacionIngresoDeUnFlotantePositivo(ingreso)!=-1){
			buffer = atof(ingreso);
			}if(buffer>=minimo && buffer<=maximo){
				*ingresoValidado = buffer;
				retorno = 0;
				break;
				}else{
					printf("%s", mensajeError);
					}
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

int GetString(char string[], char message[], int len){
	char auxiliarString[200];
	int retorno = -1;
	if (string != NULL && message != NULL){
		retorno = 0;
		printf(message);
		fflush(stdin);
		scanf("%[^\n]", auxiliarString);
		while (strlen(auxiliarString) > len){
			printf("Reingrese: ");
			fflush(stdin);
			scanf("%[^\n]", auxiliarString);
		}
		strcpy(string, auxiliarString);
	}
	return retorno;
}

float ValidacionFloatDentroDeUnRango(float ingreso, int minimo, int maximo){
	while(ingreso<minimo||ingreso>maximo){
		printf("Ingrese una opción válida: ");
		fflush(stdin);
		scanf("%f", &ingreso);
	}
	return ingreso;
}

int ValidacionEnteroDentroDeUnRango(int ingreso, int minimo, int maximo){
	while(ingreso<minimo||ingreso>maximo){
		printf("Ingrese una opción válida: ");
		fflush(stdin);
		scanf("%d", &ingreso);
	}
	return ingreso;
}

char* ToUpperFirstLetter(char cadena[]){
	int tamanio;
	tamanio= strlen(cadena);
	for(int i = 0; i < tamanio; i++){
		cadena[0]=towupper(cadena[0]);
		}
return cadena;
}

int PedirNumeroEnteroVersionCorta(char mensaje[]){
	int numero;
	char ingreso[50];
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", ingreso);
	while(!(ValidacionIngresoDeUnEnteroPositivo(ingreso))){
		printf("ERROR. %s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", ingreso);
		}
	numero = atoi(ingreso);
	return numero;
}

float PedirNumeroFlotanteVersionCorta(char mensaje[]){
	float numero;
	char ingreso[50];
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", ingreso);
	while(ValidacionIngresoDeUnFlotantePositivo(ingreso)!=0){
		printf("ERROR. %s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", ingreso);
		}
	numero = atof(ingreso);
	return numero;
}

void mostrarMenu(){
	printf(
	 "*****************************************************\n"
	 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
	 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
	 "3. Alta de empleado\n"
	 "4. Modificar datos de empleado\n"
	 "5. Baja de empleado\n"
	 "6. Listar empleados\n"
	 "7. Ordenar empleados\n"
	 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
	 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
	"10. Salir\n"
	"*****************************************************\n");
}

int cargaMayorIdEnArchivoID(LinkedList* pArrayListEmployee){//para guardar los 1eros ids q me dan
	int retorno=-1;
	Employee* employee;//para convertir pGenerico del get en empleado
	int len=-1;
	int i;
	int mayorID=-1;
	int idObtenido;
	//char idCharParaGuardar[50];
	FILE* pArchivoID=NULL;
	pArchivoID = fopen("ID.csv","w");//abrir archivo para escribirlo
	len = ll_len(pArrayListEmployee);
		if(len==0){
			return len;
		}else{
			for(i=0;i<=len;i++){
				employee = (Employee*) ll_get(pArrayListEmployee,i);//devuelve puntero genérico,castear, unboxing
				employee_getId(employee,&idObtenido);
				if(i==0 || idObtenido>mayorID){
					mayorID = idObtenido;
				}
			}
			if(pArchivoID!=NULL){
				fprintf(pArchivoID,"%d", mayorID);
				//itoa(mayorID,idCharParaGuardar,10);
				//fwrite(&idCharParaGuardar,sizeof(idCharParaGuardar),1,pArchivoID);//guardar el mayor
				fclose(pArchivoID);//cerrar arch
				retorno=0;
			}
		}
	return retorno;
}

int generadorID(){//para cargar un nuevo empleado
	int id;
	int idGenerado=-1;
	//char idParaGuardar[50];
	FILE* pArchivoID;
	pArchivoID = fopen("ID.csv","r");
	if(pArchivoID!=NULL){
		while(!feof(pArchivoID)){
			fscanf(pArchivoID, "%d",&id);
			//printf("uno %d", id);
		}
		id++;
		idGenerado =id;
		//printf("dos %d", idGenerado);
		//itoa(idGenerado,idParaGuardar,10);
		fclose(pArchivoID);
		pArchivoID = fopen("ID.csv","w");//abro para escribir el nuevo último id
		fprintf(pArchivoID,"%d", idGenerado);
		fflush(pArchivoID);
		//fwrite(&idParaGuardar,sizeof(idParaGuardar),1,pArchivoID);//guardar el id mayor nuevamente en el archivo, se pisa el anterior arch
		fclose(pArchivoID);//cerrar el archivo
	}else{
		printf("\n--->No se pudo leer el archivo.");
	}
	return idGenerado;
}

void menuModificaciones(){
	printf(
	"*****************************************************\n"
	 "1. Modificar nombre\n"
	 "2. Modificar horas trabajadas\n"
	 "3. Modificar sueldo\n"
	 "4. Cancelar\n"
	"*****************************************************\n");
}

void menuCriterioOrdenamiento(){
	printf(
	"*****************************************************\n"
	"Criterio para ordenar:\n"
	"1. ID\n"
	"2. Nombre\n"
	"3. Horas trabajadas\n"
	"4. Sueldo\n"
	"*****************************************************\n");
}

