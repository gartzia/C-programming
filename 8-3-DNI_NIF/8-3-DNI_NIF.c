/* 
 * File:   8-3-DNI_NIF.c
 * Author: Gartzia
 *
 * Created on 11 de noviembre de 2013, 19:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANGO 81
#define RANGO2 23

/*
 * 
 */
void clear_buffer();
void read_data(char *cadena);
void dni_number(char *cadena);
int validity(long dni);
void calculate_nif(long dni);

int main()
{
    char frase[RANGO];
    
    //-----LEER DATOS-----
    read_data(frase);

    //-----TRATAMIENTO DE DATOS-----
    dni_number(frase); //recoge el D.N.I. de la frase
    return (0);
}

void clear_buffer()
{
    fflush(stdout);
    fpurge(stdin);
}

void read_data(char *cadena)
{
    printf("\nInserte su D.N.I. para obterner el N.I.F:\n");
    clear_buffer();
    fgets(cadena, RANGO, stdin);
}

void dni_number(char *cadena)
{
    int opcion;
    long dni;
    
    dni=atol(cadena);
    opcion=validity(dni);
    if(opcion==0)
    {
        calculate_nif(dni);
    }
    else
    {
        printf("\nEl DNI, no es válido.\n");
    }
}

int validity(long dni)
{
    if(dni>=0100000 && dni<=99999999)
    {
        return 0;
    }
    
    return 1;
}

void calculate_nif(long dni)
{
    char nif[RANGO2]={'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    int resto;
    
    resto=dni%23;
    
    printf("\nN.I.F.: %2ld.%ld.%ld %c\n", dni/1000000, (dni%1000000)/1000,dni%1000, nif[resto]);
}