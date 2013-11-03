/* 
 * File:   6-4-Matematica_Array_DYNAMIC.c
 * Author: Gartzia
 *
 * Created on 28 de octubre de 2013, 19:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * 
 */
int tamano_array(int tamano);
void leer_array(int *cadena, int tamano);
int media_aritmetica(int *cadena, int tamano);
void visualiza_media(int x_ma);
void moda(int *cadena, int *cadena2, int frecuencia, int tamano);
void inicializar_array(int *cadena2, int tamano);
void comparar_arrays(int *cadena, int *cadena2, int tamano);
void visualiar_moda(int *cadena, int *cadena2, int tamano, int frecuencia);
int desviacion_tipica(int *cadena, int tamano);
void visualiza_desviacion(int y);

int main()
{
    int *cadena, *cadena2, tamano=0, frecuencia=0, x_ma, y;
    
    tamano=tamano_array(tamano);
    
    //reserva de memoria para cadena
    if((cadena=(int *)malloc(tamano*sizeof(int)))==NULL)
    {
        printf("\nInsuficiente memoria libre.\n");
        return -1;
    }
    
    //reserva de memoria para cadena2
    if((cadena2=(int *)malloc(tamano*sizeof(int)))==NULL)
    {
        printf("\nInsuficiente memoria para calcular la 'Moda'.\n");
        return -1;
    }
    
    leer_array(cadena, tamano);
    x_ma=media_aritmetica(cadena, tamano);
    visualiza_media(x_ma);
    moda(cadena, cadena2, frecuencia, tamano);
    y=desviacion_tipica(cadena, tamano);
    visualiza_desviacion(y);

    return (0);
}
int tamano_array(int tamano)
{
    int Ok=0;
    do
    {
        printf("\nDe que tamaño quieres el array?: (Máx. 50)\n");
        fflush(stdout);
        fpurge(stdin);
        Ok=scanf("%d", &tamano);
    }while(!Ok || tamano<1 || tamano>50);
    
    return tamano;
}

void leer_array(int *cadena, int tamano)
{
    int i;
    
    printf("\nInserta el array:");
    fflush(stdout);
    fpurge(stdin);
    for(i=0;i<tamano;i++)
    {
        scanf("%1d", &cadena[i]);
    }
    
}

int media_aritmetica(int *cadena, int tamano)
{
   int i, x=0;
    
    for(i=0;i<tamano;i++)
    {
        x+=cadena[i];
    }
    
    x/=tamano;
    
    return x;
}

void visualiza_media(int x_ma)
{
    printf("\nLa media aritmética es: %d.\n", x_ma);
}

void moda(int *cadena, int *cadena2, int frecuencia, int tamano)
{    
    inicializar_array(cadena2,tamano);
    comparar_arrays(cadena, cadena2, tamano);
    visualiar_moda(cadena, cadena2, tamano, frecuencia);
}

void inicializar_array(int *cadena2, int tamano)
{
    int i;
    
    for(i=0;i<tamano;i++)
    {
        *(cadena2+i)=1;
    }
}

void comparar_arrays(int *cadena, int *cadena2, int tamano)
{
    int i, j;
    
    for(i=0;i<tamano;i++)
    {
        for(j=i+1;j<tamano;j++)
        {
            if(cadena[j]==cadena[i])
            {
                cadena2[i]++;
            }
        }
    }
}

void visualiar_moda(int *cadena, int *cadena2, int tamano, int frecuencia)
{
    int i, j;
    
    for(i=0,j=0;i<tamano;i++)
    {
        if(cadena2[i]>cadena2[j])
        {
            j=i;
        }
    }
    
    for(i=0;i<tamano;i++)
    {
        if(cadena2[i]==cadena2[j])
        {
            printf("\nEl número '%d' es el más repetido.\n", cadena[i]);
        }
    }
}

int desviacion_tipica(int *cadena, int tamano)
{
    int i, x_ma, y=0;
    
    x_ma=media_aritmetica(cadena, tamano);

    for(i=0;i<tamano;i++)
    {
        y+=(x_ma-cadena[i])*(x_ma-cadena[i]);
    }
    y=sqrt(y);
    y/=tamano;
    
    return y;
}

void visualiza_desviacion(int y)
{
    printf("\nLa desviación típica es: %d.\n", y);
}