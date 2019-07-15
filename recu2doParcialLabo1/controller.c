#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "soporte.h"
#include "controller.h"
#include "utn.h"
//#include "informes.h"


void menu(LinkedList* listaSoporte)
{
    int optionMenu;
    int codigoProblema;

    do
    {

        system("clear");
        __fpurge(stdin);

        printf("-------------------------------------------------------------------------------\n\n");
        printf("1.- Cargar Archivo.\n");
        printf("2.- Imprimir Llamadas.\n");
        printf("3.- Generar Archivo de Llamadas.\n");
        printf("4.- Salir\n\n");
        printf("------------------------------------------------------------------------------\n");
        optionMenu = getValidInt("Ingrese opcion: ", "Error de ingreso, reintente.\n");

        switch(optionMenu)
        {
        case 1:
            controller_loadFromText("DATA_final1.csv", listaSoporte);
            __fpurge(stdin);
            pause();
            break;

        case 2:
            controller_ListEmployee(listaSoporte);
            __fpurge(stdin);
            pause();
            break;

        case 3:
            printf("Ingrese codigo de problema para filtrar: \n");
            scanf(&codigoProblema);
            ll_filter(this);
            __fpurge(stdin);
            pause();
            break;

        case 4:

            break;

        default:
            printf("Las opciones van del 1 al 4, reintente");
            break;
        }
    }
    while(optionMenu != 4);

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param listaSoporte LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* listaSoporte)
{
    int retorno = -1; //Variable que retorna la funcion (1 - TodoOK // 0 - Error)
    FILE* pArchivo; //Variable puntero al archivo
    if((pArchivo = fopen(path, "r")) != NULL) //Condicional, verifico si la lectura del archivo, si no retorna NULL accedo al parse_Soporte
    {
        printf("se encontro el archivo");
        parser_FromText(pArchivo, listaSoporte); //Funcion parser empleados modo texto
        retorno = 0;
    }
    else  //Si retorna NULL no encontro el archivo, por lo tanto lo creo e informo que no se encontro y se creo uno nuevo
    {
        if((pArchivo = fopen(path, "w")) != NULL)
        {
            printf("\n --> No se encontro el archivo. Se creo uno nuevo con el codigoProblemaStr \"%s\"\n\n", path);
            retorno = 0; //Cambio el el valor del retorno
        }
    }
    return retorno; //Retorno a la varaible
}

/** \brief Listar soporte
 *
 * \param pArrayListSoporte LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListSoporte)
{
    int retorno = 0; //Variable que retorna la funcion (1 - TodoOK // 0 - Error)
    Soporte* this; //Creo puntero a empleado
    system("clear");
    for(int i=0; i<ll_len(pArrayListSoporte); i++) //Recorro el array de empleados
    {
        this = (Soporte*)ll_get(pArrayListSoporte, i); //Le asigno a "this" lo que retorna "ll_get()"
        sop_printData(this); //Imprimo los datos del empleado
        retorno = 1; //Cambio la variable
    }
    printf("\n");
    return retorno; //Retorno la variable a la funcion
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param listaSoporte LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* listaSoporte)
{
    /*printf("Empezo a guardar\n");
    FILE* pArchivo; //Puntero al archivo
    //Soporte* this; //Creo puntero a estructura empleado
    int retorno = -1; //Variable retorno
    //Variables buffer -->
    int cantFotos = 0;
    int mayorA150 = 0;
    int mayorA300 = 0;
    int fotosPolaroids = 0;
    //<---
    printf("Inicializo variables\n");

    inf_cantFotos(listaSoporte, &cantFotos);
    //inf_cantEntCodigoProblemaStrFoto(listaSoporte, &cantPlus, &cantRegular, &cantGold);
    ll_count(listaSoporte, (void*)inf_contMayorA150, &mayorA150);
    ll_count(listaSoporte, (void*)inf_contMayorA300, &mayorA300);
    ll_count(listaSoporte, (void*)inf_contPolaroid, &fotosPolaroids);

    pArchivo = fopen(path, "w"); //Abro el archivo en modo escritura
    if(pArchivo != NULL && listaSoporte != NULL) //Condicional, verifico que la apertura del archivo y el array de empelados no sea NULL, si no lo es ingreso
    {
        fprintf(pArchivo, "********************\nInforme de ventas\n********************\n");
        fprintf(pArchivo, "- CodigoProblema total de fotos reveladas totales: %d\n", cantFotos);
        fprintf(pArchivo, "- CodigoProblema de ventas por un monto mayor a $150: %d\n", mayorA150);
        fprintf(pArchivo, "- CodigoProblema de ventas por un monto mayor a $300: %d\n", mayorA300);
        fprintf(pArchivo, "- Promedio de fotos polaroids reveladas: %d\n", fotosPolaroids);
        fprintf(pArchivo, "********************\n");

        printf("\n --> Datos guardados con exito.\n\n");
        retorno = 0; //Cambio el valor de la variable que retorna la funcion
    }
    fclose(pArchivo); //Cierro el archivo
    return retorno; //Retorno el valor de la variable*/
    return 0;
}
