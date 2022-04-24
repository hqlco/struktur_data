#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* Struktur Node */

typedef struct dnode_t
{
    int data;
    struct dnode_t *next, *prev;
} DListNode;

/* Struktur ADT SinglyList */

typedef struct Dlist_t
{
    unsigned _size;
    DListNode *_head, *_tail;
} DoublyList;

/* DAFTAR FUNGSI YANG TERSEDIA */

/* Function definition below */

void dlist_init(DoublyList *list)
{
    list->_head = list->_tail = NULL;
    list->_size = 0;
}

bool dlist_isEmpty(DoublyList *list)
{
    return (list->_head == NULL && list->_tail == NULL);
}

void dlist_popFront(DoublyList *list)
{
    if (!dlist_isEmpty(list))
    {
        DListNode *temp = list->_head;
        if (list->_head == list->_tail)
        {
            list->_head = NULL;
            list->_tail = NULL;
            free(temp);
        }
        else
        {
            list->_head = list->_head->next;
            list->_head->prev = NULL;
            free(temp);
        }
        list->_size--;
    }
    return;
}

void dlist_pushBack(DoublyList *list, int value)
{
    DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (newNode)
    {
        list->_size++;
        if (dlist_isEmpty(list))
        {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        list->_tail->next = newNode;
        newNode->prev = list->_tail;
        list->_tail = newNode;
    }
}

void dlist_popBack(DoublyList *list)
{
    if (!dlist_isEmpty(list))
    {
        DListNode *temp;
        if (list->_head == list->_tail)
        {
            temp = list->_head;
            list->_head = NULL;
            list->_tail = NULL;
            free(temp);
        }
        else
        {
            temp = list->_tail;
            list->_tail = list->_tail->prev;
            list->_tail->next = NULL;
            free(temp);
        }
        list->_size--;
    }
    return;
}

void printElement(DoublyList *list)
{
    DListNode *temp = (DListNode *)malloc(sizeof(DListNode));
    temp = list->_head;
    if (temp == NULL)
    {
        printf("Void");
        list->_size = 0;
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void acak(DoublyList *list)
{
    while (!dlist_isEmpty(list))
    {
        DoublyList list1, list2;
        dlist_init(&list1);
        dlist_init(&list2);
        DListNode *temp = list->_head;
        if (list->_size == 1)
        {
            return;
        }
        else if (list->_size % 2 != 0)
        {
            int i;
            for (i = 0; i < (list->_size / 2 + 1); i++)
            {
                temp = temp->next;
            }
            list1._head = list->_head;
            list1._tail = temp->prev;
            temp->prev->next = NULL;
            list1._size = list->_size / 2 + 1;
            list2._head = temp;
            list2._tail = list->_tail;
            list2._size = list->_size / 2;
            acak(&list1);
            acak(&list2);
            temp = list1._head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = list2._head;
            list2._head->prev = temp;
            list1._size += list2._size;
            list->_head = list1._head;
            list->_tail = list2._tail;
            return;
        }
        else if ((list->_size & (list->_size - 1)) != 0 && list->_size % 2 == 0)
        {
            int i;
            for (i = 0; i < list->_size / 2; i++)
            {
                temp = temp->next;
            }
            list2._head = list->_head;
            list2._tail = temp->prev;
            temp->prev->next = NULL;
            list2._size = list->_size / 2;
            list1._head = temp;
            list1._tail = list->_tail;
            list1._size = list->_size / 2;
            acak(&list1);
            acak(&list2);
            temp = list1._head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = list2._head;
            list2._head->prev = temp;
            list1._size += list2._size;
            list->_head = list1._head;
            list->_tail = list2._tail;
            return;
        }
        if ((list->_size & (list->_size - 1)) == 0 && list->_size != 0)
        {
            int i;
            for (i = 0; i < list->_size / 2; i++)
            {
                temp = temp->next;
            }
            list2._head = list->_head;
            list2._tail = temp->prev;
            temp->prev->next = NULL;
            list2._size = list->_size / 2;
            list1._head = temp;
            list1._tail = list->_tail;
            list1._size = list->_size / 2;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = list2._head;
            list2._head->prev = temp;
            list->_head = list1._head;
            list->_tail = list2._tail;
            list->_size = list1._size * 2;
            return;
        }
        return;
    }
}

int main()
{

    DoublyList myList;
    dlist_init(&myList);
    // int itung = 0;
    while (1)
    {
        char tanda[1000];
        scanf("%s", tanda);
        if (strcmp(tanda, "PUS") == 0)
        {
            int i, j, k, l;
            scanf("%d %d %d %d", &i, &j, &k, &l);
            for (int q = 1; q <= j; q++)
            {
                int hasil = i + (q - 1) * k + ((q - 1) * (q - 2) * l) / 2;
                dlist_pushBack(&myList, hasil);
            }
            printElement(&myList);
            printf("\n");
        }
        else if (strcmp(tanda, "CLB") == 0)
        {
            int n;
            scanf("%d", &n);
            if (myList._size == 0)
            {
                printf("Void\n");
                continue;
                ;
            }
            for (int i = 0; i < n; i++)
            {
                dlist_popBack(&myList);
            }
            printElement(&myList);
            printf("\n");
        }
        else if (strcmp(tanda, "CLF") == 0)
        {
            int n;
            scanf("%d", &n);
            if (myList._size == 0)
            {
                printf("Void\n");
                continue;
                ;
            }

            for (int i = 0; i < n; i++)
            {
                dlist_popFront(&myList);
            }
            printElement(&myList);
            printf("\n");
        }
        else if (strcmp(tanda, "AMI") == 0)
        {
            acak(&myList);
            printElement(&myList);
            printf("\n");
        }
        else if (strcmp(tanda, "END") == 0)
        {
            // assert(0 <= itung && itung <= 10000);
            return 0;
        }
        else
        {
            printf("Dummy\n");
        }

        // itung++;
    }
}
/*
typedef struct snode_t
{
    unsigned long long data;
    struct snode_t *next;
} SListNode;

typedef struct slist_t
{
    unsigned _size;
    SListNode *_head;
} SinglyList;

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
        newNode->data = value;

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
    return;
}

void slist_pushBack(SinglyList *list, unsigned long long value)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        newNode->data = value;
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
    return;
}

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
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

void slist_removeAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list))
    {
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

        if (temp->data == value)
        {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->data != value)
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
        return list->_head->data;
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
        return temp->data;
    }
    return 0;
}

int slist_getAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list))
    {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index)
        {
            temp = temp->next;
            _i++;
        }
        return temp->data;
    }
    return 0;
}
void printElement(SinglyList *list)
{
    SListNode *temp = list->_head;
    if (temp == NULL)
    {
        printf("Void");
        list->_size = 0;
        return;
    }
    while (temp != NULL)
    {
        printf("%llu ", temp->data);
        temp = temp->next;
    }
}

void acak(SinglyList *list)
{
    SinglyList list1, list2;
    slist_init(&list1);
    slist_init(&list2);
    SListNode *temp = list->_head;
    SListNode *prev, *ptr;
    if (list->_size == 1)
    {
        return;
    }
    else if (list->_size % 2 != 0)
    {
        int i;
        for (i = 0; i < (list->_size / 2 + 1); i++)
        {
            prev = temp;
            temp = temp->next;
        }
        list1._head = list->_head;
        prev->next = NULL;
        list1._size = list->_size / 2 + 1;
        list2._head = temp;
        list2._size = list->_size / 2;
        acak(&list1);
        acak(&list2);
        temp = list1._head;
        prev = list2._head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = prev;
        list1._size += list2._size;
        list->_head = list1._head;
        return;
    }
    else if ((list->_size & (list->_size - 1)) != 0 && list->_size % 2 == 0)
    {
        int i;
        for (i = 0; i < list->_size / 2; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        list2._head = list->_head;
        prev->next = NULL;
        list2._size = list->_size / 2;
        list1._head = temp;
        list1._size = list->_size / 2;
        acak(&list1);
        acak(&list2);
        temp = list1._head;
        prev = list2._head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = prev;
        list1._size += list2._size;
        list->_head = list1._head;
        return;
    }
    if ((list->_size & (list->_size - 1)) == 0 && list->_size != 0)
    {
        int i;
        for (i = 0; i < list->_size / 2; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        list2._head = list->_head;
        prev->next = NULL;
        list2._size = list->_size / 2;
        list->_head = temp;
        list->_size = list->_size / 2;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = list2._head;
        list->_size = list->_size * 2;
        return;
    }
    return;
}

int main()
{

    SinglyList myList;
    slist_init(&myList);
    int itung = 0;
    while (1)
    {
        char tanda[10001];
        scanf("%s", tanda);
        if (strcmp(tanda, "PUS") == 0)
        {
            int i, j, k, l;
            scanf("%d %d %d %d", &i, &j, &k, &l);
            assert(0 <= i && i <= 1000);
            assert(0 <= j && j <= 1000);
            assert(0 <= k && k <= 1000);
            assert(0 <= l && l <= 1000);
            for (int q = 1; q <= j; q++)
            {
                unsigned long long hasil = i + (q - 1) * k + ((q - 1) * (q - 2) * l) / 2;
                // slist_pushFront(&myList, hasil);
                slist_pushBack(&myList, hasil);
            }
            printElement(&myList);
            printf("\n");
        }
        else if (strcmp(tanda, "CLB") == 0)
        {
            int n;
            scanf("%d", &n);
            assert(0 <= n && n <= 100000);
            for (int i = 0; i < n; i++)
            {
                slist_popBack(&myList);
            }
            printElement(&myList);
            printf("\n");
        }
        else if (strcmp(tanda, "CLF") == 0)
        {
            int n;
            scanf("%d", &n);
            assert(0 <= n && n <= 100000);
            for (int i = 0; i < n; i++)
            {
                slist_popFront(&myList);
            }
            printElement(&myList);
            printf("\n");
        }
        else if (strcmp(tanda, "AMI") == 0)
        {
            acak(&myList);
            printElement(&myList);
            printf("\n");
        }
        else if (strcmp(tanda, "END") == 0)
        {
            assert(1 <= itung && itung <= 10000);
            return 0;
        }
        else
        {
            printf("Dummy\n");
        }
        itung++;
    }
}
*/