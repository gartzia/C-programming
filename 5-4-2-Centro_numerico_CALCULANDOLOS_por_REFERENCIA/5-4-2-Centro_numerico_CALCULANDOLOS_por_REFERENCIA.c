/* 
 * File:   5-4-2-Centro_numerico_CALCULANDOLOS_por_REFERENCIA.c
 * Author: Gartzia
 *
 * Created on 20 de octubre de 2013, 0:42
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int calculo_grupos (int numero);
int centro_numerico(int numero);

/*
 * 
 */

int main(void) {
    
    int numero, valor, contador=1, centros=0;//, grupo1=0, grupo2=0;
    
    printf("\nInserta un número entero entre 1 y 7000:\n");
    fflush(stdout);
    fpurge(stdin);
    scanf("%d", &numero);
    
    if((numero>0) && (numero<7001))
    {
            valor=centro_numerico(numero);
            if(valor!=0)
            {
                printf("\n¡Es un centro numérico!");
            }

            while(contador<=numero)
            {
                valor=centro_numerico(contador);
                if(valor!=0)
                {
                    printf("\nCentro Numérico: %d\nSu grupo es: %d.\n", contador, valor);
                    printf("\n----------------------\n");
                    centros=1;
                }
                contador++;
            }
            
            if(centros==0)
            {
                printf("No hay centros numéricos\n");
            }
    }
    else
    {
        printf("No has insertado un número correcto.\n\n");
    }
    
    printf("\nFin de programa\n");

    return (0);
}

int calculo_grupos (int numero)
{
    int i, k, grupo1=0, grupo2=0;
    
    for(i=1;i<numero;i++)
    {
        grupo1+=i;
    }

    for(k=numero+1;grupo2<grupo1;k++)
    {
        grupo2+=k;
    }
    if((grupo2==grupo1) && (grupo2!=0))
    {
        return grupo2;
    }
    
    return 0;
}

int centro_numerico(int numero)
{    
    int grupo;
    
    grupo=calculo_grupos(numero);
    
    if(grupo!=0)
    {
        return grupo;
    }
    
    return 0;
}