/* 
 * File:   1-Factorial.c
 * Author: Gartzia
 *
 * Created on 2 de octubre de 2013, 18:35
 */

#include <stdio.h>

/*
 * 
 */
int main(void) {
    
    int numero;
    int factorial=1;
    int i;
    
    printf("Inserta un número entero:\n");
    fflush ( stdout );
    fpurge ( stdin );
    scanf("%d", &numero);
    if(numero==0)
    {
       printf("El factorial de %d es 0.", numero);
    }
    else
    {
    
        if(numero<0)
        {
                numero=-numero; /*cambiamos el signo al numero*/
                for(i=1;i<=numero;i++)
                {
                factorial=(-i)*factorial; /*-i pone el signo negativo a los elemntos*/
                }
                numero=-numero; /*vulevo a cambiarle el signo a numero para el printf final*/
        }
        else
        {
                for(i=1;i<=numero;i++)
                {
                factorial=i*factorial;
                }
        }
        
        printf("El factorial de %d es: %d\n", numero, factorial);
    }

    return 0;
}

