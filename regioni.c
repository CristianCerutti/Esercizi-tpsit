#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300

typedef struct Sregione
{
    char *data;
    char *stato;
    int codice;
    char *denominazione_regione;
    float lat;
    float lon;
    int ricoverati_con_sintomi;
    int terapia_intensiva;
    int totale_ospedalizzati;
    float isolamento_domiciliare;
    int totale_positivi;
    float variazione_totale_positivi;
    int nuovi_positivi;
    int dimessi_guariti;
    int deceduti;
    int casi_da_sospetto_diagnostico;
    int casi_da_screening;
    int totale_casi;
    int tamponi;
    int casi_testati;
    int input;
}regione;


int main()
{
    FILE* fp;
    regione *reg;
    int cont = 0;
    char inutile[MAX];
    char riga[MAX];
    int totale_ricoverati_terapia_intensiva = 0;
    int top1_ricoverati_terapia_intensiva = -1;
    int top2_ricoverati_terapia_intensiva = -1;
    int top3_ricoverati_terapia_intensiva = -1;
    char *top1_terapia;
    char *top2_terapia;
    char *top3_terapia;
    int top1_meno_casi_positivi = 99999999;
    int top2_meno_casi_positivi = 99999999;
    int top3_meno_casi_positivi = 99999999;
    char *top1_menopositivi;
    char *top2_menopositivi;
    char *top3_menopositivi;
    int input;
    fp = fopen("data.csv", "r");
    if (fp == NULL)
    {
        printf("errore nell'apertura del file\n");
        system("pause");
        return -1;
    }
    while (fgets(inutile,MAX,fp))
    {
        cont++;
    }
    reg = (regione*) malloc (cont * sizeof(regione));
    reg->data = (char*) malloc (cont *sizeof(char));
    reg->stato = (char*) malloc (cont *sizeof(char));
    reg->denominazione_regione = (char*) malloc (cont *sizeof(char));
    fclose(fp);
    fp = fopen("data.csv", "r");
    cont = 0;

    while (fgets(riga,MAX,fp))
    {
        (reg+cont)->data = strdup(strtok(riga,","));
        (reg+cont)->stato = strdup(strtok(NULL,","));
        (reg+cont)->codice = atoi(strtok(NULL, ","));
        (reg+cont)->denominazione_regione = strdup(strtok(NULL,","));
        (reg+cont)->lat = atoi(strtok(NULL, ","));
        (reg+cont)->lon = atoi(strtok(NULL, ","));
        (reg+cont)->ricoverati_con_sintomi = atoi(strtok(NULL, ","));
        (reg+cont)->terapia_intensiva = atoi(strtok(NULL, ","));
        totale_ricoverati_terapia_intensiva = totale_ricoverati_terapia_intensiva + (reg+cont)->terapia_intensiva;
        (reg+cont)->totale_ospedalizzati = atoi(strtok(NULL, ","));
        (reg+cont)->isolamento_domiciliare = atoi(strtok(NULL, ","));
        (reg+cont)->totale_positivi = atoi(strtok(NULL, ","));
        (reg+cont)->variazione_totale_positivi = atoi(strtok(NULL, ","));
        (reg+cont)->nuovi_positivi = atoi(strtok(NULL, ","));
        (reg+cont)->dimessi_guariti = atoi(strtok(NULL, ","));
        (reg+cont)->deceduti = atoi(strtok(NULL, ","));
        (reg+cont)->casi_da_sospetto_diagnostico = atoi(strtok(NULL, ","));
        (reg+cont)->casi_da_screening = atoi(strtok(NULL, ","));
        (reg+cont)->totale_casi = atoi(strtok(NULL, ","));
        (reg+cont)->tamponi = atoi(strtok(NULL, ","));
        (reg+cont)->casi_testati = atoi(strtok(NULL, ","));
        
        if ((reg+cont)->terapia_intensiva > top1_ricoverati_terapia_intensiva)
        {
            top1_ricoverati_terapia_intensiva = (reg+cont)->terapia_intensiva;
            top1_terapia = (reg+cont)->denominazione_regione;
        }
        else
        {
            if ((reg+cont)->terapia_intensiva > top2_ricoverati_terapia_intensiva)
            {
                top2_ricoverati_terapia_intensiva = (reg+cont)->terapia_intensiva;
                top2_terapia = (reg+cont)->denominazione_regione;
            }
            else
            {
                top3_ricoverati_terapia_intensiva = (reg+cont)->terapia_intensiva;
                top3_terapia = (reg+cont)->denominazione_regione;
            }
        }
        if ((reg+cont)->totale_positivi < top1_meno_casi_positivi)
        {
            top1_meno_casi_positivi = (reg+cont)->totale_positivi;
            top1_menopositivi = (reg+cont)->denominazione_regione;
        }
        else
        {
            if ((reg+cont)->totale_positivi < top2_meno_casi_positivi)
            {
                top2_meno_casi_positivi = (reg+cont)->totale_positivi;
                top2_menopositivi = (reg+cont)->denominazione_regione;
            }
            else
            {
                top3_meno_casi_positivi = (reg+cont)->totale_positivi;
                top3_menopositivi = (reg+cont)->denominazione_regione;
            }  
        }
        cont ++;
    }
    //printf("%d", cont);
    printf("inserire 1 per visualizzare la top 3 delle regioni per numero di ricoveri in terapia intensiva\n");
    printf("inserire 2 per visualizzare il numero totale dei ricoverati in terapia intensiva\n");
    printf("inserire 3 per visualizzare la top 3 delle regioni con meno casi positivi\n");
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        printf("posizione 1: %s\n", top1_terapia);
        printf("posizione 2: %s\n", top2_terapia);
        printf("posizione 3: %s\n", top3_terapia);
        break;
    case 2:
        printf("il numero totale dei ricoverati in terapia intensiva e': %d\n", totale_ricoverati_terapia_intensiva);
        break;
    case 3:
        printf("posizione 1: %s\n", top1_menopositivi);
        printf("posizionw 2: %s\n", top2_menopositivi);
        printf("posizione 3: %s\n", top3_menopositivi);
        break;
    default:
    printf("e' stato inserito un numero sbagliato\n");
        break;
    }
    fclose (fp);
    free(reg);
    system("pause");
    return 0;
}