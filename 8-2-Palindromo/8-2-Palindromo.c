/* 
 * File:   8-2-Palindromo.c
 * Author: Gartzia
 *
 * Created on 8 de noviembre de 2013, 21:19
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANGO 81
/*
 * 
 */
void clean_buffer();
void read_data(char *cadena);
void non_letter_eraser(char *frase);
void capital_letters(char *frase);
void palindrome(char *frase/*, int i, int longitud*/);

int main()
{
    int longitud;
    char frase[RANGO];
    
    //-----LEER DATOS-----
    read_data(frase);
    
    //-----TRATAMIENTO DE DATOS-----
    non_letter_eraser(frase);
    capital_letters(frase);
    longitud=strlen(frase);
    
    //-----VISUALIZACION DE DATOS-----
    palindrome(frase/*, 0, longitud*/);

    return (0);
}

void read_data(char *cadena)
{
    fgets(cadena, RANGO, stdin);
}

void non_letter_eraser(char *frase)
{
    int i, j, longitud;
    
    longitud=strlen(frase);
   
    for(i=0;i<longitud;i++)
    {
        if(frase[i]<'A' || (frase[i]>'Z' && frase[i]<'a') || frase[i]>'z')
        {
            for(j=i;j<longitud;j++)
            {
                frase[j]=frase[j+1];
            }
            
            i--;
            frase[longitud]='\0';
            longitud=strlen(frase);
        }
    }
}

void capital_letters(char *frase)
{
    int i, longitud;
    
    longitud=strlen(frase);
    
    for(i=0;i<longitud;i++)
    {
        if(frase[i]>='a' && frase[i]<='z')
        {
            frase[i]='A'+frase[i]-'a';
        }
    }
}

void palindrome(char *frase)
{
    int i=0, longitud;
    
    longitud=strlen(frase);
    
    while(i<(longitud/2)+1)
    {
        if(frase[i]!=frase[longitud-1-i])
        {
            printf("\nNo es palindromo.\n");
            break;
        }
        else
        {
            if(i==longitud/2)
            {
                printf("\nLa palabra %s es un palindromo.\n", frase);
            }
        }
        
        i++;
    }
}