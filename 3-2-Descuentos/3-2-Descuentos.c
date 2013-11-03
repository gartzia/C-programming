/* 
 * File:   2-Descuentos.c
 * Author: Gartzia
 *
 * Created on 2 de octubre de 2013, 13:04
 */

#include <stdio.h>
#define BAJO 6000
#define MEDIO 10000
#define ALTO 20000

/*
 * 
 */
int main(void) {
    
    float gasto;
    int descuento;
    
    printf("Inserte el valor de su compra:\n");
    fflush ( stdout );
    fpurge ( stdin );
    scanf("%f", &gasto);
    
    printf("Su gasto es de %.2f\n", gasto);
    printf("----------------------\n");
    
    /* Comparamos descuento */
    if((gasto>0) && (gasto<=BAJO))
    {
        descuento=0;
    }
    else
    {
        if((gasto>BAJO) && (gasto<=MEDIO))
        {
            descuento=10;
        }
        else
        {
            if((gasto>MEDIO) && (gasto<=ALTO))
            {
                descuento=20;
            }
            else
            {
                descuento=30;
            }
        }
    }
    printf("Su descuento es del %d %%\n", descuento);
    printf("----------------------\n");
    
    float ahorro;
    ahorro=(gasto*descuento)/100;
    printf("Se ahorra %.2f\n", ahorro);
    printf("----------------------\n");
    
    gasto -= (gasto*descuento)/100;
    printf("La cantidad a pagar es de %.2f\n", gasto);
    
    printf("------------------------------------------\n");

    return 0;
}

