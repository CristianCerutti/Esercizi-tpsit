#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int main()
{   
    int t = 0;
    int a = 0;
    int g = 0;
    int c = 0;
    char riga[MAX];                                         //array che conterrà la riga

    FILE* fp = fopen("rna.txt", "r");
    if (fp == NULL)
    {
        printf("errore nell'apertura del file\n");                          //in caso di errore nell'apertura del file
        system("pause");
        return -1;
    }

        while (fgets(riga,MAX,fp))
        {
            int cont = 0;
            while (riga[cont] != '\n')                      //finchè non va a capo
            {
                switch (riga[cont])
                {
                 case 't':
                t++;
                 case 'a':                                  //ogni volta che incontra la lettera interessata incrementa
                a++;
                 case 'g':
                g++;
                 case 'c':
                c++;
                 break;
                default:
                 break;
                }
                cont++;                             //per cambiare riga
            }
            
        }
        printf("timina: %d\nadenina: %d\nguanina: %d\ncitosina: %d\n", t, a, g, c);
    
    fclose(fp);
    system("pause");
    return 0;
}