/* 
 * File:   5-2-Simplificar_division.c
 * Author: Gartzia
 *
 * Created on 11 de octubre de 2013, 0:55
 */
/**AUNQUE NO TIENE MUCHO SENTIDO HACER ESTE PROGRAMA POR REFERENCIA YA QUE QUIERO USAR
 LAS VARIABLES num1 Y num2 con su valor inicial, que no se pierda*/
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void max_comun_div(int x, int y, int *a);

int main(void) {
    
    int num1, num2, a;
    
    printf("\nIserta el Numerador:\n");
    fflush ( stdout );
    printf("Inserta el Divisor:\n");
    fpurge ( stdin );
    scanf("%d %d", &num1, &num2);
    
    printf("%d / %d = ", num1, num2);
    
    max_comun_div(num1, num2, &a);
    
    num1/=a;
    num2/=a;
    
    printf("%d / %d\n", num1, num2);

    return 0;
}

void max_comun_div(int x, int y, int *a)
{
    while(x!=y)
    {
        if(x>y)
        {
            x-=y;
        }
        else
        {
            y-=x;
        }
    }
    *a=x;
}