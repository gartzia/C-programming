/* 
 * File:   4-Billetes_Basico.c
 * Author: Gartzia
 *
 * Created on 30 de septiembre de 2013, 19:50
 */

#include <stdio.h>

/*
 * 
 */
int main(void) {

    float numero;
    int cantidad;
    
    printf("Introduce una cantidad:\n");
    fflush (stdout );
    fpurge ( stdin );
    scanf ("%f", &numero);
    
    numero = numero*100; /* Pasamos decimales a enteros */
    
    int entero; /* Convertimos float en int para eliminar decimales*/
    entero=(int)numero;
   
    /* Billetes de 500€ */
    cantidad = entero / 50000;
    /*--como cantidad es int, coge sólo el numero entero???*/
    entero = entero % 50000;
    printf("\nBilletes de 500€: %d\n", cantidad);
    
    /* Billetes de 200€ */
    cantidad = entero / 20000;
    entero = entero % 20000;
    printf("\nBilletes de 200€: %d\n", cantidad);
    
    /* Billetes de 100€ */
    cantidad = entero / 10000;
    entero = entero % 10000;
    printf("\nBilletes de 100€: %d\n", cantidad);
    
    /* Billetes de 50€ */
    cantidad = entero / 5000;
    entero = entero % 5000;
    printf("\nBilletes de 50€: %d\n", cantidad);
    
    /* Billetes de 20€ */
    cantidad = entero / 2000;
    entero = entero % 2000;
    printf("\nBilletes de 20€: %d\n", cantidad);
    
    /* Billetes de 10€ */
    cantidad = entero / 1000;
    entero = entero % 1000;
    printf("\nBilletes de 10€: %d\n", cantidad);
    
    /* Billetes de 5€ */
    cantidad = entero / 500;
    entero = entero % 500;
    printf("\nBilletes de 5€: %d\n", cantidad);
    
    /* Monedas de 2€ */
    cantidad = entero / 200;
    entero = entero % 200;   
    printf("\nBilletes de 2€: %d\n", cantidad);
    
    /* Monedas de 1€ */
    cantidad = entero / 100;
    entero = entero % 100;
    printf("\nBilletes de 1€: %d\n", cantidad);
    
    /* Monedas de 0.50€*/
    cantidad = entero / 50;
    entero = entero % 50;
    printf("\nBilletes de 0.50€: %d\n", cantidad);
    
    /* Monedas de 0.20€ */
    cantidad = entero / 20;
    entero = entero % 20;
    printf("\nBilletes de 0.2€: %d\n", cantidad);
    
    /* Monedas de 0.10€*/
    cantidad = entero / 10;
    entero = entero % 10;
    printf("\nBilletes de 0.1€: %d\n", cantidad);
    
    /* Monedas de 0.05€ */
    cantidad = entero / 5;
    entero = entero % 5;
    printf("\nBilletes de 0.05€: %d\n", cantidad);
    
    /* Monedas de 0.02€ */
    cantidad = entero / 2;
    entero = entero % 2;
    printf("\nBilletes de 0.02€: %d\n", cantidad);
    
    /* Monedas de 0.01€ */
    cantidad = entero / 1;
    entero = entero % 1;
    printf("\nBilletes de 0.01€: %d\n", cantidad);
    
    printf("----------------------------------------\n");
    
    return 0;
}

