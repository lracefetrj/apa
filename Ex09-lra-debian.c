#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "Lista.h"

int main (int argc, char **argv)
{
    
    if (argc < 2)
    {
        printf ("Modo de usar: ./primo <N>\n");
        printf ("Onde: N é um número inteiro maior do que um (N > 1).\n");
        printf ("Exemplo: ./primo 22\n");
        return EXIT_FAILURE;
    }
    
    int n = atol (argv[1]);
    int m = atol (argv[2]);
    
    List *lista = lst_create ();
    
    int i = 0, data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    
    for (int i = 10; i < 1000; i += 10)
    {
        lista = lst_add_ord (lista, &data[2]);
    }
//    lista = lst_add_ord (lista, &data[i++]);
//    lista = lst_add_ord (lista, &data[i++]);
//    lista = lst_add_ord (lista, &data[i++]);
//    lista = lst_add_ord (lista, &data[i++]);
//    lista = lst_add_ord (lista, &data[i++]);
    
    printf (1 == lst_search (lista, &data[2]) ? "Achei: %d\n" : "Não achei: %d\n", data[2]);
    
    lst_print (lista);
    
    lista = lst_remove (lista, &data[2]);
    
    lst_print (lista);
    
    lista = lst_destroy (lista);
    
    lst_print (lista);
    
    printf ("\nFim!\n");
    return EXIT_SUCCESS;
}
