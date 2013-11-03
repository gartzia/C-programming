/* 
 * File:   2-Areas.c
 * Author: Gartzia
 *
 * Created on 30 de septiembre de 2013, 18:34
 */

#include <stdio.h>
#include <math.h>
/*#define PI 3.1415*/
/*
 * 
 */
int main(void) {
    
    
    float radio;
    float base;
    float altura;
    float lado;
    int eleccion;
    
    int condicion=0;
    while(condicion == 0)
    {
        
        printf("\nCalcular el área de:\n1-Círculo\n2-Triángulo\n3-Cuadrado\n\n");
        fflush ( stdout );
        fpurge ( stdin );
        scanf("%d", &eleccion);   
        
        switch(eleccion)
        {
            case 1:
            
                
                printf("\nIntrduce el radio del círculo:\n");
                fflush ( stdout );
                fpurge ( stdin );
                scanf("%f", &radio);
            
                float area1;
                /*area1=2*PI*radio;*/
                area1=2*M_PI*radio;
            
                printf("\nEl área del círculo es de: %f u².\n", area1);
                break;
            
            case 2:
                
                printf("\nInserta la base del triángulo:\n");
                fflush (stdout );
                fpurge ( stdin );
                scanf("%f", &base);
                printf("\nInserta la altura del triángulo:\n");
                fflush (stdout );
                fpurge ( stdin );
                scanf("%f", &altura);
            
                float area2;
                area2=(base*altura)/2;
            
                printf("\nEl área del triángulo es de: %f u².\n", area2);
                break;
            
            case 3:
                
                printf("\nIserta del lado del cuadrado:\n");
                fflush (stdout );
                fpurge (stdin );
                scanf("%f", &lado);
            
                float area3;
                area3=lado*lado;
            
                printf("\El área del cuadrado es de: %f u².\n", area3);
                break;
            
            default:
                printf("\n\nDebes introducir una opcion correcta.\n\n");
        }
        
    printf("\nPara volver elegir un objeto, introduce 0\nPara salir cualquier otro número\n\n");
    fflush( stdout );
    fpurge ( stdin );
    scanf("%d", &condicion);
    
    };
    printf("\n¡Gracias por usar este programa!\n\n");
    return 0;
}

