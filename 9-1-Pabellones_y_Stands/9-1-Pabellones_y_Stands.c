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
#define JUSTIFICADO 5 //justificado de ancho en los títulos
#define JUSTIFICADO2 20
#define DIAS_FERIA 5 //dias que está abierta la feria
#define DIA_INICIO 9
#define DIA_FIN 14
#define MES "Septiembre"
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

/*
 * 
 */

/********DECLARACIONES Y DEFINICIONES DE PROTOTIPOS********/

void limpiar_buffer();
void pausa(int tipo);
/*MEMORIA*/
empresa_datos **reservar_memoria_empresas();
pabellon_datos **reservar_memoria_pabellones();
void liberar_memoria_empresas(empresa_datos **ptr_empresas, int n_empresas);
void liberar_memoria_pabellones(pabellon_datos **ptr_pabellones);
/*DATOS DEL SISTEMA*/
void ingresar_metros_pabellones(pabellon_datos **ptr_pabellones);
void ingresar_tarifas(pabellon_datos **ptr_pabellones);
void visualizar_tarifas(pabellon_datos **ptr_pabellones);
/*MENU*/
void menu(empresa_datos **empresas, pabellon_datos **pabellones, int *n_empresas);
int showmenu(char **mensajes, int opcion);
/*menu-1: Ingersar cliente*/
void recoger_datos(empresa_datos **ptr_empresas, pabellon_datos **ptr_pabellones, int *n_empresas);
void validez_del_dato(empresa_datos **ptr_empresas, int n_empresas, int contador, int tipo, int *array_pab_libres);
void validez_del_dato2(empresa_datos **ptr_empresas, int n_empresas, pabellon_datos **ptr_pabellones, float *libre, char *cambiar, int *pab_libres, int *array_pab_libres);
float validez_metros_stand(empresa_datos **ptr_empresas, int n_empresas, pabellon_datos **ptr_pabellones);
void cambiar_pabellon(empresa_datos **ptr_empresas, int n_empresas, pabellon_datos **ptr_pabellones, int *array_pab_libres);
void borrar_enter(empresa_datos *empresas);
void convertir_a_mayusculas(empresa_datos **ptr_empresas, int n_empresas);
int comprobrar_si_existe(char *nombre, empresa_datos **ptr_empresas, int n_empresas);
void aniadir_stand(empresa_datos **ptr_empresas, int n_empresas, pabellon_datos **ptr_pabellones, float libre);
float actualizar_datos_pabellon(int numero_pabellon, float metros_del_stand, pabellon_datos **pabellones);
void ordenar(empresa_datos **ptr_empresas, int n_empresas);
int busqueda_binaria(char *nombre, empresa_datos **ptr_empresas, int n_empresas);
/*menu-2: Borrar cliente*/
void borra_empresa_seleccionada(empresa_datos **ptr_empresas, int *n_empresas, pabellon_datos **ptr_pabellones);
/*menu-3: Moficar tarifas*/
void modificar_tarifa(empresa_datos **ptr_empresas, int n_empresas, pabellon_datos **ptr_pabellones);
/*menu-4: Mostrar datos*/
void visualizar_empresas(empresa_datos **ptr_empresas, int n_empresas);
void visualizar_pabellones(pabellon_datos **ptr_pabellones);

/**********************************************************/

int main()
{
    /********DECLARACIONES********/
    empresa_datos **ptr_empresas=NULL;          //puntero a array de punteros para Stands
    pabellon_datos **ptr_pabellones=NULL;       //puntero a array de punteros para pabellones
    int n_empresas=0;                           //número de empresas registradas
    
    /********RESERVA MEMORIA********/
    ptr_empresas=reservar_memoria_empresas();     // reservar memoria para 50 empresas
    ptr_pabellones=reservar_memoria_pabellones(); // reservar memoria para 5 pabellones
    
    /********DATOS DEL SISTEMA********/
    ingresar_metros_pabellones(ptr_pabellones);
    ingresar_tarifas(ptr_pabellones);
    visualizar_tarifas(ptr_pabellones);

    /********MENU********/
    menu(ptr_empresas, ptr_pabellones, &n_empresas);
    
    /********LIBERACIÓN MEMORIA********/
    liberar_memoria_empresas(ptr_empresas, n_empresas);
    liberar_memoria_pabellones(ptr_pabellones);

    printf("FIN DE PROGRAMA\n\n");   

    return (0);
}
//Limpia buffer de salida y de entrada
void limpiar_buffer()
{
    fflush(stdout);
    fpurge(stdin);
}

//Espera a recoger un caracter para realizar una pausa antes de limpiar pantalla
void pausa(int tipo)
{
    char caracter;
    if(!tipo)
    {
        printf("\nPulse una tecla para continuar\n...");
    }
    else
    {
        printf("\nPulse una tecla para volver a Menu\n...");
    }
    limpiar_buffer();
    scanf("%c", &caracter);
    
    system("clear");
}

//Reserva memoria para '50' empresas - puntero a array de punteros
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

//Reserva memoria para '5' pabellones . puntero a array de punteros
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

//Libera la memoria de las empresas registradas
void liberar_memoria_empresas(empresa_datos **ptr_empresas, int n_empresas)
{
    int i;
    
    //si no hay empresas registradas, los punteros no sabemos a donde apuntan
    if(n_empresas!=0)
    {
        for(i=0;i<n_empresas;i++)
        {
            free(ptr_empresas[i]);
        }   
    }
    //así que liberamos sólo el puntero de empresas
    free(ptr_empresas);       
}

//Libera la memoria de los pabellones registradas
void liberar_memoria_pabellones(pabellon_datos **ptr_pabellones)
{
    int i;
    
    //si no hay pabellones registradas, los punteros no sabemos a donde apuntan
    for(i=0;i<N_PABELLONES;i++)
    {
        free(ptr_pabellones[i]);
    }
    //así que liberamos sólo el puntero de pabellones
    free(ptr_pabellones);
}

//Recoge el valor máximo de metros cuadrados por pabellón
void ingresar_metros_pabellones(pabellon_datos **ptr_pabellones)
{
    int i; char justificado=' ';
    
    system("clear");
    
    printf("\n%*cInserta los metros cuadrados de los pabellones:\n\n", JUSTIFICADO, justificado);
    
    for(i=0;i<N_PABELLONES;i++)
    {
        //reservamos la memoria de cada pabellón a la vez que recogemos el dato
        ptr_pabellones[i]=(pabellon_datos *)malloc(N_PABELLONES*sizeof(pabellon_datos));
        printf("%*cPabellón %d. -> ", JUSTIFICADO2,justificado, i+1);
        scanf("%f", &ptr_pabellones[i]->metros_totales);
    }
}

//Recoge el valor de tarifa por cada pabellón
void ingresar_tarifas(pabellon_datos **ptr_pabellones)
{
    int i; char justificado=' ';
    
    printf("\n%*cInserta las tarifas de los pabellones\n\n", JUSTIFICADO+5, justificado);
    
    for(i=0;i<N_PABELLONES;i++)
    {
        printf("%*cPabellón %d. -> ", JUSTIFICADO2,justificado, i+1);
        scanf("%f", &ptr_pabellones[i]->tarifa);
        //también inicializamos a cero el número de metros alquilados por pabellón
        ptr_pabellones[i]->metros_alquilados=0;
    }
}

//muestra los datos introducidos
void visualizar_tarifas(pabellon_datos **ptr_pabellones)
{
    int i; char justificado=' ';
    
    pausa(0);
    
    printf("\n%*cTARIFAS DE LOS PABELLONES\n\n", JUSTIFICADO+11, justificado);
    
    printf("%*c%10s%15s%16s\n", 
            JUSTIFICADO+3, justificado, 
            "PABELLÓN", "TARIFA", "METORS^2");
    
    for(i=0;i<N_PABELLONES;i++)
    {
        printf("%*c%6d%15.2f€/m^2%13.2f\n", 
                JUSTIFICADO+3,justificado, 
                i+1, ptr_pabellones[i]->tarifa, 
                ptr_pabellones[i]->metros_totales);
    }
    
    printf("\n\n");
    
    pausa(1);
}

//MENU
void menu(empresa_datos **ptr_empresas, pabellon_datos **ptr_pabellones, int *n_empresas)
{
    int opcion=0;
    //array de cadenas para mostrar las opciones del menu
    char *mensajes[N_MENSAJES]={"Añadir un Stand",
                                "Eliminar un Stand",
                                "Modificar la tarifa de un pabellón",
                                "Visualizar la información de los Stands y los pabellones",
                                "Salir del programa"};
    
    while(opcion!=5)
    {
        opcion=showmenu(mensajes, opcion);
        
        switch(opcion)
        {
            case 1:
                //recoge los datos de la empresa
                recoger_datos(ptr_empresas, ptr_pabellones, n_empresas);
                break;
                
            case 2:
                //borra la empresa liberando la memoria, si es que hay
                borra_empresa_seleccionada(ptr_empresas, n_empresas, ptr_pabellones);
                break;
                
            case 3:
                //modifica la tarifa del pabellón deseado y visualiza todos después
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
        }
    }
}

//Muestra las opciones del menu
int showmenu(char **mensajes, int opcion)
{
    int i; char justificado=' ';
    
    do
    {
        printf("\n------------------------------------------------\n");
        printf("\n%*cElija una de las siguientes opciones:\n\n", JUSTIFICADO+5, justificado);
    
        for(i=0;i<N_MENSAJES;i++)
        {
            printf("%*c%d.-%s\n", JUSTIFICADO+5, justificado, i+1, mensajes[i]);
        }
        printf("\n");
        scanf("%d", &opcion);

        system("clear");
    }while(opcion<1 || opcion>5);
    
    return opcion;
}

//Recoge los datos de empresa y lllama a la función que añade el Stand si son correctos
void recoger_datos(empresa_datos **ptr_empresas, pabellon_datos **ptr_pabellones, int *n_empresas)
{
    int existe,/*si la empresa ya está registrada o no*/
        pab_libres=4,/*usada para contabilizar los pabellones disponibles*/
        array_pab_libres[N_PABELLONES]={0};  /*array para contabilizar los pabellones que no hay que mostrar*/
    float libre; //metros libres
    char cambiar; //camniar de pabellón
    
    //Incrementa el número de empresas
    ++*n_empresas;
    
    //Reserva la memoria necesaria para la estructura que contendrá los datos del Stand
    ptr_empresas[*n_empresas-1]=(empresa_datos *)malloc(sizeof(empresa_datos));

    printf("\nNúmero de empresas: %d\n", *n_empresas);
    printf("\n-------------------------------------\n");
    printf("\nRellene los campos:\n");
    
    //Se solicitan los datos: Nombre, Días de alquiler, NºPabellón y m^2 del Stand
    printf("\nNombre de la empresa: ");
    limpiar_buffer();
    fgets(ptr_empresas[*n_empresas-1]->nombre_empresa,NO_EMPRESAS,stdin);
    
    borrar_enter(ptr_empresas[*n_empresas-1]);
    
    //convierte los nombres de los Stands a mayúsculas
    convertir_a_mayusculas(ptr_empresas, *n_empresas);
    
    existe=comprobrar_si_existe(
            ptr_empresas[*n_empresas-1]->nombre_empresa,
            ptr_empresas, *n_empresas);
    
    if(existe>1)
    {
        printf("\nHay una empresa registrada con ese nombre.\n");
        
        //borra la empresa liberando la memoria:
        free(ptr_empresas[*n_empresas-1]);
        
        (*n_empresas)--;
    }
    else
    {
        //número de pabellón 0:Contador - 0:Recoge NºPabellón
        validez_del_dato(ptr_empresas, *n_empresas, 0, 0, array_pab_libres);
        //días de alquiler   0:Contador - 1:Recoge días de laquiler
        validez_del_dato(ptr_empresas, *n_empresas, 0, 1, array_pab_libres);
        //metros necesarios para el Stand
        validez_del_dato2(ptr_empresas, *n_empresas, ptr_pabellones, &libre, &cambiar, &pab_libres, array_pab_libres);
        
        if(cambiar=='N' || pab_libres<1)
        {
            //borra la empresa liberando la memoria:
            free(ptr_empresas[*n_empresas-1]);

            printf("\nSe han borrado los datos introducidos.\n");
            (*n_empresas)--;
        }
        else
        {
            //si todo está correcto, añade el Stand al array de punteros
            aniadir_stand(ptr_empresas, *n_empresas, ptr_pabellones, libre);
        }
    }
    
    //hacemos pausa antes de volver al menu
    pausa(1);
}

//Recoge el NºPabellón (Tipo=0) o Días de alquiler(Tipo=1)
void validez_del_dato(empresa_datos **ptr_empresas, int n_empresas, int contador, int tipo, int *array_pab_libres)
{
    int i, var, Ok=0, pab_disponibles=0;
    
     do
        {
            if(contador==1)
            {
                //Tipo=0 -> muestra corrección para NºPabellones
                //Tipo=1 -> muestra corrección para Días de alquiler
                if(!tipo)
                {
                    //permite en Printf mostrar el número de Pabellobes disponibles en cada intento
                    for(i=0;i<N_PABELLONES;i++)
                    {
                        if(array_pab_libres[i]==0)
                        {
                            pab_disponibles++;
                        }
                    }
                    printf("\nSólo dispones de %d pabellones."
                            "\nIntroduce un número correcto.", pab_disponibles);
                    pab_disponibles=0;
                }
                else
                {
                    printf("\nSólo se pude al aquilar entre el %d y el %d de %s"
                        "\nIntroduce uno de los %d días.", DIA_INICIO, DIA_FIN, MES, DIAS_FERIA);
                }
            }
            
            Ok=0;
            contador=0; //vijila que el número introducido está dentro del rango permitido
            printf("\nNúmero %s", !tipo?"del pabellón:":"de días a alquilar:");
            limpiar_buffer();
            Ok=scanf("%d", &var);
            contador++;
        }while(!Ok || var>(!tipo?N_PABELLONES:DIAS_FERIA) || var<1 || array_pab_libres[var-1]!=0);
        
        //Tipo=0 -> guarda la variavble en numero_pabellon
        //Tipo=1 -> guarda la variavble en dias_de_alquiler
        if(!tipo)
        {
            ptr_empresas[n_empresas-1]->numero_pabellon=var;
        }
        else
        {
            ptr_empresas[n_empresas-1]->dias_de_alquiler=var;
        }
}

//Recoge el número de m^2 del Stand
void validez_del_dato2(empresa_datos **ptr_empresas, int n_empresas, pabellon_datos **ptr_pabellones, float *libre, char *cambiar, int *pab_libres, int *array_pab_libres)
{
    do
        {
            //recoge los m^2 y comprueba los metros disponibles en el pabellón correspondiente
            *libre=validez_metros_stand(ptr_empresas, n_empresas, ptr_pabellones);
            
            if(*libre>=0 || *pab_libres<1)
            {
                break; //si ya no hay m^2 o pabellones disponibles, sale (y se borrarán todos los datos del Stand)
            }
            printf("\nNo hay metros suficientes disponibles en el pabellón %d\n",
                    ptr_empresas[n_empresas-1]->numero_pabellon);
            
            printf("¿Quieres cambiar de pabellón?  (S/N)");
            limpiar_buffer();
            scanf("%c", cambiar);
            
            if(*cambiar=='S')
            {
                //recoge el nuevo NºPabellón y muestra los pabellones con sus metros disponibles
                cambiar_pabellon(ptr_empresas, n_empresas, ptr_pabellones, array_pab_libres);
                (*pab_libres)--;
            }
            else
            {
                //para cambiar unicamente los m^2 sin moverse de pabellón
                printf("¿Quieres cambiar los m^2?  (S/N)");
                limpiar_buffer();
                scanf("%c", cambiar);
                
                if(*cambiar=='N')
                {
                    break;
                }
            }
            
        }while(*libre<0 || *pab_libres>0 || *cambiar=='S');
}

//Recoge los m^2 y comprueba los m^2 libres en el pabellón correspondiente
float validez_metros_stand(empresa_datos **ptr_empresas, int n_empresas, pabellon_datos **ptr_pabellones)
{
    float libre;
    //metros a alquilar
    printf("\nMetros del Stand:");
    limpiar_buffer();
    scanf("%f", &ptr_empresas[n_empresas-1]->metros_del_stand);

    libre=actualizar_datos_pabellon(
            ptr_empresas[n_empresas-1]->numero_pabellon,
            ptr_empresas[n_empresas-1]->metros_del_stand,
            ptr_pabellones);
        
        return libre;
}

//cambia el NºPabellón y muestra los m^2 libres de los pabellones disponibles
void cambiar_pabellon(empresa_datos **ptr_empresas, int n_empresas, pabellon_datos **ptr_pabellones, int *array_pab_libres)
{
    int i; char justificado=' ';
    
    //añade el pabellón al array de pabellones libres (+1 -> así no estará disponible)
    array_pab_libres[ptr_empresas[n_empresas-1]->numero_pabellon-1]++;
    
    printf("\n\n%*c%10s%25s\n", JUSTIFICADO, justificado, "PABELON", "METROS LIBRES");
    
    for(i=0;i<N_PABELLONES;i++)
    {
        if(array_pab_libres[i]==0)
        {
            printf("%*c%7d%24.2f\n", JUSTIFICADO, justificado, i+1, ptr_pabellones[i]->metros_totales - ptr_pabellones[i]->metros_alquilados);
        }
    }
    
    validez_del_dato(ptr_empresas, n_empresas, 0, 0, array_pab_libres); //número de pabellón
}

//borra el '\n' de la cadena de caracteres recogida con fgets()
void borrar_enter(empresa_datos *empresas)
{
    int longitud;
    
    longitud=strlen(empresas->nombre_empresa);
    
    if(empresas->nombre_empresa[longitud-1]=='\n')
    {
        empresas->nombre_empresa[longitud-1]='\0';
    }
}

//convierte los nombres de los Stands a mayúsculas
void convertir_a_mayusculas(empresa_datos **ptr_empresas, int n_empresas)
{
    int i, longitud;
    
    longitud=strlen(ptr_empresas[n_empresas-1]->nombre_empresa);
    
    for(i=0;i<longitud;i++)
    {
        if(ptr_empresas[n_empresas-1]->nombre_empresa[i]>='a' && ptr_empresas[n_empresas-1]->nombre_empresa[i]<='z')
        {
            ptr_empresas[n_empresas-1]->nombre_empresa[i]-=32;
        }
    }
}

//se busca usando el método secuencial la existencia de la empresa introducida en el array de punteros de los Stnads
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

//Actualiza los metros libres del Pabellón correspondiente y
//Llama a la dunción que añade el Stand al array de punteros de los Stands
void aniadir_stand(empresa_datos **ptr_empresas, int n_empresas, pabellon_datos **ptr_pabellones, float libre)
{
    //actualizo metros alquilados
    ptr_pabellones[ptr_empresas[n_empresas-1]->numero_pabellon-1]->metros_alquilados=
                ptr_pabellones[ptr_empresas[n_empresas-1]->numero_pabellon-1]->metros_totales -
                libre;        
            
    //calcula el precio del alquiler:
    ptr_empresas[n_empresas-1]->precio_alquiler=
            ptr_empresas[n_empresas-1]->metros_del_stand *
            ptr_empresas[n_empresas-1]->dias_de_alquiler *
            ptr_pabellones[ptr_empresas[n_empresas-1]->numero_pabellon-1]->tarifa;
             
                    
    printf("\nEl precio del alquiler es: %.2f€\n",
           ptr_empresas[n_empresas-1]->precio_alquiler);

    //ordena el Stand en el array de punteros
    ordenar(ptr_empresas, n_empresas);
}

//Comprueba si hay espacio libre en el NºPabellon correspondiente
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

/* //PARA ORDENAR CON EL MÉTODO DE BÚSQUEDA SECUENCIAL
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

//Introduce el Stand en su posición correcta siguiendo el orden alfabético
//Usando el método de búsqueda binariia
void ordenar(empresa_datos **ptr_empresas, int n_empresas)
{
    int i, posicion, mitad;
    empresa_datos *paso=ptr_empresas[n_empresas-1];
    
    mitad=busqueda_binaria(ptr_empresas[n_empresas-1]->nombre_empresa, ptr_empresas, n_empresas);
    
    //compara donde está la posición del puntero
    if(strcmp(ptr_empresas[n_empresas-1]->nombre_empresa, ptr_empresas[mitad]->nombre_empresa)<0)
    {
        posicion=mitad;
    }
    else
    {
        posicion=mitad+1;
    }
    
    //desplaza punteros
    for(i=(n_empresas)-1;i>=posicion;i--)
    {
        ptr_empresas[i+1]=ptr_empresas[i];
    }
    
    //pasa la estructura recogida a la posición del array correspondiente
    ptr_empresas[posicion]=paso; 
}

//Método de búsqueda binaria
int busqueda_binaria(char *nombre, empresa_datos **ptr_empresas, int n_empresas)
{
    int principio=0, final=n_empresas-1, mitad=(principio+final)/2;
    
    //busco posicion posible
    while(principio<final && strcmp(nombre, ptr_empresas[mitad]->nombre_empresa)!=0)
    {
        if(strcmp(nombre, ptr_empresas[mitad]->nombre_empresa)<0)
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

//Borra la empresa deseada usando el método de búsqueda binaria
void borra_empresa_seleccionada(empresa_datos **ptr_empresas, int *n_empresas, pabellon_datos **ptr_pabellones)
{
    int j, mitad;
    //char nombre[NO_EMPRESAS];
    
    if(*n_empresas)//si no hay empresas, lo visualiza por pantalla en el ELSE
    {
        //*n_empresas+1: hay que incrementar el número de empresas para acceder
        //en vez de ello, no resto: *n_empresas-1 en ptr_empresas, etc.
        
        //Reserva la memoria necesaria para la estructura que contendrá los datos del Stand
        ptr_empresas[*n_empresas]=(empresa_datos *)malloc(sizeof(empresa_datos));
    
        printf("\nInserta el nombre de la empresa a borra:\n");
        limpiar_buffer();
        fgets(ptr_empresas[*n_empresas]->nombre_empresa, NO_EMPRESAS, stdin);
        borrar_enter(ptr_empresas[*n_empresas]);

        //convierte los nombres de los Stands a mayúsculas
        convertir_a_mayusculas(ptr_empresas, *n_empresas+1);
    
        mitad=busqueda_binaria(ptr_empresas[*n_empresas]->nombre_empresa, ptr_empresas, *n_empresas);

        if(strcmp(ptr_empresas[*n_empresas]->nombre_empresa, ptr_empresas[mitad]->nombre_empresa)==0)
        {
            //actualiza los metros alquilados:
            ptr_pabellones[ptr_empresas[mitad]->numero_pabellon-1]->metros_alquilados -=
                    ptr_empresas[mitad]->metros_del_stand;
            
            //borro empresa liberando la memoria y el reservado para la búsqueda:
            free(ptr_empresas[*n_empresas]->nombre_empresa);
            free(ptr_empresas[mitad]);

            //desplaza punteros
            if(mitad<*n_empresas-1)
            {
                for(j=mitad;mitad<*n_empresas;mitad++)
                {
                    ptr_empresas[mitad]=ptr_empresas[mitad+1];
                }
            }
            (*n_empresas)--;
        }    
        else
        {
            printf("\nNo existe empresa con dicho nombre.\n");
        }
    }
    else
    {
        printf("\nNo hay empresas registradas.\n");
    }
}

//Modifica la tarifa deseada del NºPabellón correspondiente y
//Llama a la función 'visualizar_pabellones'
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
    
    visualizar_pabellones(ptr_pabellones);
}

//Visualiza la información de los Stands registrados
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

//Visualiza la información de los pabellones
void visualizar_pabellones(pabellon_datos **ptr_pabellones)
{
    int i;
    
    printf("\n");
    printf("\n%35s%15s%29s%22s%26s\n\n", "PABELLÓN", "PRECIO", "METROS DEL PABELLÓN", "METROS LIBRES", "METROS ALQUILADOS");
    
    for(i=0;i<N_PABELLONES;i++)
    {
        printf("%30d%18.2f€%20.2fm^2%22.2fm^2%21.2fm^2\n", i+1, ptr_pabellones[i]->tarifa, ptr_pabellones[i]->metros_totales, ptr_pabellones[i]->metros_totales-ptr_pabellones[i]->metros_alquilados, ptr_pabellones[i]->metros_alquilados);
    }    
    
    pausa(1);
    
    system("clear");
}
