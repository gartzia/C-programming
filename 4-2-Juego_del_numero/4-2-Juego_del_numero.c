/* 
 * File:   2-Juego_del_Numero.c
 * Author: Gartzia
 *
 * Created on 2 de octubre de 2013, 19:01
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*#define SECRETO 91 --si queremos usar un número predefinido*/
/*Me ha comentado Gorka que nombres en mayúsculas sólo para constantes
 es un convenio*/

/*
 * 
 */
int main() {
    
    int numero;
    int i=1;
    int resta;
    
    int secreto;
    srand(time(NULL));
    secreto=(rand()%100)+1; /*Al hcer módulo de 100, va del 0-99, y sumando 1, de 1-100*/
    
    /*randd coje un número entre 0 y 2 mil millones aprox.
    Para acotar el rango, hacemos el módulo (%) con N+1 para que no dé el resto
    un número entre 0 y N. Y sumamos uno para que esté acotado entre 1 y N:
        numero=rand()%(N-M+1)+M;
     */
    
    /*Para que rand() no parta de la semilla (número inicial del algoritmo) -> srand()
    Para no darle unos números como semilla:
    ClockTime: srand(time(NULL));
    srand(getpid());*/
    
    printf("\n\nBienvenido al Juego del número - Tienes diez oprtunidades para acertar el número secreto.\n\n");
    printf("Inserta un número del 1 al 100:\n\n");
    fflush ( stdout );
    fpurge ( stdin );
    scanf("%d", &numero);
    
    resta=secreto-numero;
    /*Resto el número introducido al SECRETO, así la diferencia me dira lo cerca
     o lejos que estoy, y el +/- si estoy a la derecha (que SECRETO es menor)
     o izquierda (que SERETO es mayor) respectivamente*/
    
    while(numero != secreto)
    {
        if(i==11)
        {
            printf("---------------------------");
            printf("\nTus oportunidades han acabado :(\nOtra vez será...\n-----------------------\n");
            printf("\nEl número secreto era: %d\n", secreto);
            printf("abs de resta: %d\n", abs(resta));
            break;
        }
        
        if(i==9){
            {
                printf("\n¡Date prisa! - ¡¡¡Tus oportunidades se acaban!!!\n");
            }
        }
        
        if(abs(resta)<=2)
        {
            printf("---------------------------");
            printf("\n¡CASI LO TIENES!!\n");
        }
        else
        {
            if(abs(resta)<=10)
                {
                        printf("---------------------------");
                        printf("\n¡Muy caliente!\n");
                }
            else
            {
                if(abs(resta)<=30)
                        {
                                printf("---------------------------");
                                printf("\n¡Caliente!\n");
                        }
                else
                {
                    if(abs(resta)<=50)
                        {
                                printf("---------------------------");
                                printf("\nTemplado...\n");
                        }
                    else
                    {
                        if(abs(resta)<=70)
                        {
                            printf("---------------------------");
                            printf("\nFrío, frío...\n");
                        }
                        else
                        {
                            if(abs(resta)<=90)
                            {
                                printf("---------------------------");
                                printf("\n¡Congelado!\n");
                            }
                            else
                            {
                                printf("---------------------------");
                                printf("\n¡NO DAS UNA!\n");
                            }
                        }
                    }
                }
            }
        }
  
        if(resta>0)
        {
            printf("---------------------------");
            printf("\n¡ES MÁS GRANDE!\n");
        }
        
        else
        {
            printf("---------------------------");
            printf("\n¡ES MÁS PEQUEÑO!\n");
        }
        
        printf("\nVas %d de 10 oprtunidades\n", i);
        printf("\nInserta el número otra vez:\n");
        fflush (stdout );
        fpurge ( stdin );
        scanf("%d", &numero);
        
        resta=secreto-numero;
        i++;
    }
    if(numero == secreto) /* o podría ser también if(RESTA == 0) */
    {
        printf("\n--------------------------------------------------------\n");
        printf("\nZORIONAK\n\tZORIONAK\n\t\tZORIONAK\n\t\t\tZORIONAK\n\t\t\t\tZORIONAK\n\n");
        printf("--------------------------------------------------------\n\n");   
        printf("¡¡¡Has acertado el número!!!\n");
        
        printf("\n\nEl número secreto era: %d\n\n\n", secreto);
                
        switch(i)
        {
            case 1:
                printf("\n¡INCREIBBLE! Has acertado a la primera!!!");
                break;
                
            case 2:
                printf("Que bien, lo has logrado a la segunda, fenómeno!");
                break;
                
            case 3:
                printf("Muy bien, a estado genial.");
                break;
                
            case 4:
                printf("Bien, no ha estado mal.");
                break;
                
            case 5:
                
                printf("Bien, pero hay que mejorar ;)");
                break;
                
            case 6:
                
                printf("¡A ver si la pŕóxima lo aciertas antes!");
                break;
                
            case 7:
                
                printf("Aunque eres bastente lento...");
                break;
                
            case 8:
                
                printf("Aunque los he visto mejores la verdad...");
                break;
                
            case 9:
                printf("Acertaste, pero la próxima vez cúrratelo más... jijiji");
                break;
        }
        
        printf("\t\t\t\t¡Hasta la próxima!\n\n");
    }

    return 0;
}

