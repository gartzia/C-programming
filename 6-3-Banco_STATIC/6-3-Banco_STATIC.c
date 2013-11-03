/* 
 * File:   6-3-Banco_STATIC.c
 * Author: Gartzia
 *
 * Created on 26 de octubre de 2013, 23:17
 */

#include <stdio.h>
#include <stdlib.h>
#define RANGO 9

/*
 * 
 */
int solicitud (int cuenta[], int *codigo);
void solicitar_cuenta(int cuenta[]);
int solicitar_codigo ();
int intentos (int *codigo);
int operacion (int cuenta[], int codigo);
int suma(int cuenta[]);
int resta(int cuenta[]);
int multi(int cuenta[]);
void mostrar (int opcion, int cuenta[]);
void mostrar_cuenta(int cuenta[]);

int main() {
    
    int cuenta[RANGO], opcion, codigo;
        
    opcion=solicitud(cuenta, &codigo);
    
    if(opcion==3)
    {
        opcion=operacion(cuenta, codigo);
    }
    
    mostrar(opcion, cuenta);

    return (0);
}

int solicitud (int cuenta[], int *codigo)
{
    int opcion, numeros;
    
    solicitar_cuenta(cuenta);
    *codigo=solicitar_codigo();
    
    opcion=intentos(codigo);
    
    return opcion;
}
void solicitar_cuenta(int cuenta[])
{
    int i;
    
    printf("\nInserta el número de cuenta de 9 dígitos:\n");
    fflush(stdout);
    fpurge(stdin);
    
    for(i=0;i<RANGO;i++)
    {
        scanf("%1d", &cuenta[i]);
    }
}

int solicitar_codigo ()
{
    int codigo;
    
    printf("\nInserta el código de operación:\n");
    fflush(stdout);
    fpurge(stdin);
    scanf("%d", &codigo);
    
    return codigo;
}

int intentos (int *codigo)
{
    int intentos=1;
    
    //intentos para ingresar un código correcto
    while(intentos<=3)
    {
        if(*codigo==1 || *codigo==2 || *codigo==3) //desgloso los tres casos para hacer mayor énfasis en los tres casos
        {
            return 3; //cuenta y codigo bien
        }
        else
        {
            if(intentos==3)
            {
                return 2; //cuenta bien, pero codigo mal
            }
            printf("\nInserta un código correcto por favor.\n");
            *codigo=solicitar_codigo();
        }

        intentos++;
    }
        
    
    return 1; //cuenta mal
}

int operacion (int cuenta[], int codigo)
{
    int validez;
    
    switch(codigo)
    {
        case 1:
            validez=suma(cuenta);
            break;
        case 2:
            validez=resta(cuenta);
            break;
        case 3:
            validez=multi(cuenta);
            break;
    }

    if(validez==1)
    {
        return 3;
    }
    
    return 4;
}

int suma(int cuenta[])
{
    int i, suma=0, validez;
    
    for(i=0;i<RANGO-1;i++)
    {
        suma+=cuenta[i];
    }
    
    suma%=10;
    
    if(suma==cuenta[RANGO-1])
    {
        validez=1;
    }
    else
    {
        validez=0;
    }
    
    return validez;
}

int resta(int cuenta[])
{
    int i, resta=0, validez;
    
    for(i=1;i<RANGO-1;i++)
    {
        cuenta[0]-=cuenta[i];
    }
    resta=cuenta[0];
    resta%=10;
    
    if(resta==cuenta[RANGO-1])
    {
        validez=1;
    }
    else
    {
        validez=0;
    }
    
    return validez;
}

int multi(int cuenta[])
{
    int i, multi=0, validez;
    
    for(i=0;i<RANGO-1;i++)
    {
        multi*=cuenta[i];
    }
    
    multi%=10;
    
    if(multi==cuenta[RANGO-1])
    {
        validez=1;
    }
    else
    {
        validez=0;
    }
    
    return validez;
}

void mostrar (int opcion, int cuenta[])
{    
    printf("\n");
    
    switch(opcion)
    {
        case 2:
            printf("\nNúmero de cuenta:\n");
            mostrar_cuenta(cuenta);
            printf("\nVALIDEZ:\t-----\n");
            printf("\nCódigo de operación:\n");
            printf("VALIDEZ:\tNO VÁLIDO - Has superado los intentos permitidos.\nInténtalo más tarde.\n");
            break;
            
        case 3:
            printf("\nNúmero de cuenta:\n");
            mostrar_cuenta(cuenta);
            printf("\nVALIDEZ:\tVÁLIDO\n");
            printf("\nCódigo de operación:\n");
            printf("\nVALIDEZ:\tVÁLIDO\n");
            break;
            
        case 4:
            printf("\nNúmero de cuenta:\n");
            mostrar_cuenta(cuenta);
            printf("\nVALIDEZ:\tNO VÁLIDO\n");
            printf("\nCódigo de operación:\n");
            printf("\nVALIDEZ:\tVÁLIDO\n");
            break;
    }
}

void mostrar_cuenta(int cuenta[])
{
    int i;
    
    for(i=0;i<RANGO-1;i++)
    {
        printf("%d - ", cuenta[i]);
    }
    
    printf("%d.", cuenta[RANGO-1]);
}