#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    
    if (argc < 2)
    {
        printf ("Modo de usar: ./Ex04 <nome do arquivo>  <nn>\n");
        printf ("Exemplo: ./Ex04 Ex04.c \n");
        return EXIT_FAILURE;
    }
    
    char *fn = *++argv;
    
    if (fn == NULL)
    {
        printf ("Nome do arquivo inválido.\n");
        printf ("Exemplo: ./Ex04 Ex04.c \n");
        return EXIT_FAILURE;
    }
    
    FILE *fp = NULL;
    
    if ((fp = fopen (fn, "r")) == NULL)
    {
        printf ("Não é possível abrir o arquivo %s.\n", fn);
        return EXIT_FAILURE;
    }
    
    int ch, v = 0;
    while ((ch = getc (fp)) != EOF)
    {
        if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O'
            || ch == 'u' || ch == 'U')
        {
            v++;
        }
        
    }
    
    fclose (fp);
    
    printf ("Relatório: \n");
    printf ("Número de vogais:\t%d\n", v);
    
    printf ("\nFim!\n");
    return EXIT_SUCCESS;
}
