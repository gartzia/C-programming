/* 
 * File:   5-2-MDC_por_VALOR.c
 * Author: Gartzia
 *
 * Created on 11 de octubre de 2013, 0:55
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int max_comun_mult(int x, int y);

int main(void) {
    
    int num1, num2, a;
    
    printf("\nIserta el Numerador:\n");
    fflush ( stdout );
    printf("Inserta el Divisor:\n");
    fpurge ( stdin );
    scanf("%d %d", &num1, &num2);
    
    printf("%d / %d = ", num1, num2);
    
    a=max_comun_mult(num1, num2);
    
    num1/=a;
    num2/=a;
    
    printf("%d / %d\n", num1, num2);

    return 0;
}

int max_comun_mult(int x, int y)
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
    
    return x;
}