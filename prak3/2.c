#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
/* Struktur Node */
int tanda = 0;
typedef struct pqueueNode_t
{
    char data[1000];
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t
{
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, char value[]);
void pqueue_pop(PriorityQueue *pqueue);
char *pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue)
{
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, char value[])
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode =
        (PQueueNode *)malloc(sizeof(PQueueNode));
    strcpy(newNode->data, value);
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue))
    {
        pqueue->_top = newNode;
        return;
    }

    if (strcmp(value, pqueue->_top->data) > 0)
    {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else
    {
        while (temp->next != NULL && strcmp(temp->next->data, value) > 0)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
    {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

char *pqueue_top(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else
        return 0;
}

void slist_remove(PriorityQueue *pqueue, char value[])
{
    if (!pqueue_isEmpty(pqueue))
    {
        PQueueNode *temp, *prev;
        temp = pqueue->_top;
        if (strcmp(temp->data, value) == 0)
        {
            pqueue_pop(pqueue);
            return;
        }
        while (temp != NULL && strcmp(temp->data, value) != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        prev->next = temp->next;
        free(temp);
        pqueue->_size--;
    }
}
void printElement(PriorityQueue *pqueue, int kk)
{
    PQueueNode *temp = pqueue->_top;
    while (temp != NULL && kk--)
    {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}
int main(int argc, char const *argv[])
{
    // Buat objek PriorityQueue
    PriorityQueue myPque;

    // PENTING! Jangan lupa diinisialisasi
    pqueue_init(&myPque);
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int X;
        scanf("%d", &X);
        if (X == 1)
        {
            char arr[1000];
            scanf("%s", arr);
            pqueue_push(&myPque, arr);
        }
        else if (X == 2)
        {
            char axe[1000];
            scanf("%s", axe);
            slist_remove(&myPque, axe);
        }
        else if (X == 0)
        {
            int w;
            scanf("%d", &w);
            //  scanf("%d", &tanda);
            if (!pqueue_isEmpty(&myPque))
            {
                printElement(&myPque, w);
            }
            printf("---\n");
        }
    }
}