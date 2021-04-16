#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
int menu();
int main()
{
    char seguir='s';
    char confirma;
    float primerNumero;
    float segundoNumero;
    int resultado;


    do
    {
        switch(menu())
        {
        case 1:
            primerNumero = Operando(primerNumero);
            break;
        case 2:
            segundoNumero = Operando(segundoNumero);
            break;
        case 3:
             MostrarOperaciones(primerNumero, segundoNumero);
            break;
        case 4:
            Sumar(primerNumero, segundoNumero);
            Restar(primerNumero, segundoNumero);
            Multiplicar(primerNumero, segundoNumero);
            Dividir(primerNumero, segundoNumero);
            resultado=CalcularFactorial(primerNumero);
            printf("El factorial de %.2f! = %d\n",primerNumero, resultado);
            resultado=CalcularFactorial(segundoNumero);
            printf("El factorial de %.2f! = %d\n",segundoNumero, resultado);
            break;
        case 5:
            printf("Confirma salida? s o n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                seguir='n';
            }
            break;
        }
        system("pause");
    }
    while(seguir=='s');
    return 0;
}
int menu()
{
    int opcion;
    system("cls");
    printf("*****Calculadora*****\n\n");
    printf("1-Ingresar primer oprenado A=x: \n");
    printf("2-Ingresar segundo oprenado B=x: \n");
    printf("3-Calcular todas las operaciones\n");
    printf("4-Informar los resultados\n");
    printf("5-Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
