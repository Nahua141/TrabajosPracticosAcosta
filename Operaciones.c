#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
float Operando(float operando)
{
    printf("Ingrese un operando operando= ");
    scanf("%f", &operando);
    return operando;
}
void MostrarOperaciones(float numeroUno, float numeroDos)
{
    printf("%.2f + %.2f\n", numeroUno, numeroDos);
    printf("%.2f - %.2f\n", numeroUno, numeroDos);
    printf("%.2f * %.2f\n", numeroUno, numeroDos);
    printf("%.2f / %.2f\n", numeroUno, numeroDos);
    printf("%.2f! %.2f!\n", numeroUno, numeroDos);
}
float Sumar(float numeroUno, float numeroDos)
{
    float resultado;

    resultado = numeroUno + numeroDos;
    printf("La suma entre %.2f + %.2f = %.2f\n", numeroUno, numeroDos, resultado);

    return resultado;
}
float Restar(float numeroUno, float numeroDos)
{
    float resultado;
    resultado = numeroUno - numeroDos;
    printf("La resta entre %.2f - %.2f = %.2f\n", numeroUno, numeroDos, resultado);
    return resultado;

}
float Multiplicar(float numeroUno, float numeroDos)
{
    float resultado;
    resultado = numeroUno * numeroDos;
    printf("La multiplicacion entre %.2f * %.2f = %.2f\n", numeroUno, numeroDos, resultado);
    return resultado;
}

float Dividir(float numeroUno, float numeroDos)
{
    float resultado;
    if(numeroDos == 0)
    {
        printf("No se puede dividir por 0\n");
    }
    else
    {
        resultado = numeroUno / numeroDos;
        printf("La division entre entre %.2f / %.2f = %.2f\n", numeroUno, numeroDos, resultado);
    }

    return resultado;

}
float CalcularFactorial(float numero)
{
   float resultado;

   if(numero == 0 )
   {
       resultado = 1;
   }
   else
   {
       resultado = numero * CalcularFactorial(numero-1);

   }

   return resultado;
}
