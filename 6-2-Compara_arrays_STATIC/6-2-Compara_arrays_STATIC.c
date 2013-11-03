/* 
 * File:   6-2-Compara_arrays_STATIC.c
 * Author: Gartzia
 *
 * Created on 26 de octubre de 2013, 16:56
 */

#include <stdio.h>
#include <stdlib.h>
#define RANGO 10

/*
 * 
 */
void inicializar_array(int array[]);
void peticion_array(int array_x[], int array_y[]);
void leer_array(int array[]);
void visualizar_array(int array[]);
void comparar_arrays(int array_x[], int array_y[], int array_z[]);
void contador(int array_z[]);

int main() {
    
    int array_x[RANGO], array_y[RANGO], array_z[RANGO];
    
    //inicializar arrays:
    inicializar_array(array_x);
    inicializar_array(array_y);
    
    //lee los elementos de array_x y array_y
    peticion_array(array_x, array_y);
    
    //compara los arrays y guarda en array_z los resultados
    comparar_arrays(array_x, array_y, array_z);
    
    //visualiza el número de elementos Mayores y Menores entre array_x y array_y
    contador(array_z);

    return (0);
}

void inicializar_array(int array[])
{
    int i;
    
    for(i=0;i<RANGO;i++)
    {
        *(array+i)=0;
    }
}

void peticion_array(int array_x[], int array_y[])
{
    printf("\nIserta 10 números enteros para el array 'X':\n");
    fflush(stdout);
    fpurge(stdin);
    leer_array(array_x);
    
    printf("\nIserta 10 numeros enteros para el array 'Y':\n");
    fflush(stdout);
    fpurge(stdin);
    leer_array(array_y);
    
    printf("\n---------------------\n");
    
    printf("\nElementos del array X:\n");
    visualizar_array(array_x);
    printf("\n\nElementos del array Y:\n");
    visualizar_array(array_y);
}

void leer_array(int array[])
{
    int i;
    
    for(i=0;i<RANGO;i++)
    {
        scanf("%1d", &array[i]); //o usar arrays tipo char y scanf("%[^n]") ???
        //if(getchar()=='\n')
        //{
        //    fpurge(stdin);
        //    break;
        //}
    }
}

void visualizar_array(int array[])
{
    int i;
    
    for(i=0;i<RANGO;i++)
    {
        if(i==RANGO-1)
        {
            printf("%d.\n", array[i]);
        }
        else
        {
            printf("%d, ", array[i]);
        }
    }
}

void comparar_arrays(int array_x[], int array_y[], int array_z[])
{
    int i;
    
    for(i=0;i<RANGO;i++)
    {
        
        if(array_x[i]>array_y[i])
        {
            array_z[i]=1;
        }
        else
        {
            if(array_x[i]<array_y[i])
            {
                array_z[i]=-1;
            }
            else
            {
                array_z[i]=0;
            }
        }
    }
}

void contador(int array_z[])
{
    int i, mayor=0, menor=0;
    
    printf("\n---------------------\n");
    printf("\nElementos del array 'Z':\n");
    
    for(i=0;i<RANGO;i++)
    {
        if(i==RANGO-1)
        {
            printf("%d.\n", array_z[i]);
        }
        else
        {
            printf("%d ,", array_z[i]);
            
        }
        
        if(array_z[i]==1)
        {
            mayor++;
        }
        else
        {
            if(array_z[i]==-1)
            {
                menor++;
            }
        }
    }
    
    printf("\nHay %d elementos mayores y %d elementos menores.", mayor, menor);
}