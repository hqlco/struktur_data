#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */
int haram;
int akan;
typedef struct snode_t
{
    int cek;
    char kata[1000];
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t
{
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* DAFTAR FUNGSI YANG TERSEDIA */

/* Function definition below */

void slist_init(SinglyList *list)
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list)
{
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        newNode->cek = value;

        if (slist_isEmpty(list))
            newNode->next = NULL;
        else
            newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, int value, char *arr)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        newNode->cek = value;
        strcpy(newNode->kata, arr);
        newNode->next = NULL;
        if (slist_isEmpty(list))
            list->_head = newNode;
        else
        {
            SListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL)
        {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL)
        {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}
/*
void slist_insertAt(SinglyList *list, int index, int value)
{

    if (slist_isEmpty(list) || index >= list->_size)
    {
        slist_pushBack(list, value);
        return;
    }
    else if (index == 0 || index < 0)
    {
        slist_pushFront(list, value);
        return;
    }
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index - 1)
        {
            temp = temp->next;
            _i++;
        }
        newNode->cek = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}
*/

void slist_removeAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list))
    {

        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size)
        {
            slist_popBack(list);
            return;
        }
        else if (index == 0 || index < 0)
        {
            slist_popFront(list);
            return;
        }

        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index - 1)
        {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

void slist_remove(SinglyList *list, int value)
{
    if (!slist_isEmpty(list))
    {
        SListNode *temp, *prev;
        temp = list->_head;
        if (temp->cek == value)
        {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->cek != value)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        return list->_head->cek;
    }
    return 0;
}

int slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        SListNode *temp = list->_head;
        while (temp->next != NULL)
            temp = temp->next;
        return temp->cek;
    }
    return 0;
}

void slist_getAt(SinglyList *list, int cek, int index)
{
    haram = 0;
    akan = 0;
    if (!slist_isEmpty(list))
    {
        SListNode *p;
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp != NULL)
        {
            haram++;
            if (temp->cek == cek && _i < index)
            {
                _i++;
                if (_i == index)
                {
                    printf("%s\n", temp->kata);
                    return;
                }
            }
            temp = temp->next;
        }
        if (_i != index)
        {
            akan = 1;
            printf("Mending gacha Ganyu\n");
            return;
        }
    }
    return;
}

int main()
{
    SinglyList myList;
    slist_init(&myList);
    int cek = 1;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int X;
        scanf("%d", &X);
        if (X == 1)
        {
            int n;
            scanf("%d", &n);
            for (int j = 0; j < n; j++)
            {
                char arrr[1000];
                scanf("%s", arrr);
                slist_pushBack(&myList, cek, arrr);
            }
            cek++;
        }
        else if (X == 2)
        {
            int n, m;
            scanf("%d %d", &n, &m);
            // printf("%d\n",haram);
            slist_getAt(&myList, n, m);
            if (!akan)
            {
                slist_removeAt(&myList, haram - 1);
            }
            // slist_removeAt(&myList, haram-1);
        }
    }
}