#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX 100

typedef struct sCanzone{                                            //struttura per contenere ogni canzone
    int numero;                                                     //numero della canzone
    char titolo[MAX];                                               //titolo della canzone    
    char artista[MAX];                                              //nome dell'artista
    bool riprodotta;                                                //indica se è già stata riprodotta o no
    struct sCanzone* next;                                          //puntatore autoreferenziale, serve a scorrere la lista
}Canzone;

void randomOut (Canzone* head, int contatore);                      //funzione per riordinare le canzoni e stamparle
void push (Canzone* head, char* riga, int counter);                 //funzione per passsare alla lista successiva e riempire la struttura

int main()
{  
    Canzone* head;  
    int cont = 0;
    char riga[MAX];                                            //array che conterrà le righe del file                                                  
    FILE* fp;

    fp = fopen("playlist.csv", "r");
    if (fp == NULL)                                            //in caso di errore nell'apertura del file
    {
        printf("errore nell'apertura del file\n");
        system("pause");
        return -1;
    }
    head = (Canzone*) malloc (sizeof(Canzone));     //allocazione dinamica della lista di strutture            
    while (fgets(riga, MAX, fp) != NULL)            //fgets legge le righe del file, vuole 3 argomenti la variabile in cui salva la riga che ha letto, la lunghezza massima della riga e il puntatore al file che si vuole leggere
    {                         
        push(head, riga, cont);                     //si aggiunge una lista e si riempie una struttura
        cont++;
    }
    cont--;                                         //cont va diminuito di uno se no stampa solo la prima struttura
    randomOut(head, cont);
    fclose(fp);                                     //si chiude il file
    free(head);                                     //free serve a elimina lo spazio allocato quando non serve più alla lista
    system("pause");
    return 0;
}

void push (Canzone* head, char* riga, int counter)
{
    if (counter == 0)                                           //per la prima lista
    {
        head->numero = atoi(strtok(riga,","));
        strcpy(head->titolo, strtok(NULL, ","));                //strcpy copia nel ciò che sta a secondo membro nel primo
        strcpy(head->artista, strtok(NULL, ","));               
        head->riprodotta = false;                               //false = non riprodotta; true = riprodotta
        head->next = NULL;          
    }
    else                                                        //se la prima lista è già stata fatta si passa alle successive
    {                                                               
        Canzone *appoggio = head;                                          
        while (appoggio->next != NULL)                          
        {                                                       
            appoggio = appoggio->next;                          //per scorrere tutta la lista
        }
        appoggio->next = (Canzone*) malloc(sizeof(Canzone));    //si alloca dinamicamente ogni singola struttura
        appoggio->next->numero = atoi(strtok(riga,","));        //atoi converte una stringa in un numero intero                             
        strcpy(appoggio->next->titolo, strtok(NULL, ","));      //strtok restituisce il numero della prima prima parte della stringa
        strcpy(appoggio->next->artista, strtok(NULL, ","));     //quando si richiama strtok dopo la prima volta si mette sempre NULL
        appoggio->next->riprodotta = false;
        appoggio->next->next = NULL;                            //per passare alla lista successiva
    }
}

void randomOut(Canzone* head, int contatore)
{
    int nriproduzioni;
    int random;

    Canzone* appoggio;
            
        for (int j = 0; j < contatore; j++)                      //per ogni canzone                                    
        {
            do
            {
                appoggio = head;                                 //si usa appoggio al posto di head
                random = rand() % contatore;                     //il resto tra rand e il contatore è per forza 0 o un numero più piccolo del contatore
                for (int b = 0; b < random; b++)                 //scorre fino a random
                {
                    appoggio = appoggio->next;
                }
            } while (appoggio->next->riprodotta);                                                          //ripete finchè la canzone non è stata riprodotta (false)
            appoggio->next->riprodotta = true;                                                             //esce dal do while solo se la canzone viene riprodotta e quindi la si fa diventare true per non farla riprodurre più
            printf("sto riproducendo: %s di %s \n\n", appoggio->next->titolo, appoggio->next->artista);    //stampa della canzone che verrà riprodotta     
        }
}                                                                   