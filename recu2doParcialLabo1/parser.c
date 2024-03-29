#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "soporte.h"
#include "controller.h"

/** \brief Parsea los datos los datos de los soporte desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pLinkedListSoporte LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE* pFile, LinkedList* pLinkedList)
{
    Soporte* this; //Creo un nuevo entrega
    int datosLeidos; //Contador de lectura
    char auxId[50], fecha[50], numeroCliente[50], codigoProblema[50], codigoProblemaStr[50], solucionado[50]; //Variables buffer


    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, fecha, numeroCliente, codigoProblema, solucionado); //Hago una primera lectura "fantasma" para leer el titulo el cual no voy a almacenar y le asigno a "datosLeidos" el retorno de la lectura "fscanf"


    while(!feof(pFile)) //Mientras no se llege al final del archivo
    {
        datosLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, fecha, numeroCliente, codigoProblema, solucionado); //Le asigno a "datosLeidos" el retorno de la lectura "fscanf"

        if(datosLeidos == 5) //Si datosLeidos es igual a los 4 datos pedidos a leer
        {
            if(atoi(codigoProblema) == 1)
            {
                strncpy(codigoProblemaStr, "No enciende PC", 25);
            }
            else if(atoi(codigoProblema) == 2)
            {
                strncpy(codigoProblemaStr, "No funciona mouse", 25);
            }
            else if(atoi(codigoProblema) == 3)
            {
                strncpy(codigoProblemaStr, "No funciona teclado", 25);
            }
            else if(atoi(codigoProblema) == 4)
            {
                strncpy(codigoProblemaStr, "No hay internet", 25);
            }
            else if(atoi(codigoProblema) == 5)
            {
                strncpy(codigoProblemaStr, "No funciona telefono", 25);
            }

            this = sop_newParametros(auxId, fecha, numeroCliente, codigoProblema, codigoProblemaStr, solucionado); //Le asigno a "this" las variables leidas casteadas en la funcion

            if(this != NULL)
            {
                ll_add(pLinkedList, this); //Agrego "this" al final del array de soporte
                printf("Agrego\n");
            }
        }
        else if(datosLeidos != 6 && this != NULL) //Si datosLeidos es distinto a los 4 datos pedidos a leer
        {
            if(!feof(pFile)) //Si aun no se llego al final del archivo lo informo
            {
                printf("\nError al leer el ultimo dato.");
                break;
            }
            else //Si se leyo todo el archivo sin problemas lo informo
            {
                printf("\nSe leyo todo el archivo.");
            }
        }
    }
    printf("\n --> Empleados cargados correctamente.\n\n");
    fclose(pFile); //Cierro el archivo
    return 1;
}
