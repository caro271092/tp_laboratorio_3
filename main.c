#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "InputOutput.h"

int main(){
	setbuf(stdout,NULL);
    int opcionIngresada;
    int flagCargaListadoTexto=-1;
    int flagCargaListadoBinario=-1;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	mostrarMenu();
    	PedirNumeroEntero(&opcionIngresada,"\n--->Ingrese la opción que desea ejecutar: ","---> ERROR. Ingrese una opción válida.", 1, 10, 2);
        switch(opcionIngresada)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==0){
					cargaMayorIdEnArchivoID(listaEmpleados);
					flagCargaListadoTexto=0;
					printf("\n------------->Los datos se cargaron exitosamente\n\n");
                }else{
                	printf("\n------------->No se pudieron cargar los datos\n\n");
                }
                break;
            case 2:
            	if(controller_loadFromBinary("data.csv",listaEmpleados)==0){
					flagCargaListadoBinario=0;
					printf("\n------------->Los datos se cargaron exitosamente\n\n");
            	}else{
            		printf("\n------------->No se pudieron cargar los datos\n\n");
            	}
            	break;
            case 3:
            	if(flagCargaListadoTexto==-1){
            		printf("\n-->No puede acceder a esta opción sin haber cargado los datos de los empleados\n\n");
            	}else{
            	controller_addEmployee(listaEmpleados);
            	}
            	//alta
            	break;
            case 4:
            	if(flagCargaListadoTexto==-1){
            		printf("\n-->No puede acceder a esta opción sin haber cargado los datos de los empleados\n\n");
				}else{
					controller_editEmployee(listaEmpleados);
				}
            	//modificar
                break;
            case 5:
            	if(flagCargaListadoTexto==-1){
            		printf("\n-->No puede acceder a esta opción sin haber cargado los datos de los empleados\n\n");
				}else{
					controller_removeEmployee(listaEmpleados);
				}
            	//baja
                break;
            case 6:
            	if(flagCargaListadoTexto==-1){
            		printf("\n-->No puede acceder a esta opción sin haber cargado los datos de los empleados\n\n");
				}else{
					controller_ListEmployee(listaEmpleados);
				}
               	break;
            case 7:
            	if(flagCargaListadoTexto==-1){
					printf("\n-->No puede acceder a esta opción sin haber cargado los datos de los empleados\n\n");
				}else{
					controller_sortEmployee(listaEmpleados);
				}
            	//ordenar
               	break;
            case 8:
            	if(flagCargaListadoTexto==-1){
					printf("\n-->No puede acceder a esta opción sin haber cargado los datos de los empleados\n\n");
				}else{
					if(controller_saveAsText("data.csv",listaEmpleados)==0){
					printf("\n-->Archivo de texto guardado exitosamente\n\n");
					}
				}
            	//guardar texto
               	break;
            case 9:
            	if(flagCargaListadoBinario==-1){
					printf("\n-->No puede acceder a esta opción sin haber cargado los datos de los empleados en modo binario\n");
				}else{
					if(controller_saveAsBinary("data.csv",listaEmpleados)==0){
					printf("\n-->Archivo binario guardado exitosamente\n\n");
					}
				}
            	//guardar binario
               	break;
            case 10:
            	if(flagCargaListadoBinario==0||flagCargaListadoTexto==0){
            		printf("\n-->No puede salir del programa sin guardar.\n\n");
            	}else{
            		opcionIngresada =11;
            	}
            	break;
        }
    }while(opcionIngresada != 11);
    printf("-->Ha salido del programa.");
    return 0;
}

