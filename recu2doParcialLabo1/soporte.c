#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "soporte.h"
#include "controller.h"
#include "utn.h"
//#include "informes.h"

/** \brief Crea posicion de memoria para un nuevo empleado.
 *
 * \return Entrega* posición de memoria de entrega.
 *
 */


Soporte* sop_new(void)
{
    return (Soporte*) malloc(sizeof(Soporte));
}

/** \brief Crea un nuevo empleado con posicion de memoria y contenido basado en strings.
 *
 * \param1 char* ID
 * \param2 char* codigoProblemaStr
 * \param3 char* codigoProblema
 * \param4 char* numeroCliente
 * \return retorno Soporte*. Devuelve el empleado si todo salio bien, o NULL si se pasaron mal parametros o no se pudo completar la operacion.
 *
 */


Soporte* sop_newParametros(char* id, char* fecha, char* numeroCliente, char* codigoProblema, char* codigoProblemaStr, char* solucionado)
{

    Soporte* retorno = NULL;
    Soporte* pAuxSoporte;
    if(id != NULL && codigoProblemaStr != NULL && codigoProblema != NULL && numeroCliente != NULL && fecha != NULL && solucionado != NULL)
    {

        pAuxSoporte = sop_new();

        if(pAuxSoporte != NULL)
        {
            if( !sop_setIdAsString(pAuxSoporte, id) && !sop_setCodigoProblemaStr(pAuxSoporte, codigoProblemaStr) &&
                !sop_setCodigoProblemaAsString(pAuxSoporte, codigoProblema) && !sop_setIdClienteAsString(pAuxSoporte, numeroCliente) &&
                !sop_setFecha(pAuxSoporte, fecha) && !sop_setSolucionado(pAuxSoporte, solucionado))
            {

                retorno = pAuxSoporte;
            }else
            {

                sop_delete(pAuxSoporte);
            }
        }
    }

    return retorno;
}

/** \brief Elimina un empleado.
 *
 * \param1 this Soporte* Empleado a eliminar.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */


int sop_delete(Soporte* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el ID de un empleado.
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 id int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int sop_setId(Soporte* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    printf("Retorno id: %d", retorno);
    return retorno;
}

/** \brief Obtiene el ID de un empleado.
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 resultado int* ID donde se encuentra.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int sop_getId(Soporte* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el ID de un empleado como string.
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 id char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */


int sop_setIdAsString(Soporte* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        if(esNumerico(id))
        {
            retorno = sop_setId(this, atoi(id));
        }

    }

    return retorno;
}

/** \brief Obtiene el ID de un empleado como string.
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int sop_getIdAsString(Soporte* this, char* resultado)
{
    int retorno = -1;
    int bufferId;
    if(this != NULL && resultado != NULL)
    {
        sop_getId(this, &bufferId);
        sprintf(resultado, "%d", bufferId);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el codigoProblemaStr
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 codigoProblemaStr char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */

int sop_setCodigoProblemaStr(Soporte* this, char* codigoProblemaStr)
{
    int retorno = -1;
    if(this != NULL && esSoloLetras(codigoProblemaStr))
    {
        strncpy(this->codigoProblemaStr, codigoProblemaStr, sizeof(this->codigoProblemaStr));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el codigoProblemaStr
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int sop_getCodigoProblemaStr(Soporte* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado, this->codigoProblemaStr);
        printf("codigo problema %s\n", resultado);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el fecha
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 fecha char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */
int sop_setFecha(Soporte* this, char* fecha)
{
    int retorno = -1;
    if(this != NULL && esFecha(fecha))
    {
        strncpy(this->fecha, fecha, sizeof(this->fecha));
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene el fecha
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int sop_getFecha(Soporte* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->fecha, 10);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el solucionado
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 solucionado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */
int sop_setSolucionado(Soporte* this, char* solucionado)
{
    int retorno = -1;
    if(this != NULL && esSoloLetras(solucionado))
    {
        strncpy(this->solucionado, solucionado, sizeof(this->solucionado));
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene el solucionado
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int sop_getSolucionado(Soporte* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->solucionado, 10);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define las horas trabajadas de un empleado.
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 codigoProblema int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int sop_setCodigoProblema(Soporte* this, int codigoProblema)
{
    int retorno = -1;
    if(this != NULL && codigoProblema >= 0)
    {
        this->codigoProblema = codigoProblema;
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado.
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 resultado int*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int sop_getCodigoProblema(Soporte* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->codigoProblema;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define las horas trabajadas de un empleado como string.
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 codigoProblema char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int sop_setCodigoProblemaAsString(Soporte* this, char* codigoProblema)
{
    int retorno = -1;
    if(this != NULL && codigoProblema >= 0)
    {
        if(esNumerico(codigoProblema))
        {
            retorno = sop_setCodigoProblema(this, atoi(codigoProblema));
        }
    }

    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado como string.
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int sop_getCodigoProblemaAsString(Soporte* this, char* resultado)
{
    int retorno = -1;
    int bufferCodigoProblema;
    //char bufferResultado[50];
    if(this != NULL && resultado != NULL)
    {
        bufferCodigoProblema = this->codigoProblema;
        sprintf(resultado, "%d", bufferCodigoProblema);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el numeroCliente de un empleado.
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 numeroCliente int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int sop_setIdCliente(Soporte* this, int numeroCliente)
{
    int retorno = -1;
    if(this != NULL && numeroCliente >= 0)
    {
        this->numeroCliente = numeroCliente;
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene el numeroCliente de un empleado.
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 resultado int*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int sop_getIdCliente(Soporte* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->numeroCliente;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el numeroCliente de un empleado como string.
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 numeroCliente char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int sop_setIdClienteAsString(Soporte* this, char* numeroCliente)
{
    int retorno = -1;
    if(this != NULL && numeroCliente >= 0)
    {
        if(esNumericoFlotante(numeroCliente))
        {
            retorno = sop_setIdCliente(this, atof(numeroCliente));
        }
    }

    return retorno;
}

/** \brief Define el numeroCliente de un empleado como string.
 *
 * \param1 this Soporte* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int sop_getIdClienteAsString(Soporte* this, char* resultado)
{
    int retorno = -1;
    int bufferIdCliente;
    //char bufferResultado[50];
    if(this != NULL && resultado != NULL)
    {
        bufferIdCliente = this->numeroCliente;
        sprintf(resultado, "%d", bufferIdCliente);
        retorno = 0;
    }
    return retorno;
}

/** \brief Controla si el id ingresado se encuentra en la lista
 *
 * \param pArrayListSoporte LinkedList* lista de empelados
 * \param idStr char* id en formato string
 * \return int 0 si hubo error - 1 si salio bien
 *
 */
int sop_ControlId(LinkedList* pArrayListSoporte, char* idStr)
{
    int retorno = 0; //Variable retorno funcion
    int id; //Variable ID
    id = atoi(idStr); //Casteo de string a entero
    Soporte* this; //Puntero a estructura
    if(pArrayListSoporte != NULL) //Condicional, verifica que sea distinto de NULL
    {
        for(int i=0; i<ll_len(pArrayListSoporte); i++) //Recorro el for en busca del ID ingresado
        {
            this = (Soporte*)ll_get(pArrayListSoporte, i); //Le asigno a this la estructura que retorna ll_get()
            if(this->id == id) //Si se encuentra el id ingresado se cambia la bandera y se rompe l iteraccion
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno; //Se retorna a la funcion el valor de retorno
}

void sop_printData(Soporte* this)
{
    int id; //Variable donde se almacena el id utilizando getId();
    char fecha[15]; //Variable donde se almacena el fecha utilizando getNobre();
    int numeroCliente; //Variable donde se almacenan las horas trabajadas utilizando getHorasTrabajadas();
    char codigoProblemaStr[25]; //Variable donde se almacena el codigoProblemaStr utilizando getId();
    char solucionado[5];

    sop_getId(this, &id); //Obtengo el Id del empleado
    sop_getFecha(this, fecha); //Obtengo el fecha del empleado
    sop_getIdCliente(this, &numeroCliente); //Obtengo las horas trabajadas del empelado
    sop_getCodigoProblemaStr(this, codigoProblemaStr); //Obtengo el codigo de problema
    sop_getSolucionado(this, solucionado);

    printf("| %3d | %s | %5d | %s | %5s |\n", id, fecha, numeroCliente, codigoProblemaStr, solucionado); //Muestro los datos del empleado
}
