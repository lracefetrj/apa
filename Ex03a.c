#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main (int argc, char **argv)
{
    
    if (argc < 2)
    {
        printf ("Modo de usar: ./Ex03a <n>\n");
        printf ("Onde: n sequencia contígua valores 0's e 1's.\n");
        printf ("Exemplo: ./Ex03a 1001110001110011 \n");
        return EXIT_FAILURE;
    }
    
    char *bin = argv[1];
    
    int tam = strlen (bin);
    
    int er = 0;
    char d;
    uint64_t dec = 0;
    for (int i = 0; i < tam; i++)
    {
        d = *(bin + i);
        
        if (isdigit(d) && (d == '0' || d == '1'))
        {
            dec += powl (d == '1' ? 2.0 : 0.0, (tam - i - 1));
        }
        else
        {
            er = 1;
            break;
        }
    }
    
    if (er == 1)
    {
        printf ("Entre com um valor binário.\n");
        printf ("Exemplo: ./Ex03a 1001110001110011 \n");
        return EXIT_FAILURE;
    }
    
    printf ("Binário para Decimal: \n");
    printf ("Binário: \t%s\n", bin);
    printf ("Decimal:\t%lu \n", dec);
    
    printf ("\nFim!\n");
    return EXIT_SUCCESS;
}
