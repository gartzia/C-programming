/* 
 * File:   6-Tabla_ASCII.c
 * Author: Gartzia
 *
 * Created on 2 de octubre de 2013, 23:37
 */

#include <stdio.h>

/*
 * 
 */
int main(void) {
    
    int i;
    int j;
    
    printf("\nTabla de codigo ASCII desde el caracter 33 al 126:\n");
    fflush( stdout);
    
    for(i=33,j=0;i<=127;i++,j++)
    {
        printf("%d %c ", i, i);
        if(j==7)
        {
            j=-1;
            printf("\n");
        }
        
        /*if(i==40 || i==48 || i==56 || i==64 || i==72 || i==80 || i==88 || i==96 || i==104 || i==112 || i==120)
        {
            printf("\n");
        }*/
    }

    return 0;
}

/*Si pongo int num=1;  guarda uno;
  Si pongo int num='1' guarda el número ASCII de uno -> 75;

  Si pongo char ch=1;   guarda el número 1;
  Si pongo char ch='1'; guarda el código ASCII de uno
 
 *Si compare letras con números:
 
        if(ch>'0')
 tengo que comparar el carácter con el valor del número en ASCII*/