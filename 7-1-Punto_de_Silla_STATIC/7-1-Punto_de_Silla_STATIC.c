/* 
 * File:   7-1-Punto_de_Silla_STATIC.c
 * Author: Gartzia
 *
 * Created on 29 de octubre de 2013, 18:32
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void llenar_array(int array[][2]);
void visualizar_array(int array[][2], int tipo);
void inicializar_indices_mayores(int array[][2]);
void calcular_mayores(int array[][2], int indices[][2]);
void calcuar_menores(int array[][2], int indices2[][2]);
void traspuesta(int array[][2], int array_t[][2]);
void comprobar_punto_de_silla(int array[][2], int array_t[][2], int indices[][2], int indices2[][2]);
int repetido(int i, int j, int array[][2]);

int main()
{  
    int array[2][2], array_t[2][2], indices[2][2], indices2[2][2];
    int tipo=0;
    
    printf("\nInserta los elementos para una matriz de 2X2:\n");
    
    //llenar_array a
    llenar_array(array);

    //visualizar_array
    visualizar_array(array, tipo);
    
    //inicializar indices, indices2, indices_t y indices2_t
    inicializar_indices_mayores(indices);
    inicializar_indices_mayores(indices2);
    
    //traspuesta
    traspuesta(array, array_t);
    
    //visualizar_array t
    tipo=1;
    visualizar_array(array_t, tipo);
    
    //Mayores para array a
    calcular_mayores(array, indices); 
    //Menores para array a
    calcuar_menores(array_t, indices2);
    
    //Comparar indices de array y array_t (indices, indices2 y indices_t, indices2_t))
    comprobar_punto_de_silla(array, array_t, indices, indices2);
    
    //inicializar indices, indices2, indices_t y indices2_t
    inicializar_indices_mayores(indices);
    inicializar_indices_mayores(indices2);
    
    //Mayores para array t
    calcular_mayores(array_t, indices2); 
    //Menores para array t
    calcuar_menores(array, indices);
   
    //Comparar indices de array y array_t (indices, indices2 y indices_t, indices2_t))
    comprobar_punto_de_silla(array, array_t, indices, indices2);
        
    
    return 0;
}

void llenar_array(int array[][2])
{
    int i, j;
    
    for(i=0;i<2;i++)
    {
        printf("\nFila %d:\n", i);
        for(j=0;j<2;j++)
        {
            scanf("%1d", &array[i][j]);
        }
    }
}

void visualizar_array(int array[][2], int tipo)
{
    int i, j;
    
    printf("\n");
    
    if(tipo==0)
    {
        printf("Matriz A:\n");
    }
    else
    {
        printf("Matriz A transpuesta:\n");
    }
    
    for(i=0;i<2;i++)
    {
        printf("\n");
        printf("\t");
        for(j=0;j<2;j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

//---------------

void inicializar_indices_mayores(int array[][2])
{
    int i, j;
    
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            array[i][j]=0;
        }
    }
}

void calcular_mayores(int array[][2], int indices[][2])
{
    int a, i, j;
    
    printf("\n");
    for(a=0;a<2;a++)
    {
        for(i=0,j=0;i<2;i++)
        {
            if(array[a][i]>array[a][j])
            {
                j=i;
            }
        }
        indices[a][j]=array[a][j];
        printf("Mayores A%d-%d: %d\n", a, j, indices[a][j]);
    }
}

void calcuar_menores(int array[][2], int indices2[][2])
{
    int a, i, j;
    
    printf("---------------\n");
    for(a=0;a<2;a++)
    {
        for(i=0,j=0;i<2;i++)
        {
            if(array[a][i]<array[a][j])
            {
                j=i;
            }
        }
        indices2[a][j]=array[a][j];
        printf("Menores A%d-%d: %d\n", a,j, indices2[a][j]);
    }
}

void traspuesta(int array[][2], int array_t[][2])
{
    int a, i;
    
    for(a=0;a<2;a++)
    {
        for(i=0;i<2;i++)
        {
            array_t[i][a]=array[a][i];
        }
    }
}

void comprobar_punto_de_silla(int array[][2], int array_t[][2], int indices[][2], int indices2[][2])
{
    int i, j, repes;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            if(indices[i][j]!=0)
            {
                if(indices[i][j]==indices2[j][i])
                {
                    if((repes=repetido(i, j, array)<2) && (repes=repetido(j, i, array_t)<2))
                    {
                        printf("\nPunto de Silla: %d -> A:%d-%d\n", indices[i][j], i+1,j+1);
                    }
                }
            }
        }
    }
}

int repetido(int i, int j, int array[][2])
{
    int k, frecuencia=0;
    
    for(k=0;k<2;k++)
    {
        if(array[i][k]==array[i][j])
        {
            frecuencia++;
        }
    }

    return frecuencia;
}