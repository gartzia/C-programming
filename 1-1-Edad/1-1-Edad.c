/* 
 * File:   main.c
 * Author: Gartzia
 *
 * Created on 23 de septiembre de 2013, 20:11 - Jajaja Mi Cumple ;)
 */

#include <stdio.h>


int main( void ) {
    
char nombre[20];
int edad;
int dias;

printf( "Introduzca su nombre: \n");
fflush( stdout );
fpurge( stdin );
scanf( "%s", nombre );

printf( "Introduzca su edad: \n");
fflush( stdout );
fpurge( stdin );
scanf( "%d", &edad );

dias=edad*365;

printf( "Hola %s!, tienes %d dias de vida\n", nombre, dias );

return 0;
}


