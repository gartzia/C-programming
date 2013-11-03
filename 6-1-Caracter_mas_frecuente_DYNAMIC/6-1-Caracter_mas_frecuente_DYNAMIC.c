/* 
 * File:   6-1-Caracter_mas_frecuente_STATIC.c
 * Author: Gartzia
 *
 * Created on 23 de octubre de 2013, 19:04
 */

#include <stdio.h>
#include <stdlib.h>
/*
 * 
 */
int solicitar_numero_caracteres(int nColumnas);
void leer_array(char *cadena, int nColumnas);
void inicializar_array(int *frecuencia, int nColumnas);
void maximos(char *cadena, int *frecuencia, int nColumnas);
void visualizar_max_repetidos(char *cadena, int *frecuencia, int nColumnas);

int main()
{
    int nColumnas=10;
    char *cadena=NULL;
    int *frecuencia=NULL;
    
    printf("\n--------------Contador de carácteres repetidos--------------\n");
    
    //solicitar el tamaño del array
    nColumnas=solicitar_numero_caracteres(nColumnas);
    
    //reservar memoria para cadena
    if((cadena=(char *)malloc(nColumnas*sizeof(char)))==NULL)
    {
        printf("\nNo hay suficiente memoria disponible.\n");
        return -1;
    }
    
    //reservar memoria para frecuencia
    if((frecuencia=(int *)malloc(nColumnas*sizeof(int)))==NULL)
    {
        printf("\nNo hay suficiente memoria disponible.\n");
        return -1;
    }
    
    //lee los elementos del array
    leer_array(cadena, nColumnas);
    
    //inicializa el array frecuencia
    inicializar_array(frecuencia, nColumnas);
    
    //calcula el número de veces que se repiten los carácteres
    maximos(cadena, frecuencia, nColumnas);
    
    //visualiza los elementos que más se repiten
    visualizar_max_repetidos(cadena, frecuencia, nColumnas);
    
    return 0;
}
int solicitar_numero_caracteres(int nColumnas)
{
    int Ok=0;
    
    do
    {
        printf("\nCuantos carácteres quieres insertar? (los espacios en blanco se tendrán en cuenta)\n");
        fflush(stdout);
        fpurge(stdin);
        scanf("%d", &nColumnas);
    }while(!Ok && nColumnas<1);
    
    return nColumnas;
}

void leer_array(char *cadena, int nColumnas)
{
    int i;
    
    printf("\nInserta la cadena de carácteres:\n");
    fflush(stdout);
    fpurge(stdin);
    
    for(i=0;i<nColumnas;i++)
    {
        scanf("%c", &cadena[i]);
    }
}

void inicializar_array(int *frecuencia, int nColumnas)
{
    int i;
    
    for(i=0;i<nColumnas;i++)
    {
        *(frecuencia+i)=1;      //-> por referencia (dirección)
        //frecuencia[i]=1;        -> por valor
    }
}

void maximos(char *cadena, int *frecuencia, int nColumnas)
{
    int i, j;
    
    for(i=0;i<nColumnas;i++)
    {
        for(j=i+1;j<nColumnas;j++)
        {
            if(cadena[j]==cadena[i])
            {
                frecuencia[i]++;
            }
        }
    }
}

void visualizar_max_repetidos(char *cadena, int *frecuencia, int nColumnas)
{
    int i, j;
    
    for(i=0,j=0;i<nColumnas;i++)
    {
        if(frecuencia[i]>frecuencia[j])//pasar el mayor a 'j'
        {
            j=i;
        }
    }
    
    printf("\n");
    
    for(i=0;i<nColumnas;i++)
    {
        if(frecuencia[i]==frecuencia[j])
        {
            printf("El carácter '%c' es el más repetido con %d repeticiones -> Aparece %d veces.\n", cadena[i], frecuencia[i]-1, frecuencia[i]);
        }
    }
}