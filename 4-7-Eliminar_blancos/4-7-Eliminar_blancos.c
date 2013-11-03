/* 
 * File:   7-Eliminar_blancos.c
 * Author: Gartzia
 *
 * Created on 2 de octubre de 2013, 23:38
 */

#include <stdio.h>

/*
 * 
 */
int main(void) {
    
    char cadena;
    
    printf("Inserta una cadena acabada en un punto '.'\n");
    fflush( stdout ); /*Lo vuelca a un buffer nuevo a la espera de más datos
                       cuando crea oprtuno, lo volcará a disco*/
    fpurge ( stdin ); /* Limpia el buffer y ahora cojerá del scanf() */
    scanf("%c", &cadena);
    
    while(cadena != '.')
    {
        if((cadena >= 'A' && cadena <= 'Z'))
        {
            if(cadena == 'Z')
            {
                printf("A");
            }
            else
            {
                printf("%c", ('b'+cadena-'A'));
            }
        }
        if(cadena >= 'a' && cadena <='z')
        {
            if(cadena == 'z')
            {
                printf("a");
            }
            else
            {
                printf("%c", ('B'+cadena-'a'));
            }
        }
        scanf("%c", &cadena);
    }
   
   printf("\n"); 

    return 0;
}

