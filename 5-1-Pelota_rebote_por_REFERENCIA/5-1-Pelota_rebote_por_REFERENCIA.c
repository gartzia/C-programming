/* 
 * File:   5-1-Pelota_rebote_por_REFERENCIA.c
 * Author: Gartzia
 *
 * Created on 10 de octubre de 2013, 18:43
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void altura(float *h2, float *r);

int main(void)
{
    /*int i;*/
    float h;
    float rebote;
    float altura_final;
    int botes=0;
    
    printf("\nIserta la altura inicial:\nIserta el factor de rebote:\nInserta la altura final:\n");
    fflush (stdout);
    fpurge(stdin);
    scanf("%f %f %f", &h, &rebote, &altura_final);
    
    printf("\n----------------------------------\n");

    while(h>altura_final)
    {
        if(rebote==1)
        {
            break;
        }
        altura(&h, &rebote);
        botes++;
        printf("Altura alcanza: %f al bote %d\n", h, botes);
    }

    if(h==altura_final)
    {
        printf("----------------------------------");
        printf("\nEn el bote %d consigue llegar a la altura %f exactamente.\n", botes, altura_final);
    }
    else
    {
        printf("----------------------------------");
        printf("\nEn el bote %d no alcanzará los %f u.\n", botes, altura_final);
        h/=rebote;
        printf("Con %d bote(s) llegará a los %f u.\n", (botes-1), h);
    }
   
    
    return 0;
}

void altura (float *h2, float *r)
{
    *h2 *= *r;

    //return h;
}