/* 
 * File:   10-3-Aeropuerto.c
 * Author: Gartzia
 *
 * Created on 8 de diciembre de 2013, 14:37
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VUELOS 10
#define MAX_PLAZAS 100
#define HORAS 23
#define N_DESTINO 15 //Nº caracteres
#define SALIDA 6 //Nº caracteres (hh:mm + '\0'))

#define N_MENSAJES 6 //Nª de opciones en menu
#define NCARAC_MEN 100 //Nº caracteres por mensaje
#define MENS_1 "Información de los vuelos"
#define MENS_2 "Añadir un nuevo vuelo"
#define MENS_3 "Cancelar un vuelo"
#define MENS_4 "Modificar horario de salida de un vuelo"
#define MENS_5 "Actualizar el número de plazas libres de un vuelo"
#define MENS_6 "Salir del programa"
/*
 * 
 */
typedef struct
{
    int n_vuelo; //Nº de vuelo
    char destino[N_DESTINO];
    char salida[SALIDA]; //Horario de salida (hh:mm)
    int plazasl; //plazas libres
}vuelo_datos;
/*
 * 
 */
void menu();
int showmenu();
/**/
void abrir_fichero(vuelo_datos **vuelo, int *n_vuelos);
void guardar_fichero(vuelo_datos **vuelo, int *n_vuelos);
/**/
vuelo_datos **reserva_memoria();
void liberar_memoria(vuelo_datos **vuelo, int *n_vuelos);
/**/
void visualizar_vuelos(vuelo_datos **vuelo, int *n_vuelos);
/**/
void aniadir_vuelo(vuelo_datos **vuelo, int *n_vuelos);
void borrar_enter(char *nombre, int n_vuelos);
void convertir_a_mayusculas(vuelo_datos **vuelo, int n_vuelos);
int comprobar_horario(char *nombre);
int comprobrar_si_existe(vuelo_datos **vuelos, int n_vuelos);
void ordenar(vuelo_datos **vuelo, int n_vuelos);
int busqueda_binaria(char *nombre, vuelo_datos **vuelo, int n_vuelos);
int busqueda_binaria2(int numero, vuelo_datos **vuelo, int n_vuelos);
void actualizar_numero_vuelo(vuelo_datos **vuelo, int n_vuelos);
/**/
void cancelar_vuelo(vuelo_datos **vuelo, int *n_vuelos);
/**/
void modificar_salida(vuelo_datos **vuelo, int *n_vuelos);
/**/
void modificar_plazasl(vuelo_datos **vuelo, int *n_vuelos);
/**/
int main()
{
    menu();

    return (EXIT_SUCCESS);
}

void limpiar_buffer()
{
    fflush(stdout);
    fpurge(stdin);
}

void pausa(int tipo)
{
    char caracter;
    
    do
    {
        printf("\nIntroduce <ENTER> para %s\n...", !tipo?"continuar":"menu");
        limpiar_buffer();
        scanf("%c", &caracter);
    }while(caracter!='\n');
    
    system("clear");
}

vuelo_datos **reserva_memoria()
{
    vuelo_datos **ptr_vuelo;
    
    if((ptr_vuelo=(vuelo_datos **)malloc(MAX_VUELOS*sizeof(vuelo_datos *)))==NULL)
    {
        printf("Insuficiente memeoriaO.\n");
        exit(-1);
    }
    
    return ptr_vuelo;
}

void liberar_memoria(vuelo_datos **vuelo, int *n_vuelos)
{
    int i;
    
    if(*n_vuelos)
    {
        for(i=0;i<*n_vuelos;i++)
        {
            free(vuelo[i]);
        }
    }
    free(vuelo);
}

void menu()
{   
    int opcion=0, n_vuelos;
    vuelo_datos **vuelo;
    
    
    
    while(opcion!=N_MENSAJES)
    {
        opcion=showmenu();
        
        switch(opcion)
        {
            case 1:
                        vuelo=reserva_memoria();
                visualizar_vuelos(vuelo, &n_vuelos);
                        liberar_memoria(vuelo, &n_vuelos);
                break;
            case 2:
                        vuelo=reserva_memoria();
                aniadir_vuelo(vuelo, &n_vuelos);
                        liberar_memoria(vuelo, &n_vuelos);
                break;
            case 3:
                        vuelo=reserva_memoria();
                cancelar_vuelo(vuelo, &n_vuelos);
                        liberar_memoria(vuelo, &n_vuelos);
                break;
            case 4:
                modificar_salida(vuelo, &n_vuelos);
                break;
            case 5:
                modificar_plazasl(vuelo, &n_vuelos);
                break;
        }
    }
}

int showmenu()
{
    char mensajes[N_MENSAJES][NCARAC_MEN]={MENS_1,MENS_2,MENS_3,MENS_4,MENS_5,MENS_6};
    unsigned opcion, i;
    
    do
    {        
        printf("\n------------------------------------------------\n");
        printf("\nElija una de las siguientes opciones:\n\n");
    
        for(i=0;i<N_MENSAJES;i++)
        {
            printf("%d.-%s\n", i+1, mensajes[i]);
        }
        printf("\n");
        scanf("%d", &opcion);

        system("clear");
    }while(opcion<1 || opcion>N_MENSAJES);
    
    return opcion;
}

void abrir_fichero(vuelo_datos **vuelo, int *n_vuelos)
{
    FILE *pf; //puntero al fichero VUELOS.dat
    vuelo_datos paso;
    *n_vuelos=0;
    
    if((pf=fopen("VUELOS.dat","rb"))==NULL)
    {
        //printf("No hay ningún vuelo registrado\n");
        //exit (EXIT_FAILURE);
    }
    else
    {
        while(fread(&paso, sizeof(vuelo_datos), 1, pf))
        {
            ++(*n_vuelos);
            vuelo[*n_vuelos-1]=(vuelo_datos *)malloc(sizeof(vuelo_datos));
            
            strcpy(vuelo[*n_vuelos-1]->destino, paso.destino);
            strcpy(vuelo[*n_vuelos-1]->salida, paso.salida);
            vuelo[*n_vuelos-1]->plazasl=paso.plazasl;
            vuelo[*n_vuelos-1]->n_vuelo=paso.n_vuelo;
        }
    }
    fclose(pf);
}

void guardar_fichero(vuelo_datos **vuelo, int *n_vuelos)
{
    FILE *pf;
    int i;
    
    if((pf=fopen("VUELOS.dat","wb"))==NULL)
    {
        printf("Error al abrir/crear el fichero VUELOS.dat.\n");
        exit (EXIT_FAILURE);
    }
    else
    {
        for(i=0;i<*n_vuelos;i++)
        {
            fwrite(vuelo[i], sizeof(vuelo_datos), 1, pf);
        }
    }
    fclose(pf);
}

void visualizar_vuelos(vuelo_datos **vuelo, int *n_vuelos)
{
    int i;
    
    abrir_fichero(vuelo, n_vuelos);

    if(*n_vuelos)
    {
    printf("%10s%10s%20s%20s\n\n", "NºVUELO", "DESTINO", "HORA DE SALIDA", "NºPLAZAS LIBRES");
    for(i=0;i<*n_vuelos;i++)
    {
        printf("%7d%12s%16s%16d\n",
                vuelo[i]->n_vuelo,
                vuelo[i]->destino,
                vuelo[i]->salida,
                vuelo[i]->plazasl);
    }
    printf("\n");
    }
    else
    {
        printf("\nNo hay vuelos registrados.\n");
    }
}

void aniadir_vuelo(vuelo_datos **vuelo, int *n_vuelos)
{
    int existe=0, comprobar;

    abrir_fichero(vuelo, n_vuelos);

    ++*n_vuelos;
    
    vuelo[*n_vuelos-1]=(vuelo_datos *)malloc(sizeof(vuelo_datos));
    
    printf("\nNúmero de vuelos: %d\n", *n_vuelos);
    printf("\n-------------------------------------\n");
    printf("\nRellene los campos:\n");
    
    printf("\nDestino: ");
    limpiar_buffer();
    fgets(vuelo[*n_vuelos-1]->destino,N_DESTINO,stdin);
    borrar_enter(vuelo[*n_vuelos-1]->destino, *n_vuelos);
    
    convertir_a_mayusculas(vuelo, *n_vuelos);
    
    do
    {
        printf("\nHorario de Salida (hh:mm): ");
        limpiar_buffer();
        scanf("%s", vuelo[*n_vuelos-1]->salida);
        borrar_enter(vuelo[*n_vuelos-1]->salida, *n_vuelos);

        comprobar=comprobar_horario(vuelo[*n_vuelos-1]->salida);
    }while(comprobar);
    
    do
    {
        printf("\nNº plazas libres: ");
        limpiar_buffer();
        scanf("%d", &vuelo[*n_vuelos-1]->plazasl);
    }while(vuelo[*n_vuelos-1]->plazasl>MAX_PLAZAS);
    
    comprobrar_si_existe(vuelo, *n_vuelos);
    
    if(existe>1)
    {
        printf("\nHay una vuelo registrado con destino y hora de salida iguales.\n");
        
        //borra la empresa liberando la memoria:
        free(vuelo[*n_vuelos-1]);
        
        --*n_vuelos;
    }
    else
    {
        ordenar(vuelo, *n_vuelos);
        actualizar_numero_vuelo(vuelo, *n_vuelos);
    }
    
    guardar_fichero(vuelo, n_vuelos);
}

void borrar_enter(char *nombre, int n_vuelos)
{
    int longitud;
    
    longitud=strlen(nombre);
    
    if(nombre[longitud-1]=='\n')
    {
        nombre[longitud-1]='\0';
    }
}

void convertir_a_mayusculas(vuelo_datos **vuelo, int n_vuelos)
{
    int i, longitud;
    
    longitud=strlen(vuelo[n_vuelos-1]->destino);
    
    for(i=0;i<longitud;i++)
    {
        if(vuelo[n_vuelos-1]->destino[i]>='a' && vuelo[n_vuelos-1]->destino[i]<='z')
        {
            vuelo[n_vuelos-1]->destino[i]-=32;
        }
    }
}

int comprobar_horario(char *nombre)
{
    int h1, h2, m1, m2, horas;
    
    h1=(int)nombre[0]-48;
    h2=(int)nombre[1]-48;
    m1=(int)nombre[3]-48;
    m2=(int)nombre[4]-48;
    horas=h1*10+h2;
    
    if(h1<0 || h1>2 || horas>HORAS)
    {
        printf("\nIntroduce una hora correcta.\n");
        return 1;
    }
    else
    {
        if(m1<0 || m1>5 || m2<0 || m2>9)
        {
            printf("\nIntroduce una hora correcta.\n");
            return 1;
        }
    }
        
    return 0;
}

int comprobrar_si_existe(vuelo_datos **vuelos, int n_vuelos)
{
    int i, existe=0;
    
    for(i=0;i<n_vuelos;i++)
    {
        if((strcmp(vuelos[n_vuelos-1]->destino, vuelos[i]->destino)==0) && 
           (strcmp(vuelos[n_vuelos-1]->salida, vuelos[i]->salida)==0))
        {
            existe++;
        }
    }
    
    return existe;
}

void ordenar(vuelo_datos **vuelo, int n_vuelos)
{
    int i, posicion, mitad;
    vuelo_datos *paso=vuelo[n_vuelos-1];

    mitad=busqueda_binaria(vuelo[n_vuelos-1]->salida, vuelo, n_vuelos);
    
    //compara donde está la posición del puntero
    if(strcmp(vuelo[n_vuelos-1]->salida, vuelo[mitad]->salida)<0)
    {
        posicion=mitad;
    }
    else
    {
        posicion=mitad+1;
    }
    
    //desplaza punteros
    for(i=(n_vuelos)-1;i>=posicion;i--)
    {
        vuelo[i+1]=vuelo[i];
    }
    
    //pasa la estructura recogida a la posición del array correspondiente
    vuelo[posicion]=paso; 
}

int busqueda_binaria(char *nombre, vuelo_datos **vuelo, int n_vuelos)
{
    int principio=0, final=n_vuelos-1, mitad=(principio+final)/2;
    
    //busco posicion posible
    while(principio<final && strcmp(nombre, vuelo[mitad]->salida)!=0)
    {
        if(strcmp(nombre, vuelo[mitad]->salida)<0)
        {
            final=mitad-1;
        }
        else
        {
            principio=mitad+1;
        }
        mitad=(principio+final)/2;
    }
    
    return mitad;
}

void actualizar_numero_vuelo(vuelo_datos **vuelo, int n_vuelos)
{
    int i;
    
    for(i=0;i<n_vuelos;i++)
    {
        vuelo[i]->n_vuelo=i+1;
    }
}

void cancelar_vuelo(vuelo_datos **vuelo, int *n_vuelos)
{
    int i, mitad;
    unsigned numero;
    
    abrir_fichero(vuelo, n_vuelos);
    
    if(*n_vuelos)
    {
        printf("\n¿Número del vuelo?: ");
        limpiar_buffer();
        scanf("%u", &numero);
        
        mitad=busqueda_binaria2(numero, vuelo, *n_vuelos);
        
        if(numero==vuelo[mitad]->n_vuelo)
        {
            if(mitad<*n_vuelos-1)
            {
                for(i=mitad;mitad<*n_vuelos;mitad++)
                {
                    vuelo[mitad]=vuelo[mitad+1];
                }
            }
            (*n_vuelos)--;
            
            //si no hay empresas, ordenar dará un error de segmentación porque no hay que ordenar
            if(*n_vuelos)
            {
                ordenar(vuelo, *n_vuelos);
                actualizar_numero_vuelo(vuelo, *n_vuelos);
            }
        }    
        else
        {
            printf("\nNo existe vuelo con dicho número.\n");
        }
    }
    else
    {
        printf("\nNo hay vuelos registrados.\n");
    }
    
    guardar_fichero(vuelo, n_vuelos);
}

int busqueda_binaria2(int numero, vuelo_datos **vuelo, int n_vuelos)
{
    int principio=0, final=n_vuelos-1, mitad=(principio+final)/2;
    
    //busco posicion posible
    while(principio<final && numero!=vuelo[mitad]->n_vuelo)
    {
        if(numero<vuelo[mitad]->n_vuelo)
        {
            final=mitad-1;
        }
        else
        {
            principio=mitad+1;
        }
        mitad=(principio+final)/2;
    }
    
    return mitad;
}

void modificar_salida(vuelo_datos **vuelo, int *n_vuelos)
{
    int mitad, numero, i;
    char salida[SALIDA];
    vuelo_datos *paso;
    
    abrir_fichero(vuelo, n_vuelos);
    
    if(*n_vuelos)
    {
        printf("\n¿Número del vuelo?: ");
        limpiar_buffer();
        scanf("%d", &numero);
        
        mitad=busqueda_binaria2(numero, vuelo, *n_vuelos);

        if(numero==vuelo[mitad]->n_vuelo)
        {
            printf("\n¿Horario de Salida a modificar (hh:mm)?: ");
            limpiar_buffer();
            scanf("%s", salida);
            borrar_enter(salida, *n_vuelos);
            
            strcpy(vuelo[mitad]->salida, salida);
            
            //lo elimino
            paso=vuelo[mitad];
            for(i=mitad;mitad<*n_vuelos;mitad++)
            {
                vuelo[mitad]=vuelo[mitad+1];
            }
            vuelo[*n_vuelos-1]=paso;
            
            ordenar(vuelo, *n_vuelos);
            actualizar_numero_vuelo(vuelo, *n_vuelos);
        }    
        else
        {
            printf("\nNo existe vuelo con dicho número.\n");
        }
    }
    else
    {
        printf("\nNo hay vuelos registrados.\n");
    }
    
    guardar_fichero(vuelo, n_vuelos);
}

void modificar_plazasl(vuelo_datos **vuelo, int *n_vuelos)
{
    int mitad, numero, plazas;
    
    abrir_fichero(vuelo, n_vuelos);
    
    if(*n_vuelos)
    {
        printf("\n¿Número del vuelo?: ");
        limpiar_buffer();
        scanf("%d", &numero);
        
        mitad=busqueda_binaria2(numero, vuelo, *n_vuelos);

        if(numero==vuelo[mitad]->n_vuelo)
        {
            printf("\n¿Nº de plazas libres actualizado?: ");
            limpiar_buffer();
            scanf("%d", &plazas);
            
            vuelo[mitad]->plazasl=plazas;
        }    
        else
        {
            printf("\nNo existe vuelo con dicho número.\n");
        }
    }
    else
    {
        printf("\nNo hay vuelos registrados.\n");
    }
    
    guardar_fichero(vuelo, n_vuelos);
}
