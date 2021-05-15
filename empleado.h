#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "sectores.h"
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int idSector;
    int isEmpty;
}eEmpleado;


#endif // EMPLEADO_H_INCLUDED
int inicializarEmpleados(eEmpleado lista[], int tamE);
int aniadirEmpleado(eEmpleado lista[], int tamE, int id, char nombre[], char apellido[], float salario, int sector, int index);
int buscarVacio(eEmpleado lista[], int tamE);
int buscarEmpleadoXId(eEmpleado lista[], int tamE, int id);
int removerEmpleado(eEmpleado lista[], int tamE, int id, eSector sectores[], int tam);
int reunirInformacion(eEmpleado lista[], int tamE, int* proxId, char auxNombre[], char auxApellido[], float* auxSalario, int* auxSector, int* index);
void mostrarEmpleado(eEmpleado auxEmpleado, eSector sectores[], int tam);
void mostrarEmpleados(eEmpleado lista[], int tamE, eSector sectores[], int tam);
int modificarEmpleados(eEmpleado lista[], int tamE, eSector sectores[], int tam);
int menuInformes();
int informes(eEmpleado lista[], int tamE, eSector sectores[], int tam);
int ordenarEmpleados(eEmpleado* lista, int tamE, int ordenar);
int promedioYTotalDeSalarios(eEmpleado* lista, int tamE);
void hardcodeoDeEmpleados(eEmpleado vec[], int cantidad);
