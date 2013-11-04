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
char *reserva_memoria(int ncolumnas);
int *reserva_memoria2(int ncolumnas);
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
    
    //-----RESERVA DE MEMORIA-----
    //para cadena
    cadena=reserva_memoria(nColumnas);
    //para frecuencia
    frecuencia=reserva_memoria2(nColumnas);
    
    //-----LECTURA DE DATOS-----
    //lee los elementos del array
    leer_array(cadena, nColumnas);
    //inicializa el array frecuencia
    inicializar_array(frecuencia, nColumnas);
    
    //-----TRATAMIENTO DE DATOS-----
    //calcula el número de veces que se repiten los carácteres
    maximos(cadena, frecuencia, nColumnas);
    
    //VISUALIZACIÓN DE DATOS
    //elementos que más se repiten
    visualizar_max_repetidos(cadena, frecuencia, nColumnas);
    
    return 0;
}

int solicitar_numero_caracteres(int nColumnas)
{
    int Ok=0;
    
    do
    {
        //debe ser un número entero mayor que cero
        printf("\nCuantos carácteres quieres insertar? (los espacios en blanco se tendrán en cuenta)\n");
        fflush(stdout);
        fpurge(stdin);
        scanf("%d", &nColumnas);
    }while(!Ok && nColumnas<1);
    
    return nColumnas;
}

char *reserva_memoria(int nColumnas)
{
    char *array=NULL;
    
    if((array=(char *)malloc(nColumnas*sizeof(char)))==NULL)
    {
        printf("\nNo hay suficiente memoria disponible.\n");
        return NULL;
    }
    
    return array;
}

int *reserva_memoria2(int nColumnas)
{
    int *array=NULL;
    
    if((array=(int *)malloc(nColumnas*sizeof(int)))==NULL)
    {
        printf("\nNo hay suficiente memoria disponible.\n");
        return NULL;
    }
    
    return array;
}

void leer_array(char *cadena, int nColumnas)
{
    //recoge los elementos del array
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
    //inicializa a ceros todos los elemtos del array frecuencia
    //antes no sabemos que valor hay en memoria
    int i;
    
    for(i=0;i<nColumnas;i++)
    {
        *(frecuencia+i)=1;      //-> por referencia (dirección)
        //frecuencia[i]=1;        -> por valor
    }
}

void maximos(char *cadena, int *frecuencia, int nColumnas)
{
    //cada vez que un elemento se repita en al array cadena,
    //incrementara en uno el elemento del mismo indice del array frecuencia
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
    //guarda en j el indice del elemento mayor del array frecuancia
    int i, j;
    
    for(i=0,j=0;i<nColumnas;i++)
    {
        if(frecuencia[i]>frecuencia[j])//pasar el mayor a 'j'
        {
            j=i;
        }
    }
    
    printf("\n");
    
    //muestra por pantalla el elemento del array cadena, siempre que en el array frecuencia
    //hayya un elemto con el mismo valor que el mas repetido
    for(i=0;i<nColumnas;i++)
    {
        if(frecuencia[i]==frecuencia[j])
        {
            printf("El carácter '%c' es el más repetido con %d repeticiones -> Aparece %d veces.\n", cadena[i], frecuencia[i]-1, frecuencia[i]);
        }
    }
}