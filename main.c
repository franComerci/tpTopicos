#include "main.h"
void primeraMayus(char *cadena);
void guionAespacio(char *cadena);
void decodificar(char *cadena);
// tpTopicos.exe indices_icc_general_capitulos.csv Indices_items_obra.csv

int main(int argc, char *argv[])
{
    printf("Cantidad de argumentos: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    return 0;
}

void guionAespacio(char *cadena)
{
    while(*cadena != '\0') {
        if (*cadena == '_') {
            *cadena = ' ';
        }
        cadena++;
    }
}

void primeraMayus(char *cadena)
{
    int letra1 = 1;

    while(*cadena != '\0')
    {
        if (isalpha(*cadena))
        {
            if (letra1)
                {
                *cadena = toupper(*cadena);
                letra1 = 0;
            } else
            {
                *cadena = tolower(*cadena);
            }
        } else if (*cadena == ' ')
        {
            letra1 = 0;
        }
        cadena++;
    }
}
void decodificar(char *cadena)
{

    int pos = 0;
    while(*cadena != 0)
    {
        char c = *cadena;
        char base;
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
          base = (c >= 'a') ? 'a' : 'A';
            int desp = (pos % 2 == 0) ? 4: 2;

            *cadena = base + ((c - base + desp) % 26);
        }
        pos++;
        cadena++;
    }
}

