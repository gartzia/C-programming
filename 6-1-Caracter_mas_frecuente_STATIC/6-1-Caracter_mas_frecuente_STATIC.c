/* 
 * File:   6-1-Caracter_mas_frecuente_STATIC.c
 * Author: Gartzia
 *
 * Created on 23 de octubre de 2013, 19:04
 */

#include <stdio.h>
#include <stdlib.h>
#define RANGO 10
/*
 * 
 */
void leer_array(char cadena[]);
void inicializar_array(int frecuencia[]);
void maximos(char cadena [], int frecuencia[]);
void visualizar_max_repetidos(char cadena[], int frecuencia[]);

int main()
{
    char cadena[RANGO];
    int frecuencia[RANGO];
    
    printf("\n--------------Contador de carácteres repetidos--------------\n");
    
    //lee los elementos del array
    leer_array(cadena);
    
    //inicializa el array frecuencia
    inicializar_array(frecuencia);
    
    //calcula el número de veces que se repiten los carácteres
    maximos(cadena, frecuencia);
    
    //visualiza los elementos que más se repiten
    visualizar_max_repetidos(cadena, frecuencia);
    
    return 0;
}

void leer_array(char cadena[])
{
    int i;
    
    printf("\nInserta una cadena de carácteres, máximo 10:\n");
    fflush(stdout);
    fpurge(stdin);
    
    for(i=0;i<RANGO;i++)
    {
        scanf("%c", &cadena[i]);
    }
}

void inicializar_array(int frecuencia[])
{
    int i;
    
    for(i=0;i<RANGO;i++)
    {
        *(frecuencia+i)=1;      //-> por referencia (dirección)
        //frecuencia[i]=1;        -> por valor
    }
}

void maximos(char cadena [], int frecuencia[])
{
    int i, j;
    
    for(i=0;i<RANGO;i++)
    {
        for(j=i+1;j<RANGO;j++)
        {
            if(cadena[j]==cadena[i])
            {
                frecuencia[i]++;
            }
        }
    }
}

void visualizar_max_repetidos(char cadena[], int frecuencia[])
{
    int i, j;
    
    for(i=0,j=0;i<RANGO;i++)
    {
        if(frecuencia[i]>frecuencia[j])//pasar el mayor a 'j'
        {
            j=i;
        }
    }
    
    printf("\n");
    
    for(i=0;i<RANGO;i++)
    {
        if(frecuencia[i]==frecuencia[j])
        {
            printf("El carácter '%c' es el más repetido con %d repeticiones -> Aparece %d veces.\n", cadena[i], frecuencia[i]-1, frecuencia[i]);
        }
    }
}