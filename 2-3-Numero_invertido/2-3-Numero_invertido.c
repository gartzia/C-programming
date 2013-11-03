/* 
 * File:   main.c
 * Author: Gartzia
 *
 * Created on 30 de septiembre de 2013, 19:16
 */

#include <stdio.h>

/*
 * 
 */
int main(void) {
    
    int numero;
    int invertido=0;
    
    printf("Intrduce un numero entero de 3 cifras:\n");
    fflush ( stdout );
    fpurge ( stdin );
    scanf("%d", &numero);
    
    while (numero>0)
        {
        invertido = invertido*10+(numero%10);
        numero = numero / 10; /*al ser numero int, solo me quedo y no con 12 y no 12,3*/
        }
        printf("\nEl número invertido es: %d\n", invertido);
        printf("---------------------------\n");

    return 0;
}

