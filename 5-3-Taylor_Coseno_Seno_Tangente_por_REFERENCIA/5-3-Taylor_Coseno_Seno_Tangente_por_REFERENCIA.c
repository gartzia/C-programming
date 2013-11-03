/* 
 * File:   5-3-Taylor_Coseno_Seno_Tangente_por_REFERENCIA.c
 * Author: Gartzia
 *
 * Created on 11 de octubre de 2013, 1:32
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */

void coseno(float *radian, float *onda);
void seno(float *radian, float *onda);
void tangente(float *radian, float *onda);
/***/
void sinuidal (float *radian, float *onda, int *tipo);
int factorial (int *modo);
float exponente(int *modo, float *radian);
/***/
void grados (float *radian, float *b);


int main(void) {
    
    float engrados, radian, onda;
    int opcion;
    
    
    printf("Elige función a calcular:\nCos(x)\t-> 1\nSen(x)\t-> 2\nTang(x)\t-> 3\n");
    fflush(stdout);
    fpurge(stdin);
    scanf("%d", &opcion);
    
    printf("\nInserta los radianes:\n");
    fflush (stdout);
    fpurge(stdin);
    scanf("%f", &radian);
    
    switch(opcion)
    {
        case 1:
            coseno(&radian, &onda);

            printf("\nEl valor de Cos(%.3f)=%.3f u.\n", radian, onda);
            break;
            
        case 2:
            seno(&radian, &onda);

            printf("\nEl valor de Sen(%.3f)=%.3f u.\n", radian, onda);
            break;
            
        case 3:
            tangente(&radian, &onda);
            
            printf("\nEl valor de Tang(%.3f)=%.3f u.\n", radian, onda);
            break;
            
        default:
            printf("\nNo has insertado ninguna opción válida.\n");

    }
    
    printf("\nInserta un 0 si quieres salir, cualquier otro valor para pasar los radianes a grados:\n");
    fflush(stdout);
    fpurge(stdin);
    scanf("%d", &opcion);
    
    if(opcion==0)
    {
        printf("\nPrograma finalizado\n");
    }
    else
    {
        grados(&radian, &engrados);
        printf("\n%.3f rad = %.3fº\n", radian, engrados);
        printf("\nPrograma finalizado\n");
    }

    return 0;
}
/*--------------------------------------------------------

Taylor para Coseno:
  Cos(x)=1 - x²/2! + x⁴/4! - ......

 --------------------------------------------------------- 
 
Taylor para Seno:
  Sen(x)=0 +  x/1! - x³/3! + ......

 --------------------------------------------------------- 

Tangente:
  Sen(x) / Cos(x)

--------------------------------------------------------*/
void coseno(float *radian, float *onda)
{
    int tipo=1;
    *onda=1;
    
    sinuidal(radian, onda, &tipo);
    
}

/*--------------------------------------------------------*/

void seno(float *radian, float *onda)
{
    int tipo=0;
    *onda=0;
    
    sinuidal(radian, onda, &tipo);
    
}

/*--------------------------------------------------------*/

void tangente(float *radian, float *onda)
{   
    float valor;
    
    coseno(radian, onda);
    valor=*onda;
    
    seno(radian, onda);
    
    
    *onda/=valor;
    
}

/*--------------------------------------------------------*/
void sinuidal(float *radian, float *onda, int *tipo)
{
    int i, signo, modo;
    float division=1;
    
    for(i=1;division>0.005;i++)
    {
        if(*tipo==1)
        {
            modo=i*2;
            //printf("par: %d\n", modo);
        }
        else
        {
            modo=(i*2)-1;
            //printf("impar:%d\n", modo);
        }
        
        division=exponente(&modo, radian)/factorial(&modo);
        
        if(i%2==0)
        {
            signo=1;
        }
        else
        {
            signo=-1;
        }
        
        if(*tipo==0)
        {
            signo=-signo;
        }
        
        *onda+=division*signo;
        //printf("onda: %f\n", *onda);
    }

}

/*--------------------------------------------------------*/
int factorial(int *modo)
{
    int i;
    int factorial;
    
    for(i=1,factorial=1;i<=(*modo);i++)
    {
        factorial*=i;
        //printf("i=%d factorial=%d\n", i, factorial);
    }
    
    return factorial;
}

/*--------------------------------------------------------*/
float exponente(int *modo, float *radian)
{
    int i;
    int exponente;
    
    for(i=1,exponente=1;i<=(*modo);i++)
    {
        exponente *= *radian;
        //printf("i=%d exponente=%d\n", i, exponente);
    }
    
    return exponente;
}

/*--------------------------------------------------------*/
void grados (float *radian, float *engrados)
{
    
    *engrados=(360* *radian)/(M_PI*2);
    
}

/*---FIN---*/