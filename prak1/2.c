#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct pqueueNode_t
{
    int hari;
    int bulan;
    char kota[100];
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

void pqueue_push(PriorityQueue *pqueue, int hari, int bulan, char *arr)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode =
        (PQueueNode *)malloc(sizeof(PQueueNode));
    strcpy(newNode->kota, arr);
    newNode->hari = hari;
    newNode->bulan = bulan;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue))
    {
        pqueue->_top = newNode;
        return;
    }

    if (bulan < pqueue->_top->bulan)
    {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
        return;
    }
    if (bulan == pqueue->_top->bulan)
    {
        if (hari < pqueue->_top->hari)
        {
            newNode->next = pqueue->_top;
            pqueue->_top = newNode;
            return;
        }
    }

    while (temp->next != NULL)
    {
        if (bulan < temp->next->bulan)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        else if (bulan == temp->next->bulan)
        {
            if (hari <= temp->next->hari)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
        }
        temp = temp->next;
    }
    temp->next = newNode;
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
        return pqueue->_top->kota;
    else
        return 0;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    PriorityQueue myPque;
    pqueue_init(&myPque);

    for (int i = 0; i < N; i++)
    {
        char k[1000];
        int H, B;
        scanf("%s", k);
        scanf("%d %d", &H, &B);
        pqueue_push(&myPque, H, B, k);
    }
    for (int i = 0; i < M; i++)
    {
        pqueue_pop(&myPque);
    }
    if (M >= N)
    {
        printf("Projek Rumbling Berhasil\n");
    }
    else
    {
        printf("Negara selanjutnya yaitu: %s\n", pqueue_top(&myPque));
    }
}