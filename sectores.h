#ifndef SECTORES_H_INCLUDED
#define SECTORES_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
}eSector;


#endif // SECTORES_H_INCLUDED
int cargarSectorDescripcion(char descripcion[], int id, eSector sectores[], int tam);
int mostrarSectores(eSector sectores[], int tam);
