/* 
 * File:   main.c
 * Author: Gartzia
 *
 * Created on 30 de septiembre de 2013, 18:20
 */

#include <stdio.h>

/*
 * 
 */
int main(void) {
    
    float celsius;
    float fahrenheit;
    
    printf("Inserta la temperatura en grados Celsius: XXX.YY\n\n");
    fflush ( stdout );
    fpurge ( stdin );
    scanf("%f", &celsius);
    
    fahrenheit=1.8*celsius+32;
    
    printf("\n%3.2f grados Celsius = %3.2f grados Fahrenheit\n", celsius, fahrenheit);

    return 0;
}

