/* 
 * File:   8-1-Borrar_espacios.c
 * Author: Gartzia
 *
 * Created on 5 de noviembre de 2013, 20:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANGO 11
/*
 * 
 */
void clean_buffer();
void leer_cadena(char cadena[RANGO]);
void inicial(char frase[RANGO]);
void final(char frase[RANGO]);
void intermedio(char frase[RANGO]);
void contar_palabras(char frase[RANGO]);

int main()
{
    char frase[RANGO];
    
    //-----CAPTURA DE DATOS-----
    leer_cadena(frase);
    
    //-----TRATAMIENTO DE DATOS-----
    inicial(frase);
    final(frase);
    intermedio(frase);
    printf("\nFrase ordenada\t\t:%s\n", frase);
    contar_palabras(frase);
    
    return (0);
}

void clean_buffer()
{
    fflush(stdout);
    fpurge(stdin);
}

void leer_cadena(char cadena[RANGO]) //char cadena[RANGO] ???
{    
    printf("\nIntroducir una cadena, máximo 10 caracteres:\n");
    printf("\nPara terminar pulsa <ENTER>:\n");
    
    clean_buffer();
    fgets(cadena, RANGO, stdin);
}

void inicial(char frase[RANGO])
{
    int i=0, cnt=0;
    
    while(frase[i]==' ')
    {
        cnt++;
        i++;
    }
    
    printf("\nEspacios iniciales\t:%d\n", cnt);
    
    for(i=0;i<RANGO;i++)
    {
        frase[i]=frase[cnt+i];
    }
}

void final(char frase[RANGO])
{
    int cnt=0, longitud;
    
    longitud=strlen(frase);
    
    while(frase[longitud-1]==' ')
    {
        cnt++;
        longitud--;
    }
    
    printf("\nEspacios finales\t:%d\n", cnt);
    
    //longitud ya tiene descontados los espacios finales, en el while: --longitud;
    frase[longitud]='\0';    
}

void intermedio(char frase[RANGO])
{
    int i=0, j, longitud, cnt=0;
    
    longitud=strlen(frase);
    
    while(i!=longitud)
    {
        if(frase[i]==' ' && frase[i+1]==' ')
        {//todo esto y la últma sentencia se podría hacer con strcpy, pero no me deja el compilador, ¿falta la librería?
            cnt++;
            for(j=i;j<longitud-1;j++)
            {
                frase[j]=frase[j+1];
            }
        }
        else
        {
            i++;
        }
    }
    
    frase[longitud-cnt]='\0';
}

void contar_palabras(char frase[RANGO])
{
    int i, longitud, cnt;
    
    longitud=strlen(frase);
    
    for(i=0;i<longitud-1;i++)
    {
        if(frase[i]==' ')
        {
            cnt++;
        }
    }
    
    printf("\nFrase contiene\t\t:%d palabras", cnt+1);
}