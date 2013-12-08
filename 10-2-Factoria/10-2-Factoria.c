/* 
 * File:   10-2-Factoria.c
 * Author: Gartzia
 *
 * Created on 7 de diciembre de 2013, 22:13
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N_TRABAJADORES 100
#define N_NOMBRE 15
#define N_APELLIDOS 30
#define N_DIRECCION 50
#define N_SEG_SOCIAL 11
#define N_CTA_CORRIENTE 20

typedef struct
{
    unsigned int dia;
    unsigned int mes;
    unsigned int anno;
    
}date;

typedef struct
{
    char nombre[N_NOMBRE];
    char apellidos[N_APELLIDOS];
    char direccion[N_DIRECCION];
    date fecha;
}personal;

typedef struct
{
    int seg_social[N_SEG_SOCIAL];
    int cta_corriente[N_CTA_CORRIENTE];
}cuentas;
/*
 * 
 */
/**/
void limpiar_buffer();
void pausa();
/*MEMORIA*/
personal **reserva_memoria();
cuentas **reserva_memoria2();
void liberar_memoria(personal **trabajadores, int n_trabajadores);
void liberar_memoria2(cuentas **trabajadores, int n_trabajadores);
/*FICHERO PERSONAL*/
void crear_fichero_personal();
void recoger_datos(personal **trabajadores, int n_trabajadores);
void visualizar_personal();
/*FICHERO CUENTAS*/
void crear_fichero_cuentas();
void recoger_cuentas(cuentas **trabajadores, int n_trabajadores);
void visualizar_cuentas();
/**/
void unir_ficheros();
void visualizar_bapptel();
/**/
void borrar_enter(char *nombre);
/**/
int main()
{
    system("clear");
    
    crear_fichero_personal();
    visualizar_personal();
    
    crear_fichero_cuentas();
    visualizar_cuentas();
    
    unir_ficheros();
    visualizar_bapptel();

    printf("\n\nFIN DE PROGRAMA\n");
    
    return (0);
}

void limpiar_buffer()
{
    fflush(stdout);
    fpurge(stdin);
}
personal **reserva_memoria()
{
    personal **ptr_trabajadores;
    if((ptr_trabajadores=(personal **)malloc(N_TRABAJADORES*sizeof(personal *)))==NULL)
    {
        printf("\nInsuficiente memoria.\n");
        exit (-1);
    }
    
    return ptr_trabajadores;
}

cuentas **reserva_memoria2()
{
    cuentas **ptr_trabajadores;
    if((ptr_trabajadores=(cuentas **)malloc(N_TRABAJADORES*sizeof(cuentas *)))==NULL)
    {
        printf("\nInsuficiente memoria.\n");
        exit (-1);
    }
    
    return ptr_trabajadores;
}

void liberar_memoria(personal **trabajadores, int n_trabajadores)
{
    int i;
    
    for(i=0;i<n_trabajadores;i++)
    {
        free(trabajadores[i]);
    }
    free(trabajadores);
}

void liberar_memoria2(cuentas **trabajadores, int n_trabajadores)
{
    int i;
    
    for(i=0;i<n_trabajadores;i++)
    {
        free(trabajadores[i]);
    }
    free(trabajadores);
}

void pausa()
{
    int Ok=0; char caracter;
    
    do
    {
    printf("\nIntroduce <ENTER> para continuar\n...");
    limpiar_buffer();
    Ok=scanf("%c", &caracter);
    }while(!Ok || caracter!='\n');

    system("clear");
}

void crear_fichero_personal()
{
    FILE *ptr_fichero;
    personal **trabajadores=reserva_memoria();
    int Ok=0, n_trabajadores=0; char opcion;
    
    if((ptr_fichero=fopen("PERSONAL.dat","wb"))==NULL)
    {
        printf("\nErroe al abrir/crear el archivo del personal.\n");
        exit (2);
    }
    else
    {
        printf("\nDATOS PERSONALES DE LOS TRABAJADORES DE BAPPTEL");
        do
        {
            n_trabajadores++;
            recoger_datos(trabajadores, n_trabajadores);
            fwrite(trabajadores[n_trabajadores-1], sizeof(personal), 1, ptr_fichero);
            
            printf("\n¿Quieres introducir más datos? (s/n)");
            limpiar_buffer();
            Ok=scanf("%c", &opcion);
        }while(!Ok || opcion=='s' || opcion=='s');
    }
    
    printf("\nSe cierra el fichero PERSONAL.dat\n");
    fclose(ptr_fichero);
    liberar_memoria(trabajadores, n_trabajadores);
    
    pausa();
}

void recoger_datos(personal **trabajadores, int n_trabajadores)
{
    trabajadores[n_trabajadores-1]=(personal *)malloc(sizeof(personal));
    
    printf("\nTrabajador: %d\n", n_trabajadores);
    printf("\n\nNombre: ");
    limpiar_buffer();
    fgets(trabajadores[n_trabajadores-1]->nombre, N_NOMBRE, stdin);
    borrar_enter(trabajadores[n_trabajadores-1]->nombre);
    
    printf("\nApellidos: ");
    limpiar_buffer();
    fgets(trabajadores[n_trabajadores-1]->apellidos, N_APELLIDOS, stdin);
    borrar_enter(trabajadores[n_trabajadores-1]->apellidos);
    
    printf("\nDirección: ");
    limpiar_buffer();
    fgets(trabajadores[n_trabajadores-1]->direccion, N_DIRECCION, stdin);
    borrar_enter(trabajadores[n_trabajadores-1]->direccion);
    
    printf("\nFecha de ingreso: (dd/mm/aa)");
    limpiar_buffer();
    scanf("%u/%u/%u",
            &trabajadores[n_trabajadores-1]->fecha.dia,
            &trabajadores[n_trabajadores-1]->fecha.mes,
            &trabajadores[n_trabajadores-1]->fecha.anno);
}

void visualizar_personal()
{
    FILE *ptr_fichero;
    personal trabajadores;
    
    if((ptr_fichero=fopen("PERSONAL.dat","rb"))==NULL)
    {
        printf("\nError a leer el archivo del persona.\n");
        exit (2);
    }
    else
    {
        printf("%35s", "PERSONAL");
        printf("\n-------------------------------------------------------------------------\n\n");
        printf("%10s%20s%20s%23s", "NOMBRE", "APELLIDOS", "DIRECCION", "FECHA DE INGRSO\n");
        while(fread(&trabajadores, sizeof(personal), 1, ptr_fichero))
        {
            printf("\n%10s%20s%25s%9u/%u/%u\n",
                    trabajadores.nombre,
                    trabajadores.apellidos,
                    trabajadores.direccion,
                    trabajadores.fecha.dia,
                    trabajadores.fecha.mes,
                    trabajadores.fecha.anno);
        }
    }
    
    pausa();
}

void crear_fichero_cuentas()
{
    FILE *ptr_fichero;
    cuentas **trabajadores=reserva_memoria2();
    int n_trabajadores=0, Ok=0; char opcion;
    
    if((ptr_fichero=fopen("CUENTAS.dat", "wb"))==NULL)
    {
        printf("\nError al abrir/crear el archivo CUENTS.dat.\n");
        exit (2);
    }
    else
    {
        printf("\nCUENTAS DE LOS TRABAJADORES DE BAPPTEL");
        do
        {
            n_trabajadores++;
            recoger_cuentas(trabajadores, n_trabajadores);
            fwrite(trabajadores[n_trabajadores-1], sizeof(cuentas), 1, ptr_fichero);
            
            printf("\n¿Quieres introducir mas datos? (s/n)\n");
            limpiar_buffer();
            Ok=scanf("%c", &opcion);
            
        }while(!Ok || opcion=='S' || opcion=='s');
    }
    printf("\nSe cierra fichero.\n");
    fclose(ptr_fichero);
    
    liberar_memoria2(trabajadores, n_trabajadores);
    
    pausa();
}

void recoger_cuentas(cuentas **trabajadores, int n_trabajadores)
{
    int i;
    
    trabajadores[n_trabajadores-1]=(cuentas *)malloc(sizeof(cuentas));
    
    printf("\nTrbajador: %d\n", n_trabajadores);
    printf("\nSeguridad Social: ");
    limpiar_buffer();
    for(i=0;i<N_SEG_SOCIAL;i++)
    {
        scanf("%1d", &trabajadores[n_trabajadores-1]->seg_social[i]);
    }
    
    printf("\nCuenta corriente: ");
    limpiar_buffer();
    for(i=0;i<N_CTA_CORRIENTE;i++)
    {
        scanf("%1d", &trabajadores[n_trabajadores-1]->cta_corriente[i]);
    }
}

void visualizar_cuentas()
{
    FILE *ptr_trabajadores;
    cuentas trabadores;
    int i; char justificado=' ';
    
    if((ptr_trabajadores=fopen("CUENTAS.dat", "rb"))==NULL)
    {
        printf("\nError al abrir el fichero CUENTAS.dat.\n");
        exit(2);
    }
    else
    {
        printf("%35s", "CUENTAS");
        printf("\n-------------------------------------------------------------------------\n\n");
        printf("%20s%30s", "SEGURIDAD SOCIAL", "CUENTA CORRIENTE\n\n");

        while(fread(&trabadores, sizeof(cuentas), 1, ptr_trabajadores))
        {
            printf("%*c", 9, justificado);
            for(i=0;i<N_SEG_SOCIAL;i++)
            {
                printf("%d", trabadores.seg_social[i]);
            }

            printf("%*c", 10, justificado);
            for(i=0;i<N_CTA_CORRIENTE;i++)
            {
                printf("%d", trabadores.cta_corriente[i]);
            }
        }
        fclose(ptr_trabajadores);
    }
    
    pausa();
}

void borrar_enter(char *nombre)
{
    int i, longitud;
    
    longitud=strlen(nombre);
    
    for(i=0;i<longitud;i++)
    {
        if(nombre[i]=='\n')
        {
            nombre[i]='\0';
        }
    }
}

void unir_ficheros()
{
    FILE *ptr_fichero1, *ptr_fichero2, *ptr_fichero3;
    personal trabaj1;
    cuentas trabaj2;
    
    if((ptr_fichero3=fopen("BAPPTEL.dat","wb"))==NULL)
    {
        printf("\nError al crear/leer el fichero BAPPTEL.dat\n");
        exit(2);
    }
    else
    {
        if((ptr_fichero1=fopen("PERSONAL.dat","rb"))==NULL)
        {
            printf("\nError al abrir el fichero PERSONAL.dat\n");
            exit(2);
        }
        else
        {
            if((ptr_fichero2=fopen("CUENTAS.dat","rb"))==NULL)
            {
                printf("\nError al abrir el fichero PERSONAL.dat\n");
                exit(2);
            }
            else
            {
                while(
                        (fread(&trabaj1, sizeof(personal), 1, ptr_fichero1)) && 
                        (fread(&trabaj2, sizeof(cuentas), 1, ptr_fichero2)))
                {
                    //guardar todo en un mismo registro o en diferentes registros??????
                    fwrite(&trabaj1, sizeof(personal), 1, ptr_fichero3);
                    fwrite(&trabaj2, sizeof(cuentas), 1, ptr_fichero3);
                }
            }
        }
        printf("\nSe cierran ficheros.\n");
        fclose(ptr_fichero1);
        fclose(ptr_fichero2);
        fclose(ptr_fichero3);
    }
    
    pausa();
}

void visualizar_bapptel()
{
    FILE *ptr_fichero;
    personal trabaj1;
    cuentas trabaj2;
    int i;
    
    if((ptr_fichero=fopen("BAPPTEL.dat","rb"))==NULL)
    {
        printf("\nError al abrir el fichero PERSONAL.dat\n");
        exit(2);
    }
    else
    {
        while(
                (fread(&trabaj1, sizeof(personal), 1, ptr_fichero)) && 
                 (fread(&trabaj2, sizeof(cuentas), 1, ptr_fichero)))
        {
            printf("\n");
            printf("%s\n%s\n%s\n%u/%u/%u\n",
                    trabaj1.nombre,
                    trabaj1.apellidos,
                    trabaj1.direccion,
                    trabaj1.fecha.dia,
                    trabaj1.fecha.mes,
                    trabaj1.fecha.anno);
            
            for(i=0;i<N_SEG_SOCIAL;i++)
             {
                 printf("%d", trabaj2.seg_social[i]);
             }

            printf("\n");
            for(i=0;i<N_CTA_CORRIENTE;i++)
            {
                printf("%d", trabaj2.cta_corriente[i]);
            }
        }
    }
}