#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    
    if (argc < 2)
    {
        printf ("Modo de usar: ./Ex02 <n1> <n2> <n3> ... <nn>\n");
        printf ("Onde: n1, n2 ... são números inteiros.\n");
        printf ("Exemplo: ./Ex02 10 0 -5 22 \n");
        return EXIT_FAILURE;
    }
    
    char *a, *ptr;
    int t, p = 0, n = 0, z = 0, c = 0;
    for (int i = 1; i < argc; i++)
    {
        a = argv[i];
        t = strtol (a, &ptr, 10);
        
        if ((ptr == a) || (*ptr != '\0'))
            continue;
        
        if (t > 0)
            p++;
        else if (t < 0)
            n++;
        else if (t == 0)
            z++;
        
        c++;
    }
    
    if (c == 0)
    {
        printf ("Entre com valores válidos.\n");
        printf ("Exemplo: ./Ex02 10 0 -5 22 \n");
        return EXIT_FAILURE;
    }
    
    printf ("Relatório: \n");
    printf ("Positivos:\t%d (%.2f %%)\n", p, 100 * ((float) p / (float) c));
    printf ("Negativos:\t%d (%.2f %%)\n", n, 100 * ((float) n / (float) c));
    printf ("Zeros:\t\t%d (%.2f %%)\n", z, 100 * ((float) z / (float) c));
    printf ("Total:\t\t%d (%.2f %%)\n", c, 100.00);
    
    printf ("\nFim!\n");
    return EXIT_SUCCESS;
}
