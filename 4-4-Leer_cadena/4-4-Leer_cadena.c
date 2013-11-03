/* 
 * File:   4-Leer_cadena.c
 * Author: Gartzia
 *
 * Created on 2 de octubre de 2013, 23:22
 */
/*Si pongo int num=1;  guarda uno;
  Si pongo int num='1' guarda el número ASCII de uno -> 75;

  Si pongo char ch=1;   guarda el número 1;
  Si pongo char ch='1'; guarda el código ASCII de uno
 
 *Si compare letras con números:
 
        if(ch>'0')
 tengo que comparar el carácter con el valor del número en ASCII*/

#include <stdio.h>
#include <string.h>

/*
 * 
 */
int main(void) {
    
    char cadena;
    /*int i;*/
    int numeros=0;
    int espacios=0;
    int caracteres=0;
    /*int longitud;*/
    
    printf("Inserta una cadena siendo el último carácter una punto:\n");
    fflush ( stdout );
    fpurge ( stdin );
    scanf("%c", &cadena);
    
    /*longitud = strlen(cadena);*/
    /*
     recorrer con un while buscando el final de la cadena:
     i=0;
     while (cadena[i] != '\0') {
     ...
     }
     que es lo mismo (siempre que tu cadena esté cerrada) si colocas simplemente:
     while (cadena[i]) {
     ...
     }
*/
    
    while(cadena != '.')
    {
        if((cadena >= 'A' && cadena <= 'Z') || (cadena >= 'a' && cadena <= 'z'))
        {
            caracteres++;
        }
        else
        {

                if((cadena >= '0' && cadena <= '9'))
                {
                numeros++;
                }
                if(cadena ==' ')
                {
                    espacios++;
                }
        }
        scanf("%c", &cadena);
    }

    printf("Números: %d\n", numeros);
    printf("Espacios: %d\n", espacios);
    printf("Carácteres: %d", caracteres);
    
    return 0;
}

