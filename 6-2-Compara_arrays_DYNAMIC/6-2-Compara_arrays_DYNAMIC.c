/* 
 * File:   6-2-Compara_arrays_DYNAMIC.c
 * Author: Gartzia
 *
 * Created on 26 de octubre de 2013, 16:56
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int solicitar_numero_elementos(int nColumnas);
int *reserva_memoria(int nColumnas);
void peticion_array(char a, int nColumnas);
void leer_array(int *array, int nColumnas);
void visualizar_array(int *array, int nColumnas, char a);
void comparar_arrays(int *array_x, int *array_y, int *array_z, int nColumnas);
void contador(int *array_z, int nColumnas);

int main() {
    
    int nColumnas=0;
    int *array_x, *array_y, *array_z;
    
    //solicitar el tamaño del array
    nColumnas=solicitar_numero_elementos(nColumnas);
    
    //-----RESERVA DE MEMORIA-----
    //reservar memoria para array_x
    array_x=reserva_memoria(nColumnas);
    //para array_y
    array_y=reserva_memoria(nColumnas);
    //para array_z
    array_z=reserva_memoria(nColumnas);
    
    //-----LECTURA DE DATOS-----
    //lee los elementos de array_x
    peticion_array('X', nColumnas);
    leer_array(array_x, nColumnas);
    //lee los elementos de array_y
    peticion_array('Y', nColumnas);
    leer_array(array_y, nColumnas);
    
    //-----VISUALIZACIÓN DE DATOS-----
    printf("\n\n\n\t\t\t*************************\n");
    printf("\t\t\t*\tRESULTADO\t*");
    printf("\n\t\t\t*************************\n\n\n"); 
    //elementos de array_x y array_y
    visualizar_array(array_x, nColumnas, 'X');
    visualizar_array(array_y, nColumnas, 'Y');
    
    //-----TRATAMIENTO DE DATOS-----
    //compara los arrays y guarda en array_z los resultados
    comparar_arrays(array_x, array_y, array_z, nColumnas);
    
    //visualiza el número de elementos Mayores y Menores entre array_x y array_y
    contador(array_z, nColumnas);

    return (0);
}

int solicitar_numero_elementos(int nColumnas)
{
    printf("\nInserta el numero de elemntos a comparar:\n");
    fflush(stdout);
    fpurge(stdin);
    scanf("%d", &nColumnas);
    
    return nColumnas;
}

int *reserva_memoria(int nColumnas)
{
    int *array=NULL;
    
    if((array=(int *)malloc(nColumnas*sizeof(int)))==NULL)
    {
        printf("\nInsuficiente memoria libre.\n");
        return NULL;
    }
    
    return array;
}

void peticion_array(char a, int nColumnas)
{
    printf("\nIserta los %d elementos para el array '%c':\n", nColumnas, a);
    printf("\n----------------------------------------\n");
}

void leer_array(int *array, int nColumnas)
{
    int i;
    
    for(i=0;i<nColumnas;i++)
    {
        scanf("%1d", &array[i]); //o usar arrays tipo char y scanf("%[^n]") ???
    }
}

void visualizar_array(int *array, int nColumnas, char a)
{
    int i;
    
    printf("\n\t\t\tElementos del array %c:\n", a);
    printf("\n\t\t\t---------------------\n\t\t\t");
    
    for(i=0;i<nColumnas-1;i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d.\n", array[nColumnas-1]);
}

void comparar_arrays(int *array_x, int *array_y, int *array_z, int nColumnas)
{
    //compara cada elemento de array_x con array_y, según el caso, almacena -1, 0, 1 en array_z
    int i;
    
    for(i=0;i<nColumnas;i++)
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

void contador(int *array_z, int nColumnas)
{
    //cuenta el número de elementos menores (-1) y mayores (1) en array_z
    //y los almacena en las variables 'mayor' y 'menor'
    int i, mayor=0, menor=0;
    
    printf("\n\t\t\tElementos del array Z:\n");
    printf("\n\t\t\t---------------------\n\t\t\t");
    
    for(i=0;i<nColumnas-1;i++)
    {
        printf("%d ,", array_z[i]);
        
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
    printf("%d.\n", array_z[nColumnas-1]);
    
    printf("\n\n");
    printf("\n\t-----------------------------------------------------------");
    printf("\n\t|| Hay %d elemento(s) mayor(es) y %d elemento(s) menor(es) ||", mayor, menor);
    printf("\n\t-----------------------------------------------------------\n");
}