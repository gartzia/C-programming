/* 
 * File:   5-3-Taylor_Coseno_Seno_Tangente_Grados_por_VALOR.c
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

float coseno(float radian);
float seno(float radian);
float tangente(float radian);
/***/
float sinuidal (float radian, float onda, int tipo);
int factorial (int numero);
float exponente(int j, float numero);
/***/
float grados (float r);


int main(void) {
    
    float engrados, radian, valor;
    int opcion;
    
    
    printf("Elige función a calcular:\nCos(x)\t-> 1\nSen(x)\t-> 2\nTang(x)\t-> 3\n");
    fflush(stdout);
    fpurge(stdin);
    scanf("%d", &opcion);
    
    printf("\nIserta los radianes:\n");
    fflush (stdout);
    fpurge(stdin);
    scanf("%f", &radian);
    
    switch(opcion)
    {
        case 1:
            valor=coseno(radian);

            printf("El valor de Cos(%.3f)=%.3f u.\n", radian, valor);
            break;
            
        case 2:
            valor=seno(radian);

            printf("El valor de Sen(%.3f)=%.3f u.\n", radian, valor);
            break;
            
        case 3:
            valor=tangente(radian);
            
            printf("El valor de Tang(%.3f)=%.3f u.\n", radian, valor);
            break;
            
        default:
            printf("No has insertado ninguna opción válida. Fin del programa.\n");

    }
    
    printf("\nIserta un 0 si quieres salir, cualquier otro valor para pasar los radianes a grados:\n");
    fflush(stdout);
    fpurge(stdin);
    scanf("%d", &opcion);
    
    if(opcion==0)
    {
        printf("Programa finalizado\n");
    }
    else
    {
        engrados=grados(radian);
        printf("%.3f rad == %.3fº\n", radian, engrados);
        printf("Programa finalizado\n");
    }

    return 0;
}
/*--------------------------------------------------------*/
/*
Taylor para Coseno:
  Cos(x)=1 - x²/2! + x⁴/4! - ......

 --------------------------------------------------------- 
 
Taylor para Seno:
  Sen(x)=0 +  x/1! - x³/3! + ......
*/
/*--------------------------------------------------------*/
float coseno(float radian)
{
    int tipo=1;
    float valor, onda=1;
    
    valor=sinuidal(radian, onda, tipo);
    
    return valor;
}

/*--------------------------------------------------------*/

float seno(float radian)
{
    int tipo=0;
    float valor, onda=0;
    
    valor=sinuidal(radian, onda, tipo);
    
    return valor;
}

/*--------------------------------------------------------*/

float tangente(float radian)
{   
    float valor, valor1, valor2;
    
    valor1=coseno(radian);
    valor2=seno(radian);
    
    valor=valor2/valor1;
    
    return valor;
}

/*--------------------------------------------------------*/
float sinuidal(float radian, float onda, int tipo)
{
    int i, signo, modo;
    float division=1;
    
    for(i=1;division>0.005;i++)
    {
        if(tipo==1)
        {
            modo=i*2;
            //printf("par: %d\n", modo);
        }
        else
        {
            modo=(i*2)-1;
            //printf("impar:%d\n", modo);
        }
        
        division=exponente(modo, radian)/factorial(modo);
        
        if(i%2==0)
        {
            signo=1;
        }
        else
        {
            signo=-1;
        }
        
        if(tipo==0)
        {
            signo=-signo;
        }
        
        onda+=division*signo;
        //printf("onda: %f", onda);
    }

    return onda;
}

/*--------------------------------------------------------*/
int factorial(int numero)
{
    int i;
    int factorial;
    
    for(i=1,factorial=1;i<=numero;i++)
    {
        factorial*=i;
        //printf("i=%d factorial=%d\n", i, factorial);
    }
    
    return factorial;
}

/*--------------------------------------------------------*/
float exponente(int j, float numero)
{
    int i;
    int exponente;
    
    for(i=1,exponente=1;i<=j;i++)
    {
        exponente*=numero;
        //printf("i=%d exponente=%d\n", i, exponente);
    }
    
    return exponente;
}

/*--------------------------------------------------------*/
float grados (float r)
{
    float valor;
    
    valor=(360*r)/(M_PI*2);
   
           
    return valor;
}

/*---FIN---*/