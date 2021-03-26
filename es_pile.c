#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4

typedef struct nodo {
    char valore;
    struct nodo* next;
}Nodo;

void push(Nodo** head, Nodo* elemento);
int is_empty(Nodo* head);
Nodo* pop(Nodo** head);

int main()
{
    Nodo *head;
    Nodo *elemento;
    head = (Nodo*) malloc(sizeof(Nodo));
    int cont = 0;
    char stringa[MAX];
    printf("inserire un numero: \n");
    scanf("%s", stringa);
    cont = strlen(stringa);
    for(int i = 0; i<cont; i++)
    {
        elemento->valore = *(stringa+cont);
        printf("%c", elemento->valore);
        push(&head, elemento);
    }
    for (int a = 0; a < cont; a++)
    {
        printf("%c", pop(&head)->valore);
    }
    system("pause");
    return 0;
}

void push(Nodo** head, Nodo* elemento)      //aggiunge un elemento alla pila
{
    if(is_empty(*head)){
        *head = elemento;
        elemento->next = NULL;
    }
    else
    {
        elemento->next = *head;         //elemento punta alla testa
        *head = elemento;               //testa diventa l'elemento
    }
}

Nodo* pop(Nodo** head){
    Nodo* ret = *head;
    if (is_empty(*head))
    {
        return NULL;
    }
    else
    {
        *head = ret->next;
    }
    return ret;
}

int is_empty(Nodo* head)
{
    if (head == NULL) return 1;             //per vedere se la pila è vuota
    else return 0; 
}