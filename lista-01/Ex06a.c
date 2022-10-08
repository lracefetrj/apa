#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int lst_binary_search (const int32_t *lst, const int32_t len, const int32_t data);

int lst_binary_search (const int32_t *lst, const int32_t len, const int32_t data)
{
    if (lst == NULL)
        return 0;
    
    int32_t no = len / 2, valor;
    double a0 = no, a1 = 0;
    
    do
    {
        valor = lst[no];
        if (valor == data)
            return 1;
        
        a1 = (a1 - no) / 2;
        a1 = fabs (a1 > 0 ? ceil (a1) : floor (a1));
        if (valor > data)
            no -= a1;
        else
            no += a1;
        
        a1 = a0;
        a0 = no;
        
        if (no < 0)
            no = 0;
        
        if (no >= len)
            no = len - 1;
        
    }
    while (fabs (a1 - no) > 0);
    
    return 0;
}

int main (int argc, char **argv)
{
    
    if (argc < 2)
    {
        printf ("Modo de usar: ./Ex06 <N> <n>\n");
        printf ("Onde: N e n são números inteiros.\n");
        printf ("Exemplo: ./Ex06 20 22\n");
        return EXIT_FAILURE;
    }
    
    int32_t N = atoi (argv[1]), n = atoi (argv[2]);
    
    if (N < 1 || N > INT32_MAX)
    {
        printf ("N inválido (1 < N < %d).\n", INT32_MAX);
        return EXIT_FAILURE;
    }
    
    if (n < 0 || n > INT32_MAX)
    {
        printf ("n inválido (0 < n < %d).\n", INT32_MAX);
        return EXIT_FAILURE;
    }
    
    int32_t *lista = (int32_t *) malloc (N * sizeof (int32_t));
    
    if (lista == NULL)
        return EXIT_FAILURE;
    
    for (int32_t i = 0; i < N; i++)
    {
        lista[i] = i;
    }
    
    printf ("\n\n");
    
    int rst = lst_binary_search (lista, N, n);
    
    printf ("O número %d existe na lista? %s\n", n, rst ? "Sim" : "Não");
    
    free (lista);
    
    printf ("\nFim!\n");
    
    return EXIT_SUCCESS;
}
