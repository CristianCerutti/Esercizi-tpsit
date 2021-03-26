#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CUORE 'c'
#define PICCHE 'P'
#define QUADRI 'D'
#define FIORI 'F'

typedef struct Ris       //struttura che definisce il nuovo mazzo di sole carte rosse e funziona da coda FIFO
{
    int numero;             //numero della carta
    char seme;              //seme della carta
    struct Ris* next;
}Ris;          //(secondo mazzo)

typedef struct Node         //struttura che definisce la carta e funziona da coda FIFO
{
    int numero;             //numero della carta
    char seme;              //seme della carta
    struct Node* next;
}Node;          //(primo mazzo)

int is_empty(Node* head);
Node * dequeue(Node **head, Node **tail);
Ris * dequeue2(Ris **head, RIs **tail);
void enqueue1(Node ** head, Node **tail, Node *element);
void enqueue2(Node ** head, Node **tail, Node *element);
void enqueue3(Ris ** head, Ris **tail, Node *element);
void enqueue4(Ris ** head, Ris **tail, Node *element);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *elemento1 = NULL;     //seme (nella struttura char seme)
    Node *elemento2 = NULL;     //numero (nella struttura int numero)
    int cont1 = 4;      //semi 
    int cont2 = 13;     //numero
    for (int i= 0; i < cont1; i++){    //per tutti i semi
        elemento1 = (Node*) malloc(sizeof(Node));    //allocazione dinamica memoria
        if (i == 0){        //nei seguenti if si riempie la coda per ogni seme
            elemento1->seme = CUORE;
            enqueue1(&head, &tail, elemento1);
        }
        if (i == 1){
            elemento1->seme = PICCHE;
            enqueue1(&head, &tail, elemento1);
        }
        if (i == 2)
        {
            elemento1->seme = QUADRI;
            enqueue1(&head, &tail, elemento1);
        }
        if (i == 3)
        {
            elemento1->seme = FIORI;
            enqueue1(&head, &tail, elemento1);
        }
 
        for (int a = 0; a < cont2; a++) //per tutti i numeri
        {
            elemento2 = (Node*) malloc(sizeof(Node)); //allocazione dinamica memoria
            elemento2->numero = a;
            enqueue2(&head, &tail, elemento2);
        }
    }

    for (int b = 0; b < 52; b++)            //ogni carta dal fondo viene estratta 
    {
        Node *supporto; //usato per la verifica nell'if per contenere il seme estratto
        Ris *head2;  //coda e testa del nuovo mazzo
        Ris *tail2; 
        supporto = (Node*) malloc(sizeof(Node));
        head2 = (Ris*) malloc(sizeof(Ris));         //allocazione dinamica nuovo mazzo
        tail2 = (Ris*) malloc(sizeof(Ris));
        supporto = dequeue(&head, &tail);
        if (supporto->seme == CUORE || supporto->seme == QUADRI){       //per verificare se la carta estratta è una delle interessate
            enqueue3(&head2, &tail2, supporto->seme);
            enqueue4(&head2, &tail2, supporto->numero);     //si riempie il nuovo mazzo
        }
    }
    for (int n = 0; n < 26; n++)            //per stampare il nuovo mazzo (formato da 52/2 carte)
    {
        printf(dequeue);
    }

    free(elemento1);
    free(elemento2);        //si libera la memoria allocata usando free
    free(head);
    free(tail);
    /*free(tail2);
    free(head2);
    free(supporto);*/
    system("pause");
    return 0;
}

Node * dequeue(Node **head, Node **tail) {
    Node *ret = *head;

    if (is_empty(*head)) {
        return NULL;
    }
    else {
        *head = ret->next;
    }

    if (*head == NULL) {
        *tail = NULL;
    }
    return ret;
}

Ris * dequeue2(Ris **head, RIs **tail) {
    Ris *ret = *head;

    if (is_empty(*head)) {
        return NULL;
    }
    else {
        *head = ret->next;
    }

    if (*head == NULL) {
        *tail = NULL;
    }
    return ret;
}

void enqueue1(Node ** head, Node **tail, Node *element){    //enqueue per il seme del primo mazzo
    if (is_empty(*head))
    {
        *head = element->seme;
    }
    else{
        (*tail)->next = element;
    }
    *tail = element->seme;
    element->next = NULL;
}

void enqueue2(Node ** head, Node **tail, Node *element){        //enqueue per il numero del primo mazzo
    if (is_empty(*head))
    {
        *head = element->numero;
    }
    else{
        (*tail)->next = element;
    }
    *tail = element->numero;
    element->next = NULL;
}

void enqueue3(Ris ** head, Ris **tail, Node *element){        //enqueue per il numero del secondo mazzo
    if (is_empty2(*head))
    {
        *head = element->numero;
    }
    else{
        (*tail)->next = element;
    }
    *tail = element->numero;
    element->next = NULL;
}

void enqueue4(Ris ** head, Ris **tail, Node *element){    //enqueue per il seme del secondo mazzo
    if (is_empty2(*head))
    {
        *head = element->seme;
    }
    else{
        (*tail)->next = element;
    }
    *tail = element->seme;
    element->next = NULL;
}



int is_empty(Node* head)        //per il primo mazzo
{
    if (head == NULL) return 1;             
    else return 0; 
}

int is_empty1(Ris* head)           //per il secondo mazzo
{
    if (head == NULL) return 1;             
    else return 0; 
}
