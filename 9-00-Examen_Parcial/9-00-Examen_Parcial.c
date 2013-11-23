/* 
 * File:   9-00-Examen_Parcial.c
 * Author: Gartzia
 *
 * Created on 22 de noviembre de 2013, 18:04
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void clear_buffer();
void pedir_tamanios(int *filas, int *columnas);
void reserva_bidimensionales(int ***array, int filas, int columnas);
void reserva_unidimensional(int **array3, int filas, int columnas);
void inicializar_array_bi(int **array2, int filas, int columnas);
void inicializar_array_uni(int *array3, int filas, int columnas);
void leer_datos(int **array, int filas, int columnas);
void visualizar_array(int **array, int filas, int columnas);
void moda(int **array, int **array2, int filas, int columnas, int tipo);
void moda_total(int **array, int *array3, int *array4, int filas, int columnas);
void ocho_elementos(int **array, int **array2, int filas, int columnas);
void visualizar_ocho_elemntos(int **array2, int filas, int columnas);

int main()
{
    int **array=NULL, **array2=NULL, *array3=NULL, *array4=NULL, filas, columnas;

    pedir_tamanios(&filas, &columnas);
    reserva_bidimensionales(&array, filas, columnas);
    reserva_bidimensionales(&array2, filas, columnas);
    reserva_unidimensional(&array3, filas, columnas);
    reserva_unidimensional(&array4, filas, columnas);
    inicializar_array_bi(array2, filas, columnas);
    leer_datos(array, filas, columnas);
    visualizar_array(array, filas, columnas);
    printf("\n-------------------------------------------\n");
    //1º apartado
    moda(array, array2, filas, columnas, 0); //moda filas
    //2º apartado
    inicializar_array_bi(array2, filas, columnas);
    moda(array, array2, columnas, filas, 1); //moda columnas
    //3º apartado
    inicializar_array_uni(array3, filas, columnas);
    inicializar_array_uni(array4, filas, columnas);
    moda_total(array, array3, array4, filas, columnas);
    //4º apartado
    inicializar_array_bi(array2, filas, columnas);
    ocho_elementos(array, array2, filas, columnas);
    visualizar_ocho_elemntos(array2, filas, columnas);
    
    return (0);
}

void clear_buffer()
{
    fflush(stdout);
    fpurge(stdin);
}

void pedir_tamanios(int *filas, int *columnas)
{
    int Ok;
    
    do
    {
        printf("\nInserta Filas y Columnas: XX(espacio)XX\n");
        clear_buffer();
        Ok=scanf("%d %d", filas, columnas);
    }while(!Ok || *filas<1 || *columnas<1);
}

void reserva_bidimensionales(int ***array, int filas, int columnas)
{
    int i;
    
    if((*array=(int **)malloc(filas*sizeof(int *)))==NULL)
    {
        printf("\nMemoria no suficiente.\n");
        exit (-1);
    }
    
    for(i=0;i<filas;i++)
    {
        if((*(*array+i)=(int *)malloc(columnas*sizeof(int)))==NULL)
        {
            printf("\nMemoria no suficiente.\n");
            exit (-1);
        }
    }
}

void reserva_unidimensional(int **array3, int filas, int columnas)
{
    if((*array3=(int *)malloc(filas*columnas*sizeof(int)))==NULL)
    {
        printf("\nInsuficiente memoria.\n");
        exit (-1);
    }
}

void inicializar_array_bi(int **array2, int filas, int columnas)
{
    int i, j;
    
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            array2[i][j]=0;
        }
    }
}

void inicializar_array_uni(int *array3, int filas, int columnas)
{
    int i;
    
    for(i=0;i<(filas*columnas);i++)
    {
        array3[i]=0;
    }
}

void leer_datos(int **array, int filas, int columnas)
{
    int i, j;
    
    for(i=0;i<filas;i++)
    {
        printf("\n");
        for(j=0;j<columnas;j++)
        {
            printf("Inserta elemento F%d-C%d:\n", i, j);
            clear_buffer();
            scanf("%d", &array[i][j]);
        }
    }
}

void visualizar_array(int **array, int filas, int columnas)
{
    int i, j;
    
    for(i=0;i<filas;i++)
    {
        printf("\n");
        for(j=0;j<columnas;j++)
        {
            printf("%d ", array[i][j]);

        }
    }
}

void moda(int **array, int **array2, int filas, int columnas, int tipo)
{
    int i, j, k;
    
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            for(k=j+1;k<columnas;k++)
            {
                if(tipo==0)
                {
                    if(array[i][k]==array[i][j])
                    {
                        array2[i][j]++;
                    }
                }
                else
                {
                    if(array[k][i]==array[j][i])
                    {
                        array2[j][i]++;
                    }
                }
            }
        }
    }
    //---------------------------------
    /*printf("Array2\n");
    int h, m;
    
    for(h=0;h<filas;h++)
    {
        for(m=0;m<columnas;m++)
        {
            if(tipo==0)
            {
                printf("\nF%d-C%d: %d\n",h, m, array2[h][m]);
            }
            else
            {
                printf("\nF%d-C%d: %d\n",h, m, array2[m][h]);
            }
        }
    }*/
    //---------------------------------
    for(i=0;i<filas;i++)
    {
        for(j=0, k=0;j<columnas;j++)
        {
            if(tipo==0)
            {
                if(array2[i][j]>array2[i][k])
                {
                    k=j; //guarda el mayor indice de cada fila
                }
            }
            else
            {
                if(array2[j][i]>array2[k][i])
                {
                    k=j; //guarda el mayor indice de cada fila
                }
            }
            
        }
    }
    
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            if(array2[j]==array2[k])
            {
                if(tipo==0)
                {
                    printf("\nModa fila %d: %d\n", i, array[i][j]);
                }
                else
                {
                    printf("\nModa columna %d: %d\n", i, array[j][i]);
                }
            }
        }
    }
}

void moda_total(int **array, int *array3, int *array4, int filas, int columnas)
{
    int f, i, j;
        
    for(f=0;f<filas;f++)
    {
        for(i=0;i<columnas;i++)
        {
            array3[f*filas+i]=array[f][i];
        }
    }

    for(i=0;i<(filas*columnas);i++)
    {
        for(j=i+1;j<(filas*columnas);j++)
        {
            if(array3[j]==array3[i])
            {
                array4[i]++;
            }
        }
    }
    
    printf("\n");
    
    for(i=0;i<(filas*columnas);i++)
    {
        printf("\nEl elemento array[%d], se repite: %d veces.\n",i, array4[i]);
    }
}

void ocho_elementos(int **array, int **array2, int filas, int columnas)
{
    int i=0, j;
    
    //esquinas
    for(j=0;j<columnas;j++)
    {
        array2[i][j]=0;
    }
    j=0;
    for(i=0;i<filas;i++)
    {
        array2[i][j]=0;
    }
    i=filas-1;
    for(j=0;j<columnas;j++)
    {
        array2[i][j]=0;
    }
    j=columnas-1;
    for(i=0;i<filas;i++)
    {
        array2[i][j]=0;
    }
    //centros
    for(i=1;i<filas-1;i++)
    {
        for(j=1;j<columnas-1;j++)
        {
            if(i==j)
            {
                array2[i][j]=array[i][j]*8;
            }
            else
            {
                array2[i][j]+=array[i][j]*(-1);
            }
        }
    }
}

void visualizar_ocho_elemntos(int **array2, int filas, int columnas)
{
    int i, j;
    
    for(i=0;i<filas;i++)
    {
        printf("\n");
        for(j=0;j<columnas;j++)
        {
            printf("%d ", array2[i][j]);
        }
    }
}