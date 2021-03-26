#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int valore;
    struct Node* next;
}Node;

void enqueue(struct queue_node **head, struct queue_node *element);
struct queue_node * dequeue(struct queue_node head, struct Queue_node tail);


int main()
{
    char scelta;    
    struct Node* head = NULL;
    struct Node* tail = NULL;
    struct Node* elemento;
    int cont = 0;
    do
    {
        elemento = (struct Node*) malloc(sizeof(struct Node));
        printf("inserire un numero: \n");
        scanf("%d", &element->valore);
        enqueue(&head, &tail, elemento);
        do
        {
            printf("inserire s per inserire un altro elemento o n per fermarsi: \n");
            scanf("%c", &scelta)
        } while (scelta != 's' && scelta != 'n');
        cont++;
    } while (scelta == 's');

    while(cont == 0){
        dequeue(head, tail);
        cont--;
    }
    system("pause");
    return 0;
}


struct queue_node * dequeue(struct Node **head, struct Node **tail) {
    struct Node *ret = *head;

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

void enqueue(struct Node **head, struct Node *element){
    if(is_empty(*head))
    {
        *head = element;
    }
    else
    {
        (*tail)->next = element;
    }
    *tail = element;
    element->next = NULL;
} 

int is_empty(Node* head)
{
    if (head == NULL) return 1;             
    else return 0; 
}