/* 
 * File:   1-Numeros.c
 * Author: Gartzia
 *
 * Created on 1 de octubre de 2013, 23:35
 */

#include <stdio.h>

/*
 * 
 */
int main(void) {

    int num1, num2, num3, paso;
    
    printf("\nIntrdocue tres numeros enteros y serán ordenados en modo creciente:\n");
    fflush ( stdout );
    fpurge ( stdin );
    scanf("%d %d %d", &num1, &num2, &num3);
    
    /* Ordeno los números */
    if(num1>=num2)
    {
        paso=num1;
        num1=num2;
        num2=paso;
    }
    
    if(num1>=num3)
    {
        paso=num1;
        num1=num3;
        num3=paso;
    }
    
    if(num2>=num3)
    {
        paso=num2;
        num2=num3;
        num3=paso;
    }
    
    printf("%d < %d < %d\n", num1, num2, num3);

    return 0;
}

