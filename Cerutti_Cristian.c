#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct SDati
{
    char *istruzioni;
    char *mese;
    int giorno;
    int ID_post;
    int like;
}dati;


int main()
{
    dati* dat;
    FILE* fp;
    int cont = 0;
    int contpost = 0;
    char inutile[MAX];
    char riga[MAX];
    int totlike = 0;
    char input[MAX];
    int x;
    fp = fopen("instagram.csv", "r");
    if (fp == NULL)
    {
        printf("errore nell'apertura del file\n");              //in caso di errore nell'apertura del file
        system("pause");
        return -1;
    }
    while (fgets(inutile,MAX,fp))
    {
        cont++;                                                     //si usa cont per sapere il numero delle righe del file
    }
    fclose(fp);
    dat = (dati*) malloc (cont * sizeof(dati));                 //si usa cont per sapere quante variabili dati servono e quindi calcolare lo spazio in memoria
    cont = 0;
    fp = fopen("instagram.csv", "r");
    if (fp == NULL)
    {
        printf("errore nell'apertura del file\n");
        system("pause");
        return -1;
    }
    printf("inserire il nome del mese: \n");
    fgets(input,MAX,stdin);
    while (fgets(riga,MAX,fp))
    {
        strcpy ((dat+cont)->istruzioni, strdup(strtok(riga,",")))      //si duplica la stringa fino alla prossima virgola della cont riga
        strcpy ((dat+cont)->mese, strdup(strtok(NULL,",")))      //quando si richiama la strtok dalla seconda volta in poi per andare a capo si scrive NULL
        (dat+cont)->giorno = atoi(strtok(NULL,","));
        (dat+cont)->ID_post = atoi(strtok(NULL,","));           //atoi converte una stringa in un numero intero
        (dat+cont)->like = atoi(strtok(NULL,","));
        if (strcmp(input, (dat+cont)->mese) == 0)                          //se il mese dato in input è uguale al mese di questa riga vengono aggiornati i post e i like totali del mese
        {
            totlike = totlike + (dat+cont)->like;
            contpost++;
        }
       cont++; 
    }
    printf("il mese %s ci sono stati %d post e %d like\n", input, contpost, totlike);
    fclose(fp);
    free(dat);                                                  //per liberare l'area di memoria allocata
    system("pause");
    return 0;
}