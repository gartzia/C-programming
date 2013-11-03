/* 
 * File:   5-Sumatorio_exponente.c
 * Author: Gartzia
 *
 * Created on 2 de octubre de 2013, 23:26
 */

#include <stdio.h>
#include <math.h>

/*
 * 
 */
int main(void) {
    
    int entero, i, j, exponente=1, sumatorio=0;
    
    printf("Inserta un número:\n");
    fflush ( stdout );
    fpurge( stdin );
    scanf("%d", &entero);
    
    for(i=1;i<=entero;i++)
    {
	exponente=i;

        for(j=1;j<i;j++)
	{
		exponente*=i;
	}
	sumatorio += exponente;
    }

    printf("Es sumatorio de %d es: %d\n", entero, sumatorio);
    
    return 0;
}
