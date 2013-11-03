/* 
 * File:   7-2-Estrellas_DYNAMIC.c
 * Author: Gartzia
 *
 * Created on 2 de noviembre de 2013, 20:35
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int solicitartamano(int numero, int a);
void inicializar_mapa(int **estrellas, int nFilas, int nColumnas);
void leer_array(int **array, int nFilas, int nColumnas);
void crear_mapa(int **array, int **estrellas, int nFilas, int nColumnas);
int sumador(int **array,int i,int j);
void visualizar_mapa(int **estrellas,int nFilas,int nColumnas);

int main()
{
    int **array=NULL, **estrellas=NULL;
    int nFilas, nColumnas, i;
    
    //solicitar el tamaño del array
    nFilas=solicitartamano(nFilas, 0);
    nColumnas=solicitartamano(nColumnas, 1);
    
    //reservar memoria para array:
    if((array=(int **)malloc(nFilas*sizeof(int *)))==NULL)
    {
        printf("\nInsuficiente memoria.\n");
        return -1;
    }
    else
    {
        for(i=0;i<nFilas;i++)
        {
            array[i]=(int *)malloc(nColumnas*sizeof(int));
        }
    }
    
    //reserva de memoria para estrellas:
    if((estrellas=(int **)malloc(nFilas*sizeof(int *)))==NULL)
    {
        printf("\nInsuficiente memoria.\n");
        return -1;
    }
    else
    {
        for(i=0;i<nFilas;i++)
        {
            estrellas[i]=(int *)malloc(nColumnas*sizeof(int));
        }
    }
    
    //inicializar a Ceros el mapa de salida:
    inicializar_mapa(estrellas, nFilas, nColumnas);
    
    //leer los datos del array
    leer_array(array, nFilas, nColumnas);
    
    //indicar estrellas en el mapa:
    crear_mapa(array, estrellas, nFilas, nColumnas);
    
    //visualizar mapa de estrellas:
    visualizar_mapa(estrellas, nFilas, nColumnas);

    return (0);
}

int solicitartamano(int numero, int a)
{
    int Ok=0;
    
    do
    {
        if(a==0)
        {
            printf("\nInserta el número de Filas:\n");
        }
        else
        {
            printf("\nInserta el número de Columnas:\n");
        }
        Ok=scanf("%d", &numero);
        fflush(stdin);  
        fpurge(stdin);
    }while(!Ok && numero<1);
    
    return numero;
}

void inicializar_mapa(int **estrellas, int nFilas, int nColumnas)
{
    int i, j;
    
    for(i=0;i<nFilas;i++)
    {
        for(j=0;j<nColumnas;j++)
        {
            estrellas[i][j]=0;
        }
    }
}

void leer_array(int **array, int nFilas, int nColumnas)
{
    int i, j, Ok=0;
    
    for(i=0;i<nFilas;i++)
    {
        printf("\nElementos de Fila %d:\n", i+1);
        fflush(stdout);
        fpurge(stdin);
        
        for(j=0;j<nColumnas;j++)
        {
            //Es necesario que los valores de los elementos estén entre 0 y 20:
            do
            {
                printf("\nInserta el elemento %d-%d\n", i+1, j+1);
                fflush(stdout);
                fpurge(stdin);
                Ok=scanf("%d", &array[i][j]);
            }while(!Ok || (array[i][j]<0) || (array[i][j]>20));
        }
    }
}

void crear_mapa(int **array, int **estrellas, int nFilas, int nColumnas)
{
    int i, j, suma;
    
    for(i=1;i<nFilas-1;i++)
    {
        for(j=1;j<nColumnas-1;j++)
        {
            if((suma=sumador(array, i, j))>6)
            {
                estrellas[i][j]++;
            }
        }
    }
}

int sumador(int **array,int i,int j)
{
    int suma1, suma2, suma3, sumatotal;
    
    suma1=array[i-1][j-1]+array[i-1][j]+array[i-1][j+1];
    suma2=array[i][j-1]+array[i][j]+array[i][j+1];
    suma3=array[1+1][j-1]+array[1+1][j]+array[1+1][j+1];
    
    sumatotal=(suma1+suma2+suma3)/9;
    
    return sumatotal;
}

void visualizar_mapa(int **estrellas,int nFilas,int nColumnas)
{
    int i, j;
    
    for(i=0;i<nFilas;i++)
    {
        for(j=0;j<nColumnas;j++)
        {
            if(estrellas[i][j]==1)
            {
                printf(" * ");
            }
            else
            {
                printf(" . ");
            }
        }
        
        printf("\n");
    }
}