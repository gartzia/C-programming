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
//void reservar_memoria(int **array, int nFilas, int nColumnas);
void llenar_array(int **array, int nFilas, int nColumnas);
void traspuesta(int **array, int ** array_t, int nFilas, int nColumnas);
void visualizar_array(int **array, int nFilas, int nColumnas, int tipo);
void inicializar_indices(int **array, int nFilas, int nColumnas);
void calcular_mayores(int **array, int **indices, int nFilas, int nColumnas);
void calcuar_menores(int **array, int **indices2, int nFilas, int nColumnas);
void comprobar_punto_de_silla(int **array, int **array_t, int **indices, int **indices2, int nFilas, int nColumnas);
int repetido(int i, int j,int **array, int nColumnas);

int main()
{  
    int **array=NULL, **array_t=NULL, **indices=NULL, **indices2=NULL;
    int i;
    int nFilas=0, nColumnas=0;
    
    //solicitar número de Filas y Columnas de la Matriz A:
    nFilas=solicitartamano(nFilas, 0);
    nColumnas=solicitartamano(nColumnas, 1);

    //reservar_memoria para array - Matriz A
    if ((array=(int **)malloc(nFilas*sizeof(int *))) == NULL)
    {
        printf("\nInsuficiente espacio de memoria:\n");
        return (-1);
    }

        for(i=0;i<nFilas;i++)
        {
            array[i]=(int *)malloc(nColumnas*sizeof(int));
        }
    
    
    //reservar_memoria array_t - Matriz A transpuesta
    if ((array_t=(int **)malloc(nColumnas*sizeof(int *))) == NULL)
    {
        printf("\nInsuficiente espacio de memoria:\n");
        return (-1);
    }
  
        for(i=0;i<nColumnas;i++)
        {
            array_t[i]=(int *)malloc(nFilas*sizeof(int));
        }
    
    
    //reservar_memoria para indices - Matriz con números mayores de A
    if ((indices=(int **)malloc(nFilas*sizeof(int *))) == NULL)
    {
        printf("\nInsuficiente espacio de memoria:\n");
        return (-1);
    }

        for(i=0;i<nFilas;i++)
        {
            indices[i]=(int *)malloc(nColumnas*sizeof(int));
        }
   
    
    //reservar_memoria para indices2 - Matriz con números menores de A
    if ((indices2=(int **)malloc(nColumnas * sizeof(int *))) == NULL)
    {
        printf("\nInsuficiente espacio de memoria:\n");
        return (-1);
    }
  
        for(i=0;i<nColumnas;i++)
        {
            indices2[i]=(int *)malloc(nFilas*sizeof(int));
        }
    
    
    
    //Recoger los valores de la Matriz A:
    llenar_array(array, nFilas, nColumnas);
 
    //Visualizar Matriz A:
    visualizar_array(array, nFilas, nColumnas, 0);
    
    //Matriz A Transpuesta:
    traspuesta(array, array_t, nFilas, nColumnas);
    
    //Visualizar Matriz A Transpuesta
    visualizar_array(array_t, nFilas, nColumnas, 1);

    //Inicializar arrays: indices, indices2, indices_t y indices2_t
    inicializar_indices(indices, nFilas, nColumnas);
    inicializar_indices(indices2, nColumnas, nFilas); //para transpuesta

    
    //Clacular elemntos mayores de cada Fila del la Matriz A:
    calcular_mayores(array, indices, nFilas, nColumnas); 
    //Clacular elemntos menores de cada Fila del la Matriz A Transpuesta:
    calcuar_menores(array_t, indices2, nColumnas, nFilas);     
    //Comparar mayores-menores (A-At):
    comprobar_punto_de_silla(array, array_t, indices, indices2, nFilas, nColumnas);
    
    inicializar_indices(indices, nFilas, nColumnas);
    inicializar_indices(indices2, nColumnas, nFilas);
    
    
    //Clacular elemntos mayores de cada Fila del la Matriz A transpuesta:
    calcular_mayores(array_t, indices2, nColumnas, nFilas); 
    //Clacular elemntos menores de cada Fila del la Matriz A:
    calcuar_menores(array, indices, nFilas, nColumnas);
    //Comparar menores-mayores (A-At):
    comprobar_punto_de_silla(array, array_t, indices, indices2, nFilas, nColumnas);

    
    return 0;
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
            scanf("%1d", &array[i][j]);
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
        for(i=0;i<nFilas;i++)
        {
            printf("\n");
            printf("\t");
            for(j=0;j<nColumnas;j++)
            {
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Matriz A Transpuesta:\n");
        for(i=0;i<nColumnas;i++)
        {
            printf("\n");
            printf("\t");
            for(j=0;j<nFilas;j++)
            {
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }
    }
}

void inicializar_indices(int **array, int nFilas, int nColumnas)
{
    int i, j;
    
    for(i=0;i<nFilas;i++)
    {
        for(j=0;j<nColumnas;j++)
        {
            array[i][j]=0;
        }
    }
}

void calcular_mayores(int **array, int **indices, int nFilas, int nColumnas)
{
    int a, i, j;
    
    printf("\n");
    for(a=0;a<nFilas;a++)
    {
        for(i=0,j=0;i<nColumnas;i++)
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

void calcuar_menores(int **array, int **indices2, int nFilas, int nColumnas)
{
    int a, i, j;
    
    printf("---------------\n");
    for(a=0;a<nFilas;a++)
    {
        for(i=0,j=0;i<nColumnas;i++)
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

void comprobar_punto_de_silla(int **array, int **array_t, int **indices, int **indices2, int nFilas, int nColumnas)
{
    int i, j, repes;
    for(i=0;i<nFilas;i++)
    {
        for(j=0;j<nColumnas;j++)
        {
            if(indices[i][j]!=0)
            {
                if(indices[i][j]==indices2[j][i])
                {
                    if((repes=repetido(i, j, array, nColumnas)<2) && (repes=repetido(j, i, array_t, nColumnas)<2))
                    {
                        printf("\nPunto de Silla: %d -> A:%d-%d\n", indices[i][j], i+1,j+1);
                    }
                }
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