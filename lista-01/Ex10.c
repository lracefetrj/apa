#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main (void)
{
    
    List *lista = lst_create ();
    
    int data[] = {100, -5, 80, 70, 60, 0, 40, 30, 20, -10};
    
    for (int i = 9; i >= 0; i--)
    {
        lista = lst_add (lista, data[i]);
    }
    
    lst_print (lista);
    
    lista = lst_move_menor (lista);
    
    lst_print (lista);
    
    lst_destroy (lista);
    
    printf ("\nFim!\n");
    return EXIT_SUCCESS;
}
