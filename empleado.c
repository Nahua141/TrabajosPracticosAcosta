#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sectores.h"
#include "dataWarehouse.h"
#include "utn.h"

int inicializarEmpleados(eEmpleado lista[], int tamE)
{
    if(lista != 0)
    {
        for(int i=0; i<tamE; i++)
        {
            lista[i].isEmpty=1;
        }
        return 0;
    }
    else
    {
        return 1;
    }
}
void mostrarEmpleado(eEmpleado auxEmpleado, eSector sectores[], int tam)
{
    char descripcionSector[20];

    cargarSectorDescripcion(descripcionSector, auxEmpleado.idSector, sectores, tam);

    printf("%d   %10s    %10s   %.2f    %10s", auxEmpleado.id, auxEmpleado.nombre, auxEmpleado.apellido, auxEmpleado.salario, descripcionSector);
}
void mostrarEmpleados(eEmpleado lista[], int tamE, eSector sectores[], int tam)
{
    printf(" ID       Nombre       Apellido    Salario       Sector\n\n");

    for(int i=0; i<tamE; i++)
    {
        if(lista[i].isEmpty==0)
        {
            mostrarEmpleado(lista[i], sectores, tam);
        }
    }
}
int buscarEmpleadoXId(eEmpleado lista[], int tamE, int id)
{
    int existe=-1;
    if(lista != 0 && tamE > 0)
    {
        for(int i=0; i<tamE; i++)
        {
            if(id==lista[i].id)
            {
                existe=i;
                break;
            }
        }
    }
    return existe;
}
int buscarVacio(eEmpleado lista[], int tamE)
{
    int index=-1;

    for(int i=0; i<tamE; i++)
    {
        if(lista[i].isEmpty==1)
        {
            index=i;
            break;
        }
    }
    return index;
}
int reunirInformacion(eEmpleado lista[], int tamE, int* proxId, char auxNombre[], char auxApellido[], float* auxSalario, int* auxSector, int* index)
{
    int id= *proxId;
    int nuevoId=id+1;
    int ok=-1;

    if(lista != 0 && tamE > 0 && proxId != 0 && auxNombre != 0 && auxApellido != 0 && auxSalario != 0 && auxSector != 0)
    {
        index = buscarVacio(lista, tamE);

        if(index < 0)
        {
            printf("Sistema completo\n");
        }

        else
        {

            utn_getCadena(auxNombre, 50, 3, "\nIngrese nombre: ", "El nombre ingresado es invalido.\n");
			utn_getCadena(auxApellido, 50, 3, "Ingrese apellido: ", "El apellido ingresado es invalido.\n");
			utn_getFlotante(auxSalario, 3, "Ingrese salario: ", "El salario ingresado es invalido.\n", 12000.00, 300000.00);
			utn_getEntero(auxSector, 3, "Ingrese sector: ", "El sector ingresado no es valido.\n", 1, 5);
			*proxId = nuevoId;
			ok=0;
        }

    }
    return ok;
}
int aniadirEmpleado(eEmpleado lista[], int tamE, int id, char nombre[], char apellido[], float salario, int sector, int index)
{
    int ok =-1;

    if(lista != 0 && nombre != 0 && apellido != 0 && tamE > 0)
    {
        lista[index].id = id;
        strcpy(lista[index].nombre, nombre);
        strcpy(lista[index].apellido, apellido);
        lista[index].salario = salario;
        lista[index].idSector = sector;
        lista[index].isEmpty = 0;
        ok=0;
    }
    return ok;
}
int removerEmpleado(eEmpleado lista[], int tamE, int id, eSector sectores[], int tam)
{
    int index;
    char confirmar;
    int ok=-1;

    if(lista != 0 && tamE > 0)
    {
        index = buscarEmpleadoXId(lista, tamE, id);

        if(index < 0)
        {
            printf("\nError. El id ingresado no se corresponde con un empleado");
        }
        else
        {
            printf("\nEl id %d pertenece al empleado: \n\n",id);
            mostrarEmpleado(lista[index], sectores, tam);
            printf("Desea eliminarlo?: \n");
            fflush(stdin);
            scanf("%c", &confirmar);

            if(confirmar == 's')
            {
                printf("El empleado fue eliminado de manera exitosa\n");
                lista[index].isEmpty = 1;
                ok=0;
            }
            else if (confirmar == 'n')
            {
                printf("Se ha cancelado la operacion\n");
                ok=0;
            }
        }
    }
    return ok;
}
int modificarEmpleados(eEmpleado lista[], int tamE, eSector sectores[], int tam)
{
    int ok = -1;
    int auxId;
    int opcion;
    char confirmar;
    char continuar;
    int index;
    char nuevoNombre[51];
    char nuevoApellido[51];
    float nuevoSalario;
    int nuevoSector;

    system("cls");
    printf("***Modificar empleado***\n\n");
    mostrarEmpleados(lista, tamE, sectores, tam);

    if(lista != 0 && tamE > 0 &&utn_getEntero(&auxId, 3, "\nIngrese ID de la persona a modificar: ", "Error. No es un ID.\n", 1000, 2000) == 0 )
    {
        index=buscarEmpleadoXId(lista, tamE, auxId);

        if(index==-1)
        {
            printf("No se encuentra ese id en el sistema\n");
        }
        else
        {
            printf("El id %d pertenece al empleado \n", auxId);
            printf("Id    Nombre    Apellido     Salario     Sector\n\n");
            mostrarEmpleado(lista[index], sectores, tam);
            utn_getCadena(&confirmar, 2, 3, "Desea modificarla?: ", "Error. Ingrese una opcion valida");

            if(confirmar=='s')
            {
                do
                {
                    printf("1-Modificar nombre\n");
                    printf("2-Modificar apellido\n");
                    printf("3-Modificar salario\n");
                    printf("4-Modificar sector\n");
                    utn_getEntero(&opcion, 3, "Ingrese opcion a modificar: ", "Error, no es una opcion valida", 1, 4);

                    switch(opcion)
                    {
                    case 1:
                        utn_getCadena(nuevoNombre, 51, 5, "Ingrese nuevo nombre: ", "Error, nombre invalido.\n");
                        strcpy(lista[index].nombre, nuevoNombre);
                        break;
                    case 2:
                        utn_getCadena(nuevoApellido, 51, 5, "Ingrese nuevo apellido: ", "Error, apellido invalido.\n");
                        strcpy(lista[index].apellido, nuevoApellido);
                        break;
                    case 3:
                        utn_getFlotante(&nuevoSalario, 5, "Ingrese nuevo salario: ", "Error, salario invalido.\n", 12000, 300000);
                        lista[index].salario = nuevoSalario;
                        break;
                    case 4:
                        utn_getEntero(&nuevoSector, 5, "Ingrese nuevo sector: ", "Error, sector invalido.\n", 1, 5);
                        lista[index].idSector = nuevoSector;
                        break;
                    default:
                        printf("No es una opcion valida.\n\n");
                    }
                    printf("Se han modificado los datos correctamente. \n");
                    printf("ID         Nombre     Apellido    Salario        Sector\n");
                    mostrarEmpleado(lista[index], sectores, tam);
                    printf("Desea seguir modificando? s/n: ");
                    fflush(stdin);
                    scanf("%c", &confirmar);
                    if(confirmar == 's')
                    {
                        continuar = 'n';
                    }
                }while(continuar == 's');
            }
            else if(confirmar=='n')
            {
                printf("No se registraron las modificaciones\n");
            }
        }
        ok=0;
    }
    return ok;
}
int menuInformes()
{
    int opcion;

    system("cls");
    printf("\n***Informes***\n\n");

    printf("1- Listar empleados alfabeticamente\n");
    printf("2- Total y promedio de los salarios\n");
    printf("3- Salir\n");

    utn_getEntero(&opcion, 300, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 3);

    return opcion;
}
int informes(eEmpleado lista[], int tamE, eSector sectores[], int tam)
{
    int ok=-1;
    char continuar='s';
    char confirmar;
    int asDes;

    if(lista != 0 && sectores != 0)
    {
        do
        {
            switch(menuInformes())
			{
				case 1:
					utn_getEntero(&asDes, 300, "\nIngrese 1 para listar de manera ascendente o 0 para descendente: ", "Error. No es un ordenamiento posible.\n", 0, 1);
					printf("\n");
					ordenarEmpleados(lista,tamE , asDes);
					mostrarEmpleados(lista,tamE , sectores, tam);
					ok = 0;
					break;
				case 2:
					promedioYTotalDeSalarios(lista,tamE);
					ok = 0;
					break;
				case 3:
					printf("Confirma salida? s/n: ");
					fflush(stdin);
					scanf("%c", &confirmar);
					if(confirmar == 's')
					{
						continuar = 'n';
					}
					ok = 0;
					break;
				default:
					printf("No es una opcionn valida.\n\n");
			}
		}while(continuar == 's');
        }
        return ok;
}
int ordenarEmpleados(eEmpleado* lista, int tamE, int ordenar)
{
    int ok = -1;
	eEmpleado auxEmpleado;

	if(lista != 0)
	{
		for(int i = 0; i < tamE -1; i++)
		{
			for(int j = i + 1; j < tamE; j ++)
			{
				ok = 0;

				if(lista[i].isEmpty == 0 && lista[j].isEmpty == 0)
				{

					switch(ordenar)
					{
						case 0:
							if(lista[i].idSector < lista[j].idSector || (lista[i].idSector == lista[j].idSector && (strcmp(lista[i].apellido, lista[j].apellido)) < 0))
							{
								auxEmpleado = lista[i];
								lista[i] = lista[j];
								lista[j] = auxEmpleado;
							}
							break;

						case 1:
							if(lista[i].idSector > lista[j].idSector || (lista[i].idSector == lista[j].idSector && (strcmp(lista[i].apellido, lista[j].apellido)) > 0))
							{
								auxEmpleado = lista[i];
								lista[i] = lista[j];
								lista[j] = auxEmpleado;
							}
							break;

						default:
							printf("No es un orden valido.\n");
					}
				}
			}
		}
	}
	return ok;
}
int promedioYTotalDeSalarios(eEmpleado* lista, int tamE)
{
    int ok = -1;
	float acumuladorSalario = 0;
	int contadorEmpleados = 0;
	float promedio;
	int contadorEmpleadosMasAlto = 0;

	if(lista != 0 && tamE > 0)
	{
		for(int i = 0; i < tamE; i++)
		{
			if(lista[i].isEmpty == 0)
			{
				acumuladorSalario += lista[i].salario;
				contadorEmpleados++;
			}
		}

		promedio = (float) acumuladorSalario / contadorEmpleados;

		for(int i = 0; i < tamE; i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].salario > promedio)
			{
				contadorEmpleadosMasAlto++;
			}

		}
		ok = 0;

		printf("\nEl total de los salarios de los %d empleados en sistema es de: %.2f\n", contadorEmpleados, acumuladorSalario);
		printf("El promedio de todos los salarios es de: %.2f\n", promedio);
		if(contadorEmpleadosMasAlto == 1)
		{
			printf("Hay %d empleado que supera el salario promedio.\n\n",contadorEmpleadosMasAlto);
		}
		else
		{
			printf("Hay %d empleados que superan el salario promedio.\n\n", contadorEmpleadosMasAlto);
		}


	}
	return ok;
}
void hardcodeoDeEmpleados(eEmpleado vec[], int cantidad)
{
    for(int i = 0; i < cantidad; i++)
	{
		vec[i].id = ids[i]; //uso los dato
		strcpy(vec[i].nombre, nombres[i]);
		strcpy(vec[i].apellido, apellidos[i]);
		vec[i].salario = sueldos[i];
		vec[i].idSector = idsSector[i];
		vec[i].isEmpty = 0;
	}
}
