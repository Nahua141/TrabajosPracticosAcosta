#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#include "sectores.h"

#define TAM 1000
#define TAMS 5
int menuEmpleados();
int main()
{
    eEmpleado listaEmpleado[TAM];
    eSector sectores[TAMS] = { {1, "Sistemas"},
								{2, "RRHH"},
								{3, "Ventas"},
								{4, "Compras"},
								{5, "Contable"} };
    char auxNombre[51];
	char auxApellido[51];
	float auxSalario;
	int auxSector;
	int auxId;
	int index;

	int flag = 0;

	inicializarEmpleados(listaEmpleado, TAM);

    int proximoId=999;//arranca a partir del id 1000.
    char seguir='s';
    char confirmar;
    int cuanto;

    int i=0;
    do
	{
		system("cls");
		switch(menuEmpleados())
		{
			case 1:
				printf("\n***** Altas *****\n\n ");
				utn_getEntero(&cuanto, 3, "Cuantos empleados desea ingresar?: ", "Error, la cantidad ingresada es superior a la capacidad establecida o inferior 0.\n", 1, 1000);
				do
				{
					i++;
					if(reunirInformacion(listaEmpleado, TAM, &proximoId, auxNombre, auxApellido, &auxSalario, &auxSector, &index) == 0 && aniadirEmpleado(listaEmpleado, TAM, proximoId, auxNombre, auxApellido, auxSalario, auxSector, index) == 0)
					{
						flag = 1;
					}

				}while(i < cuanto);
				i = 0;
				break;

			case 2:
				if(flag == 1)
				{
					modificarEmpleados(listaEmpleado, TAM, sectores, TAMS);
				}
				else
				{
					printf("Error. Primero debe cargar empleados.\n");
				}
				break;


			case 3:
				if(flag == 1)
				{
					printf("\n***** Bajas *****\n\n ");
					do
					{
						mostrarEmpleados(listaEmpleado, TAM, sectores, TAMS);
						if(utn_getEntero(&auxId, 300, "Ingrese ID del empleado a eliminar: ", "Error, no es un numero de ID.\n", 1000, 2000) == 0)
						{
							removerEmpleado(listaEmpleado, TAM, auxId, sectores, TAMS);
						}
						printf("Desea continuar eliminando? s/n: ");
						fflush(stdin);
						scanf("%c", &confirmar);
						if(confirmar == 's')
						{
							seguir = 'n';
						}
					}while(seguir == 's');
				}
				else
				{
					printf("Primero debe cargar empleados.\n");
				}

				break;

			case 4:

                if(flag == 1)
				{
					informes(listaEmpleado, TAM, sectores, TAMS);
				}
				else
				{
					printf("Primero debe cargar empleados.\n");
				}
				break;

			case 5:
				system("cls");
				printf("\n***** Salir *****\n\n ");
				printf("Confirma salida? s/n: ");
				fflush(stdin);
				scanf("%c", &confirmar);
				if(confirmar == 's')
				{
					seguir = 'n';
				}
				break;

		}
    system("pause");

	}while(seguir == 's');
    return 0;
}
int menuEmpleados()
{
    int opcion;

    system("cls");

    printf("***Menu***\n\n");
    printf("1-Alta\n");
    printf("2-Modificar\n");
    printf("3-Baja\n");
    printf("4-Infome\n");
    printf("5-Salir\n");
    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
