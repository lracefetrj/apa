#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matriz_permutacao (int **m, int n)
{
    int *l, *c, exit = 1;
    
    if (m == NULL || n <= 1 || n >= 100)
        return 0;
    
    if ((l = (int *) calloc (n, sizeof (int))) == NULL)
        exit = 0;
    
    if ((c = (int *) calloc (n, sizeof (int))) == NULL)
        exit = 0;
    
    for (int i = 0; i < n && exit; i++)
        for (int j = 0; j < n && exit; j++)
            if (m[i][j] == 1)
            {
                l[i]++;
                c[j]++;
            }
            else if (m[i][j] != 0)
                exit = 0;
    
    for (int i = 0; i < n && exit; i++)
        if (l[i] != 1 || c[i] != 1)
            exit = 0;
    
    if (l) free (l);
    if (c) free (c);
    
    return exit;
}

int main (int argc, char **argv)
{
    
    if (argc < 2)
    {
        printf ("Modo de usar: ./Ex05 <n>\n");
        printf ("Onde: n inteiro (1 < n < 100).\n");
        printf ("Exemplo: ./Ex03a 9 \n");
        return EXIT_FAILURE;
    }
    
    char *ptr, *d = argv[1];
    
    int n = strtoul (d, &ptr, 10);
    
    if ((ptr == d) || (*ptr != '\0') || (n <= 1 || n >= 100))
    {
        printf ("Entre com um valor inteiro (1 < n < 100).\n");
        printf ("Exemplo: ./Ex05 9 \n");
        return EXIT_FAILURE;
    }
    
    n = 3;
    
    int **m = (int *) malloc (n * sizeof (int *));
    
    if (m != NULL)
    {
        for (int i = 0; i < n; i++)
            m[i] = (int *) malloc (n * sizeof (int));
    }
    else
        return EXIT_FAILURE;
    
    m[0][0] = 1;
    m[0][1] = 0;
    m[0][2] = 0;
    
    m[1][0] = 0;
    m[1][1] = 0;
    m[1][2] = 1;
    
    m[2][0] = 0;
    m[2][1] = 1;
    m[2][2] = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf ("%d\t", m[i][j]);
        printf ("\n");
        
    }
    
    int s = matriz_permutacao (m, n);
    
    printf ("\nMatriz é de permutação: %s\n", s ? "Sim" : "Não");
    
    printf ("\nFim!\n");
    
    if (m != NULL)
    {
        for (int i = 0; i < n; i++)
            free (m[i]);
        
        free (m);
    }
    
    return EXIT_SUCCESS;
}
