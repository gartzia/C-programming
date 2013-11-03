/* 
 * File:   5-4-Centro_numerico_por_REFERENCIA_y_VALOR.c
 * Author: Gartzia
 *
 * Created on 19 de octubre de 2013, 12:15
 */

#include <stdio.h>
#define CN1 6
#define CN2 35
#define CN3 204
#define CN4 1189
#define CN5 6930

/*
 * 
 */

void centronumerico(int *numero);
void grupo(int constante);

/*
 * 
 */

int main(void) {
    
    int numero;
    
    printf("\nIntroduce un número entero entre 1 y 7000:\n");
    fflush(stdout);
    fpurge(stdin);
    scanf("%d", &numero);
    
    centronumerico(&numero);

    return (0);
}

void centronumerico(int *numero)
{
    
    if((*numero>=1) && (*numero<=7000))
    {
        if((*numero==CN1) || (*numero==CN2) || (*numero==CN3) || (*numero==CN4) || (*numero==CN5))
        {
            printf("\n¡Has introducio un centro numérico!\n");
        }
        if(*numero>=CN5)
            {
                printf("\nLos centros numéricos bajo %d\n\n", *numero);
                
                grupo(CN5);
                grupo(CN4);
                grupo(CN3);
                grupo(CN2);
                grupo(CN1);
            }
            else
            {
                if((*numero>=CN4) && (*numero<CN5))
                {
                    printf("\nLos centros numéricos bajo %d:\n\n", *numero);

                    grupo(CN4);
                    grupo(CN3);
                    grupo(CN2);
                    grupo(CN1);
                }
                else
                {
                    if((*numero>=CN3) && (*numero<CN4))
                    {
                        printf("\nLos centros numéricos bajo %d:\n\n", *numero);

                        grupo(CN3);
                        grupo(CN2);
                        grupo(CN1);
                    }
                    else
                    {
                        if((*numero>=CN2) && (*numero<CN3))
                        {
                            printf("\nLos centros numéricos bajo %d:\n\n", *numero);

                            grupo(CN2);
                            grupo(CN1);
                        }
                        else
                        {
                            printf("\nEl centro numérico bajo %d:\n\n", *numero);

                            grupo(CN1);
                        }
                    }
                }
            }
    }
    else
    {
        printf("\nNo ha sintroducido un numero correcto.\n");
    }
    printf("FIN de programa.");
}

void grupo (int constante)
{
    int i, k,grupo1=0,grupo2=0;
    
    for(i=1;i<constante;i++)
    {
        grupo1+=i;
    }
    
    for(k=constante+1;grupo2!=grupo1;k++)
    {
        grupo2+=k;
    }
    
    printf("%d\nSu grupo es: %d.\nDe %d a %d y de %d a %d.\n", constante, grupo1, 1, i-1, constante+1, k-1);
    printf("\n----------------------\n");
}