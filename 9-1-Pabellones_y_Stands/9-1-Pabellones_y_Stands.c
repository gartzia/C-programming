/* 
 * File:   9-1-Pabellones_y_Stands.c
 * Author: Gartzia
 *
 * Created on 25 de noviembre de 2013, 18:43
 */

/********INCLUSIÓN DE LIBRERIAS********/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********DEFINICIONES DE CONSTANTES********/
#define JUSTIFICADO 45 //justificado de ancho en los títulos
#define NU_EMPRESAS 50 //número de empresas
#define NO_EMPRESAS 30 //nombre de empresa: número de caracteres
#define N_PABELLONES 5 //número de pabellones
#define N_MENSAJES 5   //número de mensajes en el menú
#define NC_MENSAJES 60 //número de caracteres para cada mensaje del menú

/********DECLARACIONES DE ESTRUCTURAS********/
typedef struct  //datos de cada empresa
{
    char nombre_empresa[NO_EMPRESAS];
    int numero_pabellon;
    int dias_de_alquiler;
    float metros_del_stand;
    float precio_alquiler;
}empresa_datos;

typedef struct //datos de cada pabellón
{
    float metros_totales;
    float metros_alquilados;
    float tarifa;
}pabellon_datos;

/*typedef struct //cadena para cada mensaje
{
    char mensaje[NC_MENSAJES];
    
}menu_datos;*/

/*
 * 
 */

/********DECLARACIONES Y DEFINICIONES DE PROTOTIPOS********/
void limpiar_buffer();
void pausa();
empresa_datos **reservar_memoria_empresas();
//void re_reserva_memoria_empresas(empresa_datos **empresas, int numero_bytes);
pabellon_datos **reservar_memoria_pabellones();
void liberar_memoria_empresas(empresa_datos **ptr_empresas, int n_empresas);
void liberar_memoria_pabellones(pabellon_datos **ptr_pabellones);

/**/
void ingresar_metros_pabellones(pabellon_datos **ptr_pabellones);
void ingresar_tarifas(pabellon_datos **ptr_pabellones);
void visualizar_tarifas(pabellon_datos **ptr_pabellones);
/**/
void menu(empresa_datos **empresas, pabellon_datos **pabellones, int *n_empresas);
int showmenu(char **mensajes, int opcion);
/**/
void ingresar_empresa(empresa_datos **ptr_empresas, pabellon_datos **ptr_pabellones, int *n_empresas);
void borrar_enter(empresa_datos *empresas);
int comprobrar_si_existe(char *nombre, empresa_datos **ptr_empresas, int n_empresas);
//float precio_de_alquiler(int dias, float metros_del_stand, float tarifa);
float actualizar_datos_pabellon(int numero_pabellon, float metros_del_stand, pabellon_datos **pabellones);
//void borrar_empresa(empresa_datos **ptr_empresas, int n_empresas);
void ordenar(empresa_datos **ptr_empresas, int n_empresas);
//void ordenar_empresas(empresa_datos **empresas, int n_empresas);
/**/
void borra_empresa_seleccionada(empresa_datos **ptr_empresas, int *n_empresas, pabellon_datos **ptr_pabellones);
void borrar_enter_nombre(char *nombre);
/**/
void modificar_tarifa(empresa_datos **ptr_empresas, int n_empresas, pabellon_datos **ptr_pabellones);
/**/
void visualizar_empresas(empresa_datos **ptr_empresas, int n_empresas);
void visualizar_pabellones(pabellon_datos **ptr_pabellones);
/**/
int main()
{
    /********DECLARACIONES********/
    empresa_datos **ptr_empresas=NULL;          //array de punteros para Stands
    pabellon_datos **ptr_pabellones=NULL;       //array de punteros para pabellones
    int n_empresas=0;                           //número de empresas, ordenar=0
    
    /********RESERVA MEMORIA********/
    ptr_empresas=reservar_memoria_empresas(); // reservar memoria para 50 empresas
    ptr_pabellones=reservar_memoria_pabellones(); // reservar memoria para 5 pabellones
    
    /********DATOS NECESARIOS PARA INICIO********/
    ingresar_metros_pabellones(ptr_pabellones);
    ingresar_tarifas(ptr_pabellones);
    visualizar_tarifas(ptr_pabellones);

    /********MENU********/
    menu(ptr_empresas, ptr_pabellones, &n_empresas);
    
    /********LIBERACIÓN MEMORIA********/
    liberar_memoria_empresas(ptr_empresas, n_empresas);
    liberar_memoria_pabellones(ptr_pabellones);

    printf("\n\nTODO OK\n\n");
    

    return (0);
}

void limpiar_buffer()
{
    fflush(stdout);
    fpurge(stdin);
}
void pausa()
{
    char caracter;
    
    printf("\nPulse una tecla para volver a Menu\n...");
    limpiar_buffer();
    scanf("%c", &caracter);
}

empresa_datos **reservar_memoria_empresas()
{
    empresa_datos **ptr_empresas;
    
    if((ptr_empresas=(empresa_datos **)malloc(NU_EMPRESAS*sizeof(empresa_datos *)))==NULL)
    {
        printf("\nNo hay memoria para tantas empresas.\n");
        exit (-1);
    }
    
    return ptr_empresas;
}
/*
void re_reserva_memoria_empresas(empresa_datos **empresas, int numero_bytes)
{
    if(*empresas != NULL)
    {
        if((*empresas=realloc(*empresas,numero_bytes*sizeof(empresa_datos)))==NULL)
        {
            printf("\nNo es posible añadir más empresas. No hay suficiente memoria.");
            //exit(-1;)
        }
    }
}
*/
pabellon_datos **reservar_memoria_pabellones()
{
    pabellon_datos **ptr_pabellones;
    
    if((ptr_pabellones=(pabellon_datos **)malloc(N_PABELLONES*sizeof(pabellon_datos *)))==NULL)
    {
        printf("\nNo hay memoria para tnatas empresas.\n");
        exit (-1);
    }
    
    return ptr_pabellones;
}

void liberar_memoria_empresas(empresa_datos **ptr_empresas, int n_empresas)
{
    int i;
    
    if(n_empresas!=0)
    {
        for(i=0;i<n_empresas;i++)
        {
            free(ptr_empresas[i]);
        }   
    }
    free(ptr_empresas);       
}

void liberar_memoria_pabellones(pabellon_datos **ptr_pabellones)
{
    int i;
    
    for(i=0;i<N_PABELLONES;i++)
    {
        free(ptr_pabellones[i]);
    }
    
    free(ptr_pabellones);
}

void ingresar_metros_pabellones(pabellon_datos **ptr_pabellones)
{
    int i; char justificado=' ';
    
    for(i=0;i<N_PABELLONES;i++)
    {
        ptr_pabellones[i]=(pabellon_datos *)malloc(N_PABELLONES*sizeof(pabellon_datos));
    }
    
    printf("\n%*c-----Insercción metros cuadrados de los pabellones-----\n", JUSTIFICADO, justificado);
    
    for(i=0;i<N_PABELLONES;i++)
    {
        printf("Pabellón %d. -> ", i+1);
        scanf("%f", &ptr_pabellones[i]->metros_totales);
    }
}

void ingresar_tarifas(pabellon_datos **ptr_pabellones)
{
    int i; char justificado=' ';
    
    printf("\n%*c-----Insercción de las tarifas de los pabellones-----\n", JUSTIFICADO, justificado);
    
    for(i=0;i<N_PABELLONES;i++)
    {
        printf("Pabellón %d. -> ", i+1);
        scanf("%f", &ptr_pabellones[i]->tarifa);
        ptr_pabellones[i]->metros_alquilados=0;
    }
}

void visualizar_tarifas(pabellon_datos **ptr_pabellones)
{
    int i; char justificado=' ';
    
    system("clear");
    
    printf("\n%*c-----TARIFAS DE LOS PABELLONES-----\n", JUSTIFICADO+10, justificado);
    
    for(i=0;i<N_PABELLONES-1;i++)
    {
        printf("Pabellón %d: %.2f€/m^2 --- ", i+1, ptr_pabellones[i]->tarifa);
    }
    printf("Pabellón %d: %.2f€/m^2\n", N_PABELLONES, ptr_pabellones[N_PABELLONES-1]->tarifa);
    
    printf("\n\n");
}

void menu(empresa_datos **ptr_empresas, pabellon_datos **ptr_pabellones, int *n_empresas)
{
    int opcion=0;
    char *mensajes[N_MENSAJES]={"Añadir un Stand",
                                "Eliminar un Stand",
                                "Modificar la tarifa de un pabellón",
                                "Visualizar la información de los Stands y los pabellones",
                                "Salir del programa"};
    /*menu_datos mensajes[N_MENSAJES]=
    {
        {"Añadir un Stand"},{"Eliminar un Stand"},{"Modificar la tarifa de un pabellón"},{"Visualizar la información de los Stands y los pabellones"},{"Salir del programa"}
    };*/
    
    while(opcion!=5)
    {
        opcion=showmenu(mensajes, opcion);
        
        switch(opcion)
        {
            case 1:
                ingresar_empresa(ptr_empresas, ptr_pabellones, n_empresas);
                break;
                
            case 2:
                if(*n_empresas>0)
                {
                    //borrar empresa (con liberar memoria)
                    borra_empresa_seleccionada(ptr_empresas, n_empresas, ptr_pabellones);
                }
                else
                {
                    printf("\nNo hay empresas registradas.\n");
                }
                break;
                
            case 3:
                modificar_tarifa(ptr_empresas, *n_empresas, ptr_pabellones);
                break;
                
            case 4:
                //
                if(*n_empresas>0)
                {
                    //ordenar_empresas(ptr_empresas, *n_empresas);
                    visualizar_empresas(ptr_empresas, *n_empresas);
                    visualizar_pabellones(ptr_pabellones);
                }
                else
                {
                    printf("\nNo hay empresas registradas.\n");
                }
                break;
                
            case 5:
                break;
        }
    }
}

int showmenu(char **mensajes, int opcion)
{
    int i;
    
    do
    {
        printf("\n-------------------------------------\n");
        printf("\nElija una de las siguientes opciones:\n\n");
    
        for(i=0;i<N_MENSAJES;i++)
        {
            printf("%d.-%s\n", i+1, mensajes[i]);
        }
        printf("\n");
        scanf("%d", &opcion);

        system("clear");
    }while(opcion<1 || opcion>5);
    
    return opcion;
}

void ingresar_empresa(empresa_datos **ptr_empresas, pabellon_datos **ptr_pabellones, int *n_empresas)
{
    float libre; //metros libres
    int existe;
    
    //incremento el número de empresas
    ++*n_empresas;
    
    //Reserva de estructura
    ptr_empresas[*n_empresas-1]=(empresa_datos *)malloc(sizeof(empresa_datos));

    printf("\nNúmero de empresas: %d\n", *n_empresas);

    printf("\n-------------------------------------\n");
    printf("\nRellene los campos:\n");
    
    printf("\nNombre de la empresa: ");
    limpiar_buffer();
    fgets(ptr_empresas[*n_empresas-1]->nombre_empresa,NO_EMPRESAS,stdin);
    
    borrar_enter(ptr_empresas[*n_empresas-1]);
    
    existe=comprobrar_si_existe(
            ptr_empresas[*n_empresas-1]->nombre_empresa,
            ptr_empresas, *n_empresas);
    
    if(existe>1)
    {
        printf("\nHay una empresa registrada con ese nombre.\n");
        
        //borro la empresa liberando la memoria:
        free(ptr_empresas[*n_empresas-1]);
        
        (*n_empresas)--;
    }
    else
    {
        printf("\nNúmero del pabellón:");
        limpiar_buffer();
        scanf("%d", &ptr_empresas[*n_empresas-1]->numero_pabellon);

        printf("\nNúmero días a alquilar:");
        limpiar_buffer();
        scanf("%d", &ptr_empresas[*n_empresas-1]->dias_de_alquiler);

        printf("\nMetros del Stand:");
        limpiar_buffer();
        scanf("%f", &ptr_empresas[*n_empresas-1]->metros_del_stand);

        //***********************
        libre=actualizar_datos_pabellon(
                ptr_empresas[*n_empresas-1]->numero_pabellon,
                ptr_empresas[*n_empresas-1]->metros_del_stand,
                ptr_pabellones);
        //***********************

        if(libre>=0)
        {
            //actualizo metros alquilados
            ptr_pabellones[ptr_empresas[*n_empresas-1]->numero_pabellon-1]->metros_alquilados=
                        ptr_pabellones[ptr_empresas[*n_empresas-1]->numero_pabellon-1]->metros_totales -
                        libre;        

            //alquiler=precio_de_alquiler(ptr_empresas[*n_empresas-1]->dias_de_alquiler, ptr_empresas[*n_empresas-1]->metros_del_stand, ptr_pabellones[ptr_empresas[*n_empresas-1]->numero_pabellon-1]->tarifa);
            //ptr_empresas[*n_empresas-1]->precio_alquiler=alquiler;
            
            //clacula elprecio del alquiler:
            ptr_empresas[*n_empresas-1]->precio_alquiler=
                    ptr_empresas[*n_empresas-1]->metros_del_stand *
                    ptr_empresas[*n_empresas-1]->dias_de_alquiler *
                    ptr_pabellones[ptr_empresas[*n_empresas-1]->numero_pabellon-1]->tarifa;
             
                    
            printf("\nEl precio del alquiler es: %.2f€\n",
                   ptr_empresas[*n_empresas-1]->precio_alquiler);
            
            //AQUI INSERTARIÍA LA EMPRESA EN SU POSICIÓN ORDENADA
            ordenar(ptr_empresas, *n_empresas);
        }
        else//arreglar funcion borrar_empresa
        {
            printf("\nNo hay metros suficientes disponibles en el pabellón %d\n", ptr_empresas[*n_empresas-1]->numero_pabellon);
            
            //borrar_empresa(ptr_empresas, *n_empresas);
            //borro la empresa liberando la memoria:
            free(ptr_empresas[*n_empresas-1]);
            
            printf("Se han borrado los datos introducidos.\n");
            (*n_empresas)--;
            //realloc
        }
    }
    
    //hacemos pausa antes de volver al menu
    pausa();
    
    system("clear");
}

void borrar_enter(empresa_datos *empresas)
{
    int longitud;
    
    longitud=strlen(empresas->nombre_empresa);
    
    if(empresas->nombre_empresa[longitud-1]=='\n')
    {
        empresas->nombre_empresa[longitud-1]='\0';
    }
}

int comprobrar_si_existe(char *nombre, empresa_datos **ptr_empresas, int n_empresas)
{
    int i, existe=0;
    
    for(i=0;i<n_empresas;i++)
    {
        if(strcmp(nombre, ptr_empresas[i]->nombre_empresa)==0)
        {
            existe++;
        }
    }
    
    return existe;
}

float actualizar_datos_pabellon(int numero_pabellon, float metros_del_stand, pabellon_datos **pabellones)
{
    float libre;
    
    //metros ya alquilados en ese pabellón - metros totales - metros del stand
    if(pabellones[numero_pabellon-1]->metros_alquilados==0)
    {
        libre=(pabellones[numero_pabellon-1]->metros_totales)-metros_del_stand;
    }
    else
    {
        libre=(pabellones[numero_pabellon-1]->metros_totales-pabellones[numero_pabellon-1]->metros_alquilados)-metros_del_stand;
    }
    //si hay metros libres, devolvemos el valor y lo asignamos
    return libre<0?-1:libre;
}

/*float precio_de_alquiler(int dias, float metros_del_stand, float tarifa)
{
    float alquiler;
    
    alquiler=(dias)*(metros_del_stand)*(tarifa);
    
    return alquiler;
}
*/
/*void borrar_empresa(empresa_datos **ptr_empresas, int n_empresas)
{
    free(ptr_empresas[n_empresas-1]); //libero la memoria de esa empresa
}
*/

/*
void ordenar_empresas(empresa_datos **empresas, int n_empresas)
{
    empresa_datos *paso;
    int i=0, s=1;
    
    while((s==1) && (--n_empresas>0))
    {
        s=0;
        
        for(i=1;i<=n_empresas;i++)
        {
            if(strcmp(empresas[i-1]->nombre_empresa, empresas[i]->nombre_empresa)>0)
            {
                paso = empresas[i-1];
                empresas[i-1] = empresas[i];
                empresas[i] = paso;
                s = 1;
            }
        }
    }
}
*/
void ordenar(empresa_datos **ptr_empresas, int n_empresas)
{
    int i, principio=0, final=n_empresas-1, mitad=(principio+final)/2, posicion;
    empresa_datos *paso=ptr_empresas[n_empresas-1];
    
    //busco posicion posible
    while(principio<final && strcmp(ptr_empresas[n_empresas-1]->nombre_empresa, ptr_empresas[mitad]->nombre_empresa)!=0)
    {
        if(strcmp(ptr_empresas[n_empresas-1]->nombre_empresa, ptr_empresas[mitad]->nombre_empresa)<0)
        {
            final=mitad-1;
        }
        else
        {
            principio=mitad+1;
        }
        mitad=(principio+final)/2;
    }
    
    //comparo donde entra
    if(strcmp(ptr_empresas[n_empresas-1]->nombre_empresa, ptr_empresas[mitad]->nombre_empresa)<0)
    {
        posicion=mitad;
    }
    else
    {
        posicion=mitad+1;
    }
    
    //desplazo punteros
    for(i=(n_empresas)-1;i>=posicion;i--)
    {
        ptr_empresas[i+1]=ptr_empresas[i];
    }
    
    ptr_empresas[posicion]=paso; //paso la estructura recogida a la posición del array correspondiente
}

void borra_empresa_seleccionada(empresa_datos **ptr_empresas, int *n_empresas, pabellon_datos **ptr_pabellones)
{
    int i, j, existe=0;
    char nombre[NO_EMPRESAS];
    
    printf("\nInserta el nombre de la empresa a borra:\n");
    limpiar_buffer();
    fgets(nombre, NO_EMPRESAS, stdin);
    borrar_enter_nombre(nombre);
    
    for(i=0;i<*n_empresas;i++)
    {
        if(strcmp(nombre, ptr_empresas[i]->nombre_empresa)==0)
        {
            //actualizo los metros alquilados:
            ptr_pabellones[ptr_empresas[i]->numero_pabellon-1]->metros_alquilados -=
                    ptr_empresas[i]->metros_del_stand;
            //borro empresa liberando la memoria:
            free(ptr_empresas[i]);
            //borrar_empresa(ptr_empresas, i+1); //libero la memoria de esa empresa
            existe++;
            
            if(i<*n_empresas-1)
            {
                for(j=i;i<*n_empresas;i++)
                {
                    ptr_empresas[i]=ptr_empresas[i+1];
                }
            }
        }
    }
    
    if(existe==0)
    {
        printf("\nNo existe empresa con dicho nombre.\n");
    }
    else
    {
        (*n_empresas)--;
    }
}

void borrar_enter_nombre(char *nombre)
{
    int longitud;
    
    longitud=strlen(nombre);
    
    if(nombre[longitud-1]=='\n')
    {
        nombre[longitud-1]='\0';
    }
}

void modificar_tarifa(empresa_datos **ptr_empresas, int n_empresas, pabellon_datos **ptr_pabellones)
{
    int  i, pabellon; float nueva_tarifa;
    
    system("clear");
    
    printf("\nInserta el número de pabellón y la nueva tarifa en €: (XX-YY.YY)\n");
    limpiar_buffer();
    scanf("%d-%f", &pabellon, &nueva_tarifa);
    
    ptr_pabellones[pabellon-1]->tarifa=nueva_tarifa;
    printf("\ntarifa del pabellón %d: %f\n", pabellon, ptr_pabellones[pabellon]->tarifa);
    
    for(i=0;i<n_empresas;i++)
    {
        if(ptr_empresas[i]->numero_pabellon==pabellon)
        {
            //ptr_empresas[i]->precio_alquiler=precio_de_alquiler(ptr_empresas[i]->dias_de_alquiler, ptr_empresas[i]->metros_del_stand, nueva_tarifa);
            ptr_empresas[i]->precio_alquiler=
                    ptr_empresas[i]->dias_de_alquiler *
                    ptr_empresas[i]->metros_del_stand *
                    nueva_tarifa;
        }
    }
}

void visualizar_empresas(empresa_datos **ptr_empresas, int n_empresas)
{
    int i;
    
    printf("\n");
    printf("\n%33s%18s%21s%25s%24s\n\n", "NOMBRE", "PABELLÓN", "DÍAS", "METROS", "PRECIO");
    
    for(i=0;i<n_empresas;i++)
    {
        printf("%20dª%11s%14d%23d%24.2fm^2%23.2f€\n", i+1, ptr_empresas[i]->nombre_empresa, ptr_empresas[i]->numero_pabellon, ptr_empresas[i]->dias_de_alquiler, ptr_empresas[i]->metros_del_stand, ptr_empresas[i]->precio_alquiler);
    }
}

void visualizar_pabellones(pabellon_datos **ptr_pabellones)
{
    int i;
    
    printf("\n");
    printf("\n%35s%15s%29s%22s%26s\n\n", "PABELLÓN", "PRECIO", "METROS DEL PABELLÓN", "METROS LIBRES", "METROS ALQUILADOS");
    
    for(i=0;i<N_PABELLONES;i++)
    {
        printf("%30d%18.2f€%20.2fm^2%22.2fm^2%21.2fm^2\n", i+1, ptr_pabellones[i]->tarifa, ptr_pabellones[i]->metros_totales, ptr_pabellones[i]->metros_totales-ptr_pabellones[i]->metros_alquilados, ptr_pabellones[i]->metros_alquilados);
    }    
    
    pausa();
    
    system("clear");
}