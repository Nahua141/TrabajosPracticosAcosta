#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sectores.h"
int cargarSectorDescripcion(char descripcion[], int id, eSector sectores[], int tam)
{
    int ok=0;
    for(int i=0; i<tam; i++)
    {
        if(sectores[i].id == id)
        {
            strcpy(descripcion, sectores[i].descripcion);
            ok=1;
            break;
        }
    }
    return ok;
}
int mostrarSectores(eSector sectores[], int tam)
{
    int ok=0;
    if(sectores !=0)
    {
        ok=1;
        printf("****Sectores****\n\n");
        printf(" Id      Descripcion");

        for(int i=0; i<tam; i++)
        {
            printf("%d    %10s\n", sectores[i].id, sectores[i].descripcion);
        }
    }
    return ok;
}
