/* 
 * File:   6-3-Banco_DYNAMIC.c
 * Author: Gartzia
 *
 * Created on 26 de octubre de 2013, 23:17
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int solicitar_numero_digitos(int nColumnas);
int *reserva_memoria(int nColumnas);
int solicitud (int *cuenta, int nColumnas, int *codigo);
void solicitar_cuenta(int *cuenta, int nColumnas);
int solicitar_codigo ();
int intentos (int *codigo);
int operacion (int *cuenta, int nColumnas, int codigo);
int suma(int *cuenta, int nColumnas);
int resta(int *cuenta, int nColumnas);
int multi(int *cuenta, int nColumnas);
void mostrar (int opcion, int *cuenta, int nColumnas);
void mostrar_cuenta(int *cuenta, int nColumnas);

int main() {
    
    int nColumnas=0;
    int *cuenta, opcion, codigo;
    
    //solicitar número de dígitos de la cuenta (Columnas del array)
    nColumnas=solicitar_numero_digitos(nColumnas);
    
    //-----RESERVA DE MEMORIA------
    //para la cuenta
    cuenta=reserva_memoria(nColumnas);
    
    //-----LECTURA DE DATOS-----
    //solicitar el número de cuenta y el código de seguridad
    opcion=solicitud(cuenta, nColumnas, &codigo);
    
    //-----TRATAMIENTO DE DATOS-----
    //si todo está correcto, calcular la operación correspondiente al código introducido
    //y comprobar que el resultado es correcto:
    if(opcion==3)
    {
        opcion=operacion(cuenta, nColumnas, codigo);
    }
    
    //-----VISUALIZACIÓN DE DATOS-----
    //resultado:
    mostrar(opcion, cuenta, nColumnas);

    return (0);
}

int solicitar_numero_digitos(int nColumnas)
{
    int Ok=0;
    
    do
    {
        printf("\nInserta el número de dígitos que introducirás:\n");
        fflush(stdout);
        fpurge(stdin);
        scanf("%d", &nColumnas);
    }while(!Ok && nColumnas<1);
    
    return nColumnas;
}

int *reserva_memoria(int nColumnas)
{
    int *cuenta=NULL;
    if((cuenta=(int *)malloc(nColumnas*sizeof(int)))==NULL)
    {
        printf("\nInsuficiente memoria libre.\n");
        return NULL;
    }
    
    return cuenta;
}

int solicitud (int *cuenta, int nColumnas, int *codigo)
{
    int opcion;
    
    solicitar_cuenta(cuenta, nColumnas);
    *codigo=solicitar_codigo();
    
    opcion=intentos(codigo);
    
    return opcion;
}
void solicitar_cuenta(int *cuenta, int nColumnas)
{
    int i;
    
    printf("\nInserta el número de cuenta de 9 dígitos:\n");
    fflush(stdout);
    fpurge(stdin);
    
    for(i=0;i<nColumnas;i++)
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

int operacion (int *cuenta, int nColumnas, int codigo)
{
    int validez;
    
    switch(codigo)
    {
        case 1:
            validez=suma(cuenta, nColumnas);
            break;
        case 2:
            validez=resta(cuenta, nColumnas);
            break;
        case 3:
            validez=multi(cuenta, nColumnas);
            break;
    }

    if(validez==1)
    {
        return 3;
    }
    
    return 4;
}

int suma(int *cuenta, int nColumnas)
{
    int i, suma=0, validez;
    
    for(i=0;i<nColumnas-1;i++)
    {
        suma+=cuenta[i];
    }
    
    suma%=10;
    
    if(suma==cuenta[nColumnas-1])
    {
        validez=1;
    }
    else
    {
        validez=0;
    }
    
    return validez;
}

int resta(int *cuenta, int nColumnas)
{
    int i, resta=0, validez;
    
    for(i=1;i<nColumnas-1;i++)
    {
        cuenta[0]-=cuenta[i];
    }
    resta=cuenta[0];
    resta%=10;
    
    if(resta==cuenta[nColumnas-1])
    {
        validez=1;
    }
    else
    {
        validez=0;
    }
    
    return validez;
}

int multi(int *cuenta, int nColumnas)
{
    int i, multi=0, validez;
    
    for(i=0;i<nColumnas-1;i++)
    {
        multi*=cuenta[i];
    }
    
    multi%=10;
    
    if(multi==cuenta[nColumnas-1])
    {
        validez=1;
    }
    else
    {
        validez=0;
    }
    
    return validez;
}

void mostrar (int opcion, int *cuenta, int nColumnas)
{    
    printf("\n");
    
    switch(opcion)
    {
        case 2:
            printf("\nNúmero de cuenta:\n");
            mostrar_cuenta(cuenta, nColumnas);
            printf("\nVALIDEZ:\t-----\n");
            printf("\nCódigo de operación:\n");
            printf("\nVALIDEZ:\tNO VÁLIDO - Has superado los intentos permitidos.\nInténtalo más tarde.\n");
            break;
            
        case 3:
            printf("\nNúmero de cuenta:\n");
            mostrar_cuenta(cuenta, nColumnas);
            printf("\nVALIDEZ:\tVÁLIDO\n");
            printf("\nCódigo de operación:\n");
            printf("\nVALIDEZ:\tVÁLIDO\n");
            break;
            
        case 4:
            printf("\nNúmero de cuenta:\n");
            mostrar_cuenta(cuenta, nColumnas);
            printf("\nVALIDEZ:\tNO VÁLIDO\n");
            printf("\nCódigo de operación:\n");
            printf("\nVALIDEZ:\tVÁLIDO\n");
            break;
    }
}

void mostrar_cuenta(int *cuenta, int nColumnas)
{
    int i;
    
    for(i=0;i<nColumnas-1;i++)
    {
        printf("%d - ", cuenta[i]);
    }
    
    printf("%d.", cuenta[nColumnas-1]);
}