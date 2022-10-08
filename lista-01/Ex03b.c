#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define _64BYTES_ 64

int main (int argc, char **argv)
{
    
    if (argc < 2)
    {
        printf ("Modo de usar: ./Ex03b <n>\n");
        printf ("Onde: n número inteiro (n > 0).\n");
        printf ("Exemplo: ./Ex03b 15 \n");
        return EXIT_FAILURE;
    }
    
    char *ptr, *d = argv[1];
    
    uint64_t dec = strtoul (d, &ptr, 10);
    
    if ((ptr == d) || (*ptr != '\0'))
    {
        printf ("Entre com um valor inteiro.\n");
        printf ("Exemplo: ./Ex03b 15 \n");
        return EXIT_FAILURE;
    }
    
    int bin[_64BYTES_];
    
    int c = 0;
    uint64_t div = dec;
    while (div > 0)
    {
        bin[c++] = (div % 2);
        div /= 2;
    }
    
    char *b = (char *) calloc (c, sizeof (char));
    
    for (int i = 0; i < c; i++)
        b[i] = bin[c - i - 1] + '0';
    
    printf ("Decimal para Binário: \n");
    printf ("Binário:\t%s\n", b);
    printf ("Decimal:\t%lu \n", dec);
    
    printf ("\nFim!\n");
    
    free (b);
    return EXIT_SUCCESS;
}
