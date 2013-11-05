/* 
 * File:   7-1-Punto_de_Silla_DYNAMIC.c
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
void llenar_array(int **array, int nFilas, int nColumnas);
void visualizar_array(int **array, int nFilas, int nColumnas);
int calcular_mayores(int **array, int nFilas, int nColumnas, int no_psilla);
int calcuar_menores(int **array, int nFilas, int nColumnas, int no_psilla);
void visualizar_no_psilla(int no_psilla);

int main()
{  
    int **array=NULL;  //bidimensional (Matriz A)
    int nFilas=0, nColumnas=0, no_psilla=0;
    
    //solicitar número de Filas y Columnas de la Matriz A:
    nFilas=solicitartamano(nFilas, 0);
    nColumnas=solicitartamano(nColumnas, 1);

    //-----Reserva de memoria BIDIMENSIONAL-----
    //para array - Matriz A
    array=reservar_memoria(nFilas, nColumnas);      
    
    //-----LECTURA DE DATOS-----
    //Recoger los valores de la Matriz A:
    llenar_array(array, nFilas, nColumnas);
    
    //-----VISUALIZACIÓN DE DATOS-----
    //Visualizar Matriz A:
    visualizar_array(array, nFilas, nColumnas);
    
    //-----COMPRARACIÓN MAYORES-MENORES-----
    no_psilla=calcular_mayores(array, nFilas, nColumnas, no_psilla); 
    no_psilla=calcuar_menores(array, nFilas, nColumnas, no_psilla);    

    //-----VISUALIZACIÓN DE DATOS-----
    //mostrar si no hay punto de silla
    visualizar_no_psilla(no_psilla);
    
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

void visualizar_array(int **array, int nFilas, int nColumnas)
{
    int i, j;
    
    printf("\n");
    
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

int calcular_mayores(int **array, int nFilas, int nColumnas, int no_psilla)
{
    int i, j, k, f, contador=0;
    
    printf("\n");
    
    for(i=0,k=0;i<nFilas;i++)
    {
        contador=0;
        
        for(j=0;j<nColumnas;j++)
        {
            if(array[i][j]>array[i][k])
            {
                k=j; //mayor de la fila
            }
        }
        
        for(f=0;f<nFilas;f++)
        {
            if(array[f][k]>array[i][k])
            {
                contador++; // menor de la columna
            }
        }
        
        if(contador==nFilas-1)
        {
            printf("---------------\n");
            printf("\nPunto de Silla: %d -> A:%d-%d\n", array[i][k], i+1,k+1);
            no_psilla=1;
        }
    }
    
    return no_psilla;
}

int calcuar_menores(int **array, int nFilas, int nColumnas, int no_psilla)
{
    int i, j, k, f, contador=0;
    
    printf("\n");
    
    for(i=0,k=0;i<nFilas;i++)
    {
        contador=0;
        
        for(j=0;j<nColumnas;j++)
        {
            if(array[i][j]<array[i][k])
            {
                k=j; //menr de la fila
            }
        }
        
        for(f=0;f<nFilas;f++)
        {
            if(array[f][k]<array[i][k])
            {
                contador++; // mayor de la columna
            }
        }
        
        if(contador==nFilas-1)
        {
            printf("---------------\n");
            printf("\nPunto de Silla: %d -> A:%d-%d\n", array[i][k], i+1,k+1);
            no_psilla=1;
        }
    }
    
    return no_psilla;
}

void visualizar_no_psilla(int no_psilla)
{
    if(no_psilla==0)
    {
        printf("\nNo hay punto de silla.\n");
    }
}
//---FIN---