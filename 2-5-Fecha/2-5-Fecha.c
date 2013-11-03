/* 
 * File:   5-Fecha.c
 * Author: Gartzia
 *
 * Created on 30 de septiembre de 2013, 19:41
 */

#include <stdio.h>

/*
 * 
 */
int main(void) {
    
    int dia;
    int mes;
    int anno;
    
    printf("Inserta el dia, mes y año:\n");
    fflush ( stdout );
    fpurge ( stdin );
    scanf("%d %d %d", &dia, &mes, &anno);
  /*  
    printf("Inserta el mes:\n");
    fflush ( stdout );
    __fpurge ( stdin );
    scanf("%d", &mes);
    
    printf("Inserta el anno:\n");
    fflush ( stdout );
    __fpurge ( stdin );
    scanf("%d", &anno);*/
    
    anno=anno%100; /*El resto será el numero de digitos desplazados a decimal*/
    
    printf("Esta es la fecha: %02u/%02u/%d en formato dd/mm/aa.\n", dia, mes, anno);

    return 0;
}

