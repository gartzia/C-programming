/* 
 * File:   5-5-Adicional_por_REFERENCIA.c
 * Author: Gartzia
 *
 * Created on 20 de octubre de 2013, 16:07
 */

/*
 * 
 C:) Indica para cada uno de los siguientes parámetros si son de entrada, de salida o de entrada/salida:
     num1 y num2, orden, resultado.
 *
     num1:      Para main()-> Salida   Para ordena()-> E/S     Para visualizar()-> Entrada.
     num2:      Para main()-> Salida   Para ordena()-> E/S     Para visualizar()-> Entrada.
     orden:     Para main()-> Salida   Para ordena()-> E/S     Para visualizar()-> Entrada.
     resultado: Para main()-> Salida   Para ordena()-> E/S     Para visualizar()-> Entrada.
 * 
 D:) Indica para cada uno de los siguientes parámetros si has empleado paso por valor o paso por referencia:
     num1 y num2, orden, resultado.
 * 
     num1:      Referencia.
     num2:      Referencia.
     ordena:    Referencia.
     resultado: Referencia.
 * 
 E:) ¿Cómo harías para pasar resultado de la forma opuesta (valor/referencia) a la que has empleado?
 * 
 
 Prototipo: (declaración de la función)
     int ordena (int resultado);
 
 Llamada: (invocación de la función por VALOR)
     resultado=ordena(resultado);
 
 Función: (definición de la función)
     int ordena (int resultado)
     {
     ...
     if(...)
     {
        resultado=1;
     }
     ...
     return resultado;
     }
 
 */
#include <stdio.h>

/*
 * 
 */
void ordena (int *num1, int *num2, int *orden, int *resultado);
void visualizar(int *resultado, int *orden, int *num1, int *num2);
/*
 * 
 */
int main(void) {
    
    int num1, num2, orden, resultado;
    
    printf("\nInserta dos números enteros:\nY un '0' si quieres ordenarlos de mayor a menor o '1' de menor a mayor:\n");
    fflush(stdout);
    fpurge(stdin);
    scanf("%d %d %d", &num1, &num2, &orden);
    
    if(num1==num2)
    {
        printf("Los números son iguales.\n");
    }
    else
    {
        ordena(&num1, &num2, &orden, &resultado);
        visualizar(&resultado, &orden, &num1, &num2);
    }
    
    printf("\nFin del programa.\n");
    
    return (0);
}

void ordena(int *num1, int *num2, int *orden, int *resultado)
{
    int paso;
    
    switch(*orden)
    {
        case 0:
            if(*num1<*num2)
            {
                paso=*num1;
                *num1=*num2;
                *num2=paso;
                
                *resultado=0;
                
            }
            else
            {
                *resultado=1;
            }
            break;
        
        case 1:
            if(*num2<*num1)
            {
                paso=*num1;
                *num1=*num2;
                *num2=paso;
                
                *resultado=0;
            }
            else
            {
                *resultado=1;
            }
            break;
            
    }
}

void visualizar(int *resultado, int *orden, int *num1, int *num2)
{
    if(*resultado==0)
    {
        printf("Se ha cambiado el orden de los números:\n");
    }
    else
    {
        printf("No se ha cambiado el orden de los números:\n");
    }

    if(*orden==0)
    {
        printf("%d > %d\n", *num1, *num2);
    }
    else
    {
        printf("%d < %d\n", *num1, *num2);
    }
}