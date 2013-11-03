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
int solicitarFilas(int nFilas, int Ok);
int solicitarColumnas(int nColumnas, int Ok);
//void reservar_memoria(int **array, int nFilas, int nColumnas);
void llenar_array(int **array, int nFilas, int nColumnas);
void visualizar_array(int **array, int nFilas, int nColumnas, int tipo);
void inicializar_indices_mayores(int **array, int nFilas, int nColumnas);
void calcular_mayores(int **array, int **indices, int nFilas, int nColumnas);
void calcuar_menores(int **array, int **indices2, int nFilas, int nColumnas);
void traspuesta(int **array, int ** array_t, int nFilas, int nColumnas);
void comprobar_punto_de_silla(int **array, int **array_t, int **indices, int **indices2, int **indices_t, int **indices2_t, int nFilas, int nColumnas);
int repetido(int i, int j,int **array, int nColumnas);

int main()
{  
    int **array=NULL, **array_t=NULL, **indices=NULL, **indices2=NULL, **indices_t=NULL, **indices2_t=NULL;
    int i,j;
    int Ok=0, nFilas=0, nColumnas=0;
    int tipo=0;
    
    //solicitar número de Filas y Columnas de la Matriz A:
    nFilas=solicitarFilas(nFilas, Ok);
    nColumnas=solicitarColumnas(nColumnas, Ok);

    //reservar_memoria para array - Matriz A
    if ((array=(int **)malloc(nFilas * sizeof(int *))) == NULL)
    {
        printf("\nInsuficiente espacio de memoria:\n");
        return (-1);
    }
    else
    {
        for(i=0;i<nFilas;i++)
        {
            array[i]=(int *)malloc(nColumnas*sizeof(int));
        }
    }
    
    //reservar_memoria array_t - Matriz A transpuesta
    if ((array_t=(int **)malloc(nFilas * sizeof(int *))) == NULL)
    {
        printf("\nInsuficiente espacio de memoria:\n");
        return (-1);
    }
    else
    {
        for(i=0;i<nFilas;i++)
        {
            array_t[i]=(int *)malloc(nColumnas*sizeof(int));
        }
    }
    
    //reservar_memoria para indices - Matriz con números mayores de A
    if ((indices=(int **)malloc(nFilas * sizeof(int *))) == NULL)
    {
        printf("\nInsuficiente espacio de memoria:\n");
        return (-1);
    }
    else
    {
        for(i=0;i<nFilas;i++)
        {
            indices[i]=(int *)malloc(nColumnas*sizeof(int));
        }
    }
    
    //reservar_memoria para indices2 - Matriz con números menores de A
    if ((indices2=(int **)malloc(nFilas * sizeof(int *))) == NULL)
    {
        printf("\nInsuficiente espacio de memoria:\n");
        return (-1);
    }
    else
    {
        for(i=0;i<nFilas;i++)
        {
            indices2[i]=(int *)malloc(nColumnas*sizeof(int));
        }
    }
    
    //reservar_memoria para indices_t - Matriz con números mayores de A
    if ((indices_t=(int **)malloc(nFilas * sizeof(int *))) == NULL)
    {
        printf("\nInsuficiente espacio de memoria:\n");
        return (-1);
    }
    else
    {
        for(i=0;i<nFilas;i++)
        {
            indices_t[i]=(int *)malloc(nColumnas*sizeof(int));
        }
    }
    
    //reservar_memoria para indices2_t - Matriz con números menores de A
    if ((indices2_t=(int **)malloc(nFilas * sizeof(int *))) == NULL)
    {
        printf("\nInsuficiente espacio de memoria:\n");
        return (-1);
    }
    else
    {
        for(i=0;i<nFilas;i++)
        {
            indices2_t[i]=(int *)malloc(nColumnas*sizeof(int));
        }
    }
    
    //Recoger los valores de la Matriz A:
    llenar_array(array, nFilas, nColumnas);
 
    //Visualizar Matriz A:
    visualizar_array(array, nFilas, nColumnas, tipo);

    //Inicializar arrays: indices, indices2, indices_t y indices2_t
    inicializar_indices_mayores(indices, nFilas, nColumnas);
    inicializar_indices_mayores(indices2, nFilas, nColumnas);
    inicializar_indices_mayores(indices_t, nFilas, nColumnas);
    inicializar_indices_mayores(indices2_t, nFilas, nColumnas);
    
    //Clacular elemntos mayores de cada Fila del la Matriz A:
    calcular_mayores(array, indices, nFilas, nColumnas); 
    //Clacular elemntos menores de cada Fila del la Matriz A:
    calcuar_menores(array, indices2, nFilas, nColumnas);
    
    //Matriz A Transpuesta:
    traspuesta(array, array_t, nFilas, nColumnas);
    
    //Visualizar Matriz A Transpuesta
    tipo=1;
    visualizar_array(array_t, nFilas, nColumnas, tipo);
    
    //Clacular elemntos mayores de cada Fila del la Matriz A Transpuesta:
    calcular_mayores(array_t, indices_t, nFilas, nColumnas); 
    //Clacular elemntos menores de cada Fila del la Matriz A:
    calcuar_menores(array_t, indices2_t, nFilas, nColumnas);

    
    //Comparar mayores-menores (A-At) y menores-mayores (A-At):
    comprobar_punto_de_silla(array, array_t, indices, indices2, indices_t, indices2_t, nFilas, nColumnas);
        
    
    return 0;
}

int solicitarFilas(int nFilas, int Ok)
{
    do
    {
        printf("\nInserta el número de Filas:\n");
        Ok=scanf("%d", &nFilas);
        fflush(stdin);  
    }while(!Ok && nFilas<1);
    
    return nFilas;
}

int solicitarColumnas(int nColumnas, int Ok)
{
    do
    {
        printf("\nInserta el número de Columnas:\n");
        Ok=scanf("%d", &nColumnas);
        fflush(stdin);
    }while(!Ok && nColumnas<1);
    
    return nColumnas;
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
        printf("Matriz A transpuesta:\n");
    }
    
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

//---------------

void inicializar_indices_mayores(int **array, int nFilas, int nColumnas)
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

void traspuesta(int **array, int ** array_t, int nFilas, int nColumnas)
{
    int a, i;
    
    for(a=0;a<nFilas;a++)
    {
        for(i=0;i<nFilas;i++)
        {
            array_t[i][a]=array[a][i];
        }
    }
}

void comprobar_punto_de_silla(int **array, int **array_t, int **indices, int **indices2, int **indices_t, int **indices2_t, int nFilas, int nColumnas)
{
    int i, j, repes;
    for(i=0;i<nFilas;i++)
    {
        for(j=0;j<nFilas;j++)
        {
            if(indices[i][j]!=0)
            {
                if(indices[i][j]==indices2_t[j][i])
                {
                    if((repes=repetido(i, j, array, nColumnas)<2) && (repes=repetido(j, i, array_t, nColumnas)<2))
                    {
                        printf("\nPunto de Silla: %d -> A:%d-%d\n", indices[i][j], i+1,j+1);
                    }
                }
            }
            if(indices2[i][j]!=0)
            {
                if(indices2[i][j]==indices_t[j][i])
                {
                    if((repes=repetido(i, j, array, nColumnas)<2) && (repes=repetido(j, i, array_t, nColumnas)<2))
                    {
                        printf("\nPunto de Silla: %d -> A:%d-%d", indices2[i][j], i+1, j+1);
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