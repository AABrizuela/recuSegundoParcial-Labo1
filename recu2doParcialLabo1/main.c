#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"

int main()
{
    LinkedList* listaSoporte = ll_newLinkedList();

    if(listaSoporte == NULL)
    {
        return -1;
    }

    menu(listaSoporte);

    return 0;
}
