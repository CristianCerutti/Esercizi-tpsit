#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX 100


typedef struct SCanzone{                                            //struttura per contenere ogni canzone
    int numero;
    char *titolo;                                                   
    char *artista;
    bool riprodotta;
}Canzone;

void randomOut(Canzone* playlist, int contatore);                       //funzione per riordinare le canzoni e stamparle

int main()
{
int cont = 0;                                                  
FILE* fp;
fp = fopen("playlist.csv", "r");
if (fp == NULL)                                                 //in caso di errore nell'apertura del file
{
    printf("errore nell'apertura del file\n");
    system("pause");
    return -1;
}
Canzone* playlist;
char inutile[MAX];
while (fgets(inutile,MAX,fp))
{
    cont++;
}
fclose(fp);
playlist = (Canzone*) malloc (cont * sizeof(Canzone));             //playlist viene dichiarata di tipo canzone in modo da poter accedere alla struttura e creare un array di strutture con la malloc
char riga[MAX];                                               //array che conterrà le righe del file
cont = 0;                                             //per resettare il contatore

fp = fopen("playlist.csv", "r");
while (fgets(riga,MAX,fp))                                 //fgets legge le righe del file, vuole 3 argomenti la variabile in cui salva la riga che ha letto, la lunghezza massima della riga e il puntatore al file che si vuole leggere
{                         
    (playlist+cont)->numero = atoi(strtok(riga,","));             //atoi converte una stringa in un numero intero         //strtok restituisce il numero della prima prima parte della stringa    
    (playlist+cont)->titolo = strdup (strtok(NULL,","));          //strdup prende in pasto una stringa e ne crea una copia 
    (playlist+cont)->artista = strdup(strtok(NULL,","));           //quando si richiama strtok dopo la prima volta si mette sempre NULL  
    cont++;
}
    randomOut(playlist, cont);
    fclose(fp);
    free(playlist);                                     //free serve a elimina lo spazio allocato quando non serve più l'array
    system("pause");
    return 0;
}

void randomOut(Canzone* playlist, int contatore)
{
    int nriproduzioni;
    int random;
    printf("inserire il numero di volte che si vuole riprodurre la playlist: ");
    scanf("%d", &nriproduzioni);
    for (int n = 0; n < contatore; n++)
              {
                  (playlist+n)->riprodotta = false;                               //false = canzoni non riprodotte true = canzoni riprodotte
              }
          for (int i = 0; i < nriproduzioni; i++)                               //si riproducono tutte le canzoni nriproduzioni volte
          {
              printf("riproduzione numero: %d\n", i+1);
              for (int j = 0; j < contatore; j++)                                //per ogni canzone                                    
              {
                  do
                  {
                     random = rand() % contatore;                                //il resto tra rand e il contatore è per forza 0 o un numero più piccolo del contatore
                  } while ((playlist+random)->riprodotta);                         //ripete finchè la canzone non è stata riprodotta(false)
                  (playlist+random)->riprodotta = true;                            //esce dal do while solo se la canzone viene riprodotta e quindi la si fa diventare true per non farla riprodurre più
                  printf("sto riproducendo: %s di %s \n\n", playlist[random].titolo, playlist[random].artista);         
              }
              for (int k = 0; k < contatore; k++)                                   
              {
                  (playlist+k)->riprodotta = false;                                   //per resettare le canzoni e rimetterle a non riprodotte
              }
              }
}
                                                                         
