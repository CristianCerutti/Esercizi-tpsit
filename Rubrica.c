#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_CONTATTI 1024

typedef struct Scontatto{
    int id;
    char nome[64];
    char numero[64];
}contatto;

typedef struct Srubrica{
    int num_inseriti;
    contatto db[MAX_NUM_CONTATTI];
}rubrica;

int inserisci(rubrica *r, char *nome, char *numero);
char *trova_numero_da_nome( rubrica *r, char *nome);
void stampa_rubrica(rubrica *r);

int main()
{
   rubrica r;
   contatto *c; 
   char* nome;
   char* numero;
   int input = 0;
   int input2 = 1;
   do
   {
       printf("inserire un numero maggiore di 0 per entrare nella rubrica: \n");
       scanf("%d", &input2);
       printf("inserire 1 per cercare contatti\ninserisci 2 per stampare la rubrica\ninserisci 3 per caricare un contatto\n");
       scanf("%d", &input);
       switch (input)
   {
   case 1:
       printf("e' stato scelto di trovare un contatto\n\n");
       printf("inserire un nome: \n");
       scanf("%c", &nome);
       trova_numero_da_nome(&r, nome);
       break;
    case 2:
       printf("e' stato scelto di stampare la rubrica\n\n");
       printf("stampa in corso...\n");
       stampa_rubrica(&r);
       break;
    case 3:
       printf("e' stato scelto di inserire un nuovo contatto\n\n");
       printf("inserire il nome del contatto: \n");
       scanf("%c", &nome);
       printf("inserire il numero di telefono del contatto: \n");
       scanf("%d", &numero);
       inserisci(&r, nome, numero);
       break;
   
   default:
   printf("e' stato inserito un numero errato\n");
       break;
   }
   } while(input2 > 0);
   system("pause");
   return 0;
}

int inserisci(rubrica *r, char *nome, char *numero)
{
    contatto *p;
    if (r->num_inseriti == MAX_NUM_CONTATTI){
        printf("rubrica piena");
        return -1;                  //errore
    }       
    p = &r->db[r->num_inseriti]; //punta la prima area di memoria disponibile
    strcpy(p->nome, nome);       //copia il nome
    strcpy(p->numero, numero);   //copia il numero 
    p->id = r->num_inseriti;
    r->num_inseriti++;
    return 0;            
}

char *trova_numero_da_nome(rubrica *r, char *nome)
{
    int i;
    contatto *p;
    for (i = 0; i < MAX_NUM_CONTATTI; i++)
    {
        if (i == r->num_inseriti)
        {
            break;                      //stop se abbiamo raggiunto l'ultimo
        }
        p = &r->db[i];                  //punto l'iesimo contatto
        if(strcmp(p->nome, nome)== 0){
            return p->numero;           //ritorno il num se i nomi coincidono
        }
        
    }
    
}

void stampa_rubrica(rubrica *r)
{
    int i;
    contatto *p;
    printf("\nstampa rubrica: %d contatti\n", r->num_inseriti);
    for (i = 0; i <MAX_NUM_CONTATTI; i++)
    {
        if (i == r->num_inseriti)
        {
            break;                      //stop se abbiamo raggiunto l'ultimo
        }
        p = &r->db[i];
        printf("%s, %s\n", p->nome, p->numero);
    }
    
}
