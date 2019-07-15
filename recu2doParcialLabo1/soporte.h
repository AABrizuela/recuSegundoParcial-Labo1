#ifndef SOPORTE_H
#define SOPORTE_H
typedef struct
{
    int id;
    char fecha[15];
    int numeroCliente;
    int codigoProblema;
    char codigoProblemaStr[25];
    char solucionado[5];
}Soporte;
#endif //SOPORTE_H


void sop_menu(LinkedList* listaSoporte);
Soporte* sop_new();
Soporte* sop_newParametros(char* auxId, char* fecha, char* numeroCliente, char* codigoProblema, char* codigoProblemaStr, char* solucionado);
int sop_delete(Soporte* this);

int sop_setId(Soporte* this,int id);
int sop_getId(Soporte* this,int* resultado);
int sop_setIdAsString(Soporte* this, char* id);
int sop_getIdAsString(Soporte* this, char* resultado);

int sop_setCodigoProblemaStr(Soporte* this,char* codigoProblemaStr);
int sop_getCodigoProblemaStr(Soporte* this,char* resultado);

int sop_setFecha(Soporte* this,char* fecha);
int sop_getFecha(Soporte* this,char* resultado);

int sop_setSolucionado(Soporte* this,char* solucionado);
int sop_getSolucionado(Soporte* this,char* resultado);

int sop_setCodigoProblema(Soporte* this,int codigoProblema);
int sop_getCodigoProblema(Soporte* this,int* resultado);
int sop_setCodigoProblemaAsString(Soporte* this, char* codigoProblema);
int sop_getCodigoProblemaAsString(Soporte* this, char* resultado);

int sop_setIdCliente(Soporte* this,int idCliente);
int sop_getIdCliente(Soporte* this,int* resultado);
int sop_setIdClienteAsString(Soporte* this, char* idCliente);
int sop_getIdClienteAsString(Soporte* this, char* resultado);
int sop_ControlId(LinkedList* pArrayListSoporte, char* idStr);

void sop_printData(Soporte* this);
