/* 
 * File:   7-3-Punto_de_Silla_DYNAMIC.c
 * Author: Gartzia
 *
 * Created on 29 de octubre de 2013, 18:32
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int solicitartamano(int nFilas, int a);
int **reservar_memoria(int nFilas, int nColumnas); //bidimensionales
int *reservar_memoria2(int nColumnas); //unidimensionales
void llenar_array(int **array, int nFilas, int nColumnas);
void traspuesta(int **array, int ** array_t, int nFilas, int nColumnas);
void visualizar_array(int **array, int nFilas, int nColumnas, int tipo);
void inicializar_indices(int *array, int nColumnas);
void calcular_mayores(int **array, int *indices, int nFilas, int nColumnas);
void calcuar_menores(int **array, int *indices2, int nFilas, int nColumnas);
void comprobar_punto_de_silla(int **array, int **array_t, int *indices, int *indices2, int nFilas, int nColumnas);
int repetido(int i, int j,int **array, int nColumnas);

int main()
{  
    int **array=NULL, **array_t=NULL;  //bidimensionales (Matriz A y Matriz A Traspuesta)
    int *indices=NULL, *indices2=NULL; //unidimensionales
    int nFilas=0, nColumnas=0;
    
    //solicitar número de Filas y Columnas de la Matriz A:
    nFilas=solicitartamano(nFilas, 0);
    nColumnas=solicitartamano(nColumnas, 1);

    //-----Reserva de memoria BIDIMENSIONAL-----
    //para array - Matriz A
    array=reservar_memoria(nFilas, nColumnas);      
    //para array_t - Matriz A transpuesta
    array_t=reservar_memoria(nColumnas, nFilas);
    
    //-----Reserva de memoria UNIDIMENSIONAL-----
    //para indices - Matriz con números mayores de A
    indices=reservar_memoria2(nFilas);  
    //para indices2 - Matriz con números menores de A
    indices2=reservar_memoria2(nColumnas);
    
    //-----LECTURA DE DATOS-----
    //Recoger los valores de la Matriz A:
    llenar_array(array, nFilas, nColumnas);
    //Matriz A Transpuesta:
    traspuesta(array, array_t, nFilas, nColumnas);
    
    //-----VISUALIZACIÓN DE DATOS-----
    //Visualizar Matriz A:
    visualizar_array(array, nFilas, nColumnas, 0);
    //Visualizar Matriz A Transpuesta
    visualizar_array(array_t, nColumnas, nFilas, 1);
    
    //-----COMPRARACIÓN MAYORES-MENORES-----
    //Clacular elemntos mayores de cada Fila del la Matriz A:
    calcular_mayores(array, indices, nFilas, nColumnas); 
    //Clacular elemntos menores de cada Fila del la Matriz A Transpuesta:
    calcuar_menores(array_t, indices2, nColumnas, nFilas);     
    //Comparar mayores-menores (A-At):
    comprobar_punto_de_silla(array, array_t, indices, indices2, nFilas, nColumnas);
    
    //COMPARACIÓN MENORES-MAYORES-----
    //Clacular elemntos mayores de cada Fila del la Matriz A transpuesta:
    calcular_mayores(array_t, indices2, nColumnas, nFilas); 
    //Clacular elemntos menores de cada Fila del la Matriz A:
    calcuar_menores(array, indices, nFilas, nColumnas);
    //Comparar menores-mayores (A-At):
    comprobar_punto_de_silla(array, array_t, indices, indices2, nFilas, nColumnas);
    
    return 0;
}

int **reservar_memoria(int nFilas, int nColumnas)
{
    int **array=NULL, i;
    
    if ((array=(int **)malloc(nFilas*sizeof(int *))) == NULL)
    {
        printf("\nInsuficiente espacio de memoria:\n");
        //return (-1);
    }

        for(i=0;i<nFilas;i++)
        {
            array[i]=(int *)malloc(nColumnas*sizeof(int));
        }
    
    return array;
}

int *reservar_memoria2(int nColumnas)
{
    int *array=NULL;
            
    if ((array=(int *)malloc(nColumnas*sizeof(int))) == NULL)
    {
        printf("\nInsuficiente espacio de memoria:\n");
        //return (-1);
    }
    
    return array;
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

void llenar_array(int **array, int nFilas, int nColumnas)
{
    int i, j;
    
    for(i=0;i<nFilas;i++)
    {
        printf("\nFila %d:\n", i);
        for(j=0;j<nColumnas;j++)
        {
          //scanf("%1d", &array[i][j]); //numero de 0 a 9, recoge dígito a dígito
          scanf("%d", &array[i][j]); //numeros enteros, separados por espacios o Enters, etc.
        }
    }
}

void traspuesta(int **array, int **array_t, int nFilas, int nColumnas)
{
    int a, i;
    
    for(a=0;a<nFilas;a++)
    {
        for(i=0;i<nColumnas;i++)
        {
            array_t[i][a]=array[a][i];
        }
    }
}

void visualizar_array(int **array, int nFilas, int nColumnas, int tipo)
{
    int i, j;
    
    printf("\n");
    
    if(tipo==0)
    {
        printf("Matriz A:\n");
    }
    else
    {
        printf("Matriz A Traspuesta:\n");
    }
    
    for(i=0;i<nFilas;i++)
    {
        printf("\n");
        printf("\t");
        for(j=0;j<nColumnas;j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    
    
}

void calcular_mayores(int **array, int *indices, int nFilas, int nColumnas)
{
    int i, j, k;
    
    printf("\n");
    
    for(i=0;i<nFilas;i++)
    {
        for(j=0,k=0;j<nColumnas;j++)
        {
            if(array[i][j]>array[i][k])
            {
                k=j;
            }
        }
        indices[i]=k; //cada columna de indices, es una fila de A, y guarda el indice del mayor
    }
}

void calcuar_menores(int **array, int *indices2, int nFilas, int nColumnas)
{
    int i, j, k;
    
    for(i=0;i<nFilas;i++)
    {
        for(j=0,k=0;j<nColumnas;j++)
        {
            if(array[i][j]<array[i][k])
            {
                k=j;
            }
        }
        indices2[i]=k; //cada columna de indices2, es la fila de At, y guarda el indice del menor
    }
}

void comprobar_punto_de_silla(int **array, int **array_t, int *indices, int *indices2, int nFilas, int nColumnas)
{
    int i, j, k, repes;
    
    for(i=0;i<nFilas;i++)
    {
        j=indices[i];
        k=indices2[j]; //k=indices2[indices[i];
        
        if(array[i][j]==array_t[j][k])
        {
            if((repes=repetido(i, j, array, nColumnas)<2) && (repes=repetido(j, i, array_t, nColumnas)<2))
            {
                printf("---------------\n");
                printf("\nPunto de Silla: %d -> A:%d-%d\n", array[i][j], i+1,j+1);
            }
        }
    }    
}

int repetido(int i, int j,int **array, int nColumnas)
{
    int k, frecuencia=0;
    
    for(k=0;k<nColumnas;k++)
    {
        if(array[i][k]==array[i][j])
        {
            frecuencia++;
        }
    }

    return frecuencia;
}
//---FIN---
