/* 
 * File:   10-1-Cenco.c
 * Author: Gartzia
 *
 * Created on 7 de diciembre de 2013, 2:14
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_NOMBRE 15
#define N_APELLIDOS 30
#define N_DIRECCION 50
#define NP_CENSO 100 //número de persons del censo
#define ANNO 2013

typedef struct
{
    char nombre[N_NOMBRE];
    char apellidos[N_APELLIDOS];
    unsigned int anio;
    char direccion[N_DIRECCION];
}datos;
/*
 * 
 */
/**/
void limpiar_buffer();
void pausa();
datos **reserva_memoria();
void fichero_recoger_censo();
void recoger_datos(datos **personas, int *n_personas);
void borrar_enter(char *nombre);
void liberar_memoria_personas(datos **personas, int n_personas);
void fichero_censo_60();
void porcentaje_60();
void visualizar_fichero_censo();
void visualizar_fichero_censo_60();
/**/
int main()
{
    fichero_recoger_censo();
    fichero_censo_60();
    porcentaje_60();
    visualizar_fichero_censo();
    visualizar_fichero_censo_60();
    
    printf("\nFIN PROGRAMA\n");
    
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
    int Ok=0;
    
    do
    {
        printf("Introduce <ENTER> para continuar\n...");
        limpiar_buffer();
        Ok=scanf("%c", &caracter);
    }while(!Ok || caracter!='\n');
    
    system("clear");
}

datos **reserva_memoria()
{
    datos **ptr_personas;
    
    if((ptr_personas=(datos **)malloc(NP_CENSO*sizeof(datos *)))==NULL)
    {
        printf("\nInsuficiente memoria para %d personas\n", NP_CENSO);
        exit (-1);
    }
    
    return ptr_personas;
}

void fichero_recoger_censo()
{
    FILE *ptr_fichero;
    datos **personas;
    int n_personas=0;
    char opcion;
    
    personas=reserva_memoria();
    
    if((ptr_fichero=fopen("CENSO.dat","ab+"))==NULL)
    {
        printf("\nError al abrir/crear el archivo CENSO.\n");
        exit (2);
    }
    else
    {
        do
        {
            recoger_datos(personas, &n_personas);
            fwrite(personas[n_personas-1], sizeof(datos), 1, ptr_fichero);
            //fwrite(personas[n_personas-1]->nombre, 1, N_NOMBRE, ptr_fichero);
            //fwrite(personas[n_personas-1]->apellidos, 1, N_APELLIDOS, ptr_fichero);
            //fwrite(&personas[n_personas-1]->anio, 1, sizeof(int), ptr_fichero);
            //fwrite(personas[n_personas-1]->direccion, 1, N_DIRECCION, ptr_fichero);
            
            do
            {
            printf("\n¿Introducir más datos? (S/N)\n");
            limpiar_buffer();
            scanf("%c", &opcion);
            }while(opcion!='S' && opcion!='N');
            
            system("clear");
            
        }while(opcion=='S');
        
        printf("\nSe cierra el fichero.\n");
        fclose(ptr_fichero);
        
        liberar_memoria_personas(personas, n_personas);
        
        pausa();
    }    
}

void recoger_datos(datos **personas, int *n_personas)
{
    (*n_personas)++;
    //reserva de memoria:
    personas[*n_personas-1]=(datos *)malloc(sizeof(datos));
    
    printf("\nIntroduzca los datos:\n");
    printf("\nNombre:  ");
    limpiar_buffer();
    fgets(personas[*n_personas-1]->nombre, N_NOMBRE, stdin);
    borrar_enter(personas[*n_personas-1]->nombre);
    
    printf("\nApellidos:  ");
    limpiar_buffer();
    fgets(personas[*n_personas-1]->apellidos, N_APELLIDOS, stdin);
    borrar_enter(personas[*n_personas-1]->apellidos);
    
    printf("\nAño de nacimiento:  ");
    limpiar_buffer();
    scanf("%u", &personas[*n_personas-1]->anio);
    
    printf("\nDirección:  ");
    limpiar_buffer();
    fgets(personas[*n_personas-1]->direccion, N_DIRECCION, stdin);
    borrar_enter(personas[*n_personas-1]->direccion);
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

void liberar_memoria_personas(datos **personas, int n_personas)
{
    int i;
    
    for(i=0;i<n_personas;i++)
    {
        free(personas[i]);
    }
    free(personas);
}

void fichero_censo_60()
{
    FILE *ptr_fichero;
    FILE *ptr_fichero2;
    //datos personas;
    datos **personas;
    int n_personas=1;
    
    personas=reserva_memoria();
    personas[n_personas-1]=(datos *)malloc(sizeof(datos));

    if((ptr_fichero=fopen("CENSO.dat","rb"))==NULL)
    {
        printf("\nError al abrir/crear el archivo CENSO para CENSO_60.\n");
        exit (2);
    }
    else
    {
        if((ptr_fichero2=fopen("CENSO_60.dat","ab+"))==NULL)
        {
            printf("\nError al abrir/crear el archivo CENSO_60.\n");
            exit (2);
        }
        else
        {
            /*while
             (fread(personas.nombre, 1, N_NOMBRE, ptr_fichero) &&
              fread(personas.apellidos, 1, N_APELLIDOS, ptr_fichero) &&
              fread(&personas.anio, sizeof(int), 1, ptr_fichero) &&
              fread(personas.direccion, 1, N_DIRECCION, ptr_fichero))*/
            while(fread(personas[n_personas-1], sizeof(datos), 1, ptr_fichero))
            {
                if(ANNO-personas[n_personas-1]->anio>=60)
                {
                    fwrite(personas[n_personas-1], sizeof(datos), 1, ptr_fichero2);
                    //fwrite(personas.nombre, 1, N_NOMBRE, ptr_fichero2);
                    //fwrite(personas.apellidos, 1, N_APELLIDOS, ptr_fichero2);
                    //fwrite(&personas.anio, sizeof(int), 1, ptr_fichero2);
                    //fwrite(personas.direccion, 1, N_DIRECCION, ptr_fichero2);
                }
                n_personas++;
                personas[n_personas-1]=(datos *)malloc(sizeof(datos));

            }
            fclose(ptr_fichero);
            fclose(ptr_fichero2);
        }
    }
    liberar_memoria_personas(personas, n_personas+1);
}

void porcentaje_60()
{
    FILE *ptr_fichero;
    FILE *ptr_fichero2;
    long porcentaje;
    
    if((ptr_fichero=fopen("CENSO.dat", "rb"))==NULL)
    {
        printf("\nError al abrir/leer el archivo CENSO  para porcentaje.\n");
        exit (2);
    }
    else
    {
        if((ptr_fichero2=fopen("CENSO_60.dat", "rb"))==NULL)
        {
            printf("\nError al abrir/leer el archivo CENSO_60 para porcentaje.\n");
            exit (2);
        }
        else
        {
            fseek(ptr_fichero, 0L, SEEK_END);
            fseek(ptr_fichero2, 0L, SEEK_END);

            porcentaje=100 * ftell(ptr_fichero2) / ftell(ptr_fichero);

            printf("\nEl %ld%% del censo tiene más de 60 años.\n", porcentaje);

            fclose(ptr_fichero);
            fclose(ptr_fichero2);
        }
    }
}

//La diferencia entre 'visualizar_fichero_censo' & ''visualizar_fichero_censo_60
//es que en la 1ª, uso la estructura 'datos persona' que guarda las estructuras
//del Stream; pero en la 2ª, guardo los datos en el array de punteros a estructuras
//'datos **personas', así si cierro el fichero, quedará una copia de los datos en
//memoria que pueda manioular con mi programa.
void visualizar_fichero_censo()
{
    FILE *ptr_fichero;
    datos personas;
    
    if((ptr_fichero=fopen("CENSO.dat", "rb"))==NULL)
    {
        printf("\nError al abrir/leer el archivo CENSO para visualizar.\n");
        exit (2);
    }
    else
    {
        printf("\n\n%45s\n________________________________________________________________________"
                "\n\n%15s%20s%18s%20s\n\n", "CENSO", "NOMBRE", "APELLIDOS", "AÑO", "DIRECCIÓN");
        
      /* while(
        (fread(personas.nombre, 1, N_NOMBRE, ptr_fichero)) &&
        (fread(personas.apellidos, 1, N_APELLIDOS, ptr_fichero)) &&
        (fread(&personas.anio, 1, sizeof(int), ptr_fichero)) &&
        (fread(personas.direccion, 1, N_DIRECCION, ptr_fichero)))
        {
            printf("%14s%20s%19u%20s\n", personas.nombre, personas.apellidos, personas.anio, personas.direccion);
        }*/
        
        while(fread(&personas, sizeof(datos), 1, ptr_fichero))
        {
            printf("%14s%20s%18u%19s\n",
                    personas.nombre,
                    personas.apellidos,
                    personas.anio,
                    personas.direccion);
        }
      
        printf("\n\n");
        fclose(ptr_fichero);
    }
    
    printf("........................................................................");
}

void visualizar_fichero_censo_60()
{
    FILE *ptr_fichero2;
    datos paso;
    datos **personas;
    int n_personas=1;
    
    personas=reserva_memoria();
    personas[n_personas-1]=(datos *)malloc(sizeof(datos));
    
    if((ptr_fichero2=fopen("CENSO_60.dat", "rb"))==NULL)
    {
        printf("\nError al abrir/eer el archivo CENSO_60 para visualizar.\n");
        exit (2);
    }
    else
    {
        printf("\n\n%45s\n________________________________________________________________________"
                "\n\n%15s%20s%18s%20s\n\n", "CENSO 60", "NOMBRE", "APELLIDOS", "AÑO", "DIRECCIÓN");
        
        while(fread(&paso, sizeof(datos), 1, ptr_fichero2))
        {
            strcpy(personas[n_personas-1]->nombre,paso.nombre);
            strcpy(personas[n_personas-1]->apellidos,paso.apellidos);
            personas[n_personas-1]->anio=paso.anio;
            strcpy(personas[n_personas-1]->direccion,paso.direccion);
            
            printf("%14s%20s%18u%19s\n",
                    personas[n_personas-1]->nombre,
                    personas[n_personas-1]->apellidos,
                    personas[n_personas-1]->anio,
                    personas[n_personas-1]->direccion);
        }
        printf("\n\n");
        fclose(ptr_fichero2);
    }
    
    liberar_memoria_personas(personas, n_personas);
        
    pausa();
}