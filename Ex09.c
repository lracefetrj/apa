#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main (int argc, char **argv)
{
    
    if (argc < 2)
    {
        printf ("Modo de usar: ./Ex09 <n1> <n2>\n");
        printf ("Onde: n1 e n2 são números inteiros maior do que zero (N > 0).\n");
        printf ("Exemplo: ./Ex09 20 60\n");
        return EXIT_FAILURE;
    }
    
    int n = atol (argv[1]);
    int m = atol (argv[2]);
    
    List *lista = lst_create ();
    
    int data[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    for (int i = 0; i < 10; i++)
    {
        lista = lst_add (lista, data[i]);
    }
    
    printf (1 == lst_search (lista, n) ? "Achei: %d\n" : "Não achei: %d\n", n);
    printf (1 == lst_search (lista, m) ? "Achei: %d\n" : "Não achei: %d\n", m);
    
    lst_print (lista);
    
    lista = lst_exchange_info (lista, n, m);
    
    lst_print (lista);
    
    lista = lst_destroy (lista);
    
    lst_print (lista);
    
    printf ("\nFim!\n");
    return EXIT_SUCCESS;
}
