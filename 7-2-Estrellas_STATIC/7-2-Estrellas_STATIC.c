/* 
 * File:   7-2-Estrellas_STATIC.c
 * Author: Gartzia
 *
 * Created on 2 de noviembre de 2013, 20:35
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int solicitar_Filas(int numero);
int solicitar_Columnas(int numero);
void inicializar_mapa(int estrellas[][4]);
void leer_array(int array[][4]);
void crear_mapa(int array[][4], int estrellas[][4]);
int sumador(int array[][4],int i,int j);
void visualizar_mapa(int estrellas[][4]);

int main()
{
    int array[4][4], estrellas[4][4];
    
    inicializar_mapa(estrellas);
    
    leer_array(array);
    
    crear_mapa(array, estrellas);
    
    visualizar_mapa(estrellas);

    return (0);
}

void inicializar_mapa(int estrellas[][4])
{
    int i, j;
    
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            estrellas[i][j]=0;
        }
    }
}

void leer_array(int array[][4])
{
    int i, j, Ok=0;
    
    for(i=0;i<4;i++)
    {
        printf("\nElementos de Fila %d:\n", i+1);
        fflush(stdout);
        fpurge(stdin);
        
        for(j=0;j<4;j++)
        {
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

void crear_mapa(int array[][4], int estrellas[][4])
{
    int i, j, suma;
    
    for(i=1;i<4-1;i++)
    {
        for(j=1;j<4-1;j++)
        {
            if((suma=sumador(array, i, j))>6)
            {
                estrellas[i][j]++;
            }
        }
    }
}

int sumador(int array[][4],int i,int j)
{
    int suma1, suma2, suma3, sumatotal;
    
    suma1=array[i-1][j-1]+array[i-1][j]+array[i-1][j+1];
    suma2=array[i][j-1]+array[i][j]+array[i][j+1];
    suma3=array[1+1][j-1]+array[1+1][j]+array[1+1][j+1];
    
    sumatotal=(suma1+suma2+suma3)/9;
    
    return sumatotal;
}

void visualizar_mapa(int estrellas[][4])
{
    int i, j;
    
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
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