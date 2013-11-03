/* 
 * File:   3-Raiz_Newton.c
 * Author: Gartzia
 *
 * Created on 2 de octubre de 2013, 23:00
 */

#include <stdio.h>
#include <math.h>

/*
 * 
 */
int main(void) {
    
    int i;
    int N;
    float EPSILON; /*epsilon=8.854187817 10⁻¹²*/
    float r0;
    float r;
    float condicion;
    float viejo;
    
    printf("\nInserte el valor de:\nN\nEpsilon\nr0\n");
    fflush ( stdout );
    fpurge (stdin );
    scanf("%d %f %f", &N, &EPSILON, &r0);
    
    r=((N+r0)/r0)/2;
    condicion=abs(r-r0);
    
    for(i=0;condicion>EPSILON;i++)
    {
        viejo=r;
        r=((N/r)+r)/2;
        condicion=abs(r-viejo);
        
    }
    if(condicion<=EPSILON)
    {
        printf("\nLa raíz cuadrada es:\t%f\n", r);
    }

    return 0;
}

