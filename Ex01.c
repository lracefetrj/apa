#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int main (int argc, char **argv)
{
    
    if (argc < 2)
    {
        printf ("Modo de usar: ./Ex01 <N>\n");
        printf ("Onde: N é um número inteiro maior do que um (N > 1).\n");
        printf ("Exemplo: ./Ex01 22\n");
        return EXIT_FAILURE;
    }
    
    uint64_t n = atol (argv[1]);
    
    if (n <= 1)
    {
        printf ("N tem que ser maior do que um (N > 1).\n");
        return EXIT_FAILURE;
    }
    
    char *array = (char *) malloc ((n + 1) * sizeof (char));
    
    if (array == NULL)
    {
        printf ("Erro na alocação da memória. Valor de N (%lu) muito grande.\n", n);
        return EXIT_FAILURE;
    }
    
    memset (array, 0, (n + 1) * sizeof (char));
    
    uint64_t k, l, raiz = sqrtl (n);
    
    for (uint64_t j = 2; j <= raiz; j++)
    {
        k = 0;
        if (*(array + j) == 0)
        {
            while ((l = (j * j + k * j)) <= n)
            {
                *(array + l) = 1;
                k++;
            }
        }
    }
    
    for (uint64_t j = 2; j <= n; j++)
    {
        if (*(array + j) == 0)
            printf ("%lu ", j);
    }
    
    free (array);
    
    printf ("\nFim!\n");
    return EXIT_SUCCESS;
}
