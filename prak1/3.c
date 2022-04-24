#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct snode_t
{
    int data1;
    int data2;
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

void slist_pushFront(SinglyList *list, int value1, int value2)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        newNode->data1 = value1;
        newNode->data2 = value2;
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

void slist_pushBack(SinglyList *list, int value1, int value2)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        newNode->data1 = value1;
        newNode->data2 = value2;
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
int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        return list->_head->data1;
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
        return temp->data1;
    }
    return 0;
}

int slist_getAt1(SinglyList *list, int index)
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
        return temp->data1;
    }
    return 0;
}
int slist_getAt2(SinglyList *list, int index)
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
        return temp->data2;
    }
    return 0;
}
int main()
{
    SinglyList myList;
    slist_init(&myList);
    int i = 0;
    while (1)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == -1 && b != -1)
        {
            if (b > i - 1)
            {
                printf("Out of range\n");
            }
            else
            {
                SinglyList myList3;
                slist_init(&myList3);
                int A = slist_getAt1(&myList, b);
                int B = slist_getAt2(&myList, b);
                int tanda = 0;
                printf("%d %d -> ", A, B);
                if (A == 0)
                {
                    printf("0\n");
                }
                else
                {
                    if (B == 1)
                    {
                        for (int j = 0; j < A; j++)
                        {
                            if (j == 0)
                            {
                                printf("0");
                            }
                            else
                            {
                                printf("-0");
                            }
                        }
                        printf("\n");
                    }
                    else
                    {
                        while (A)
                        {
                            int temp = A % B;
                            A = A / B;
                            slist_pushFront(&myList3, temp, 1);
                        }
                        while (!slist_isEmpty(&myList3))
                        {
                            if (tanda == 0)
                            {
                                printf("%d", slist_front(&myList3));
                            }
                            else
                            {
                                printf("-%d", slist_front(&myList3));
                            }
                            slist_popFront(&myList3);
                            tanda++;
                        }
                        printf("\n");
                    }
                }
            }
        }
        else if (a == -1 && b == -1)
        {
            return 0;
        }
        else
        {
            SinglyList myList2;
            slist_init(&myList2);
            slist_pushBack(&myList, a, b);
            if (b == 1)
            {
                printf("Ya\n");
            }
            else
            {
                int cek = 0;
                while (a)
                {
                    int temp = a % b;
                    slist_pushBack(&myList2, temp, 1);
                    a = a / b;
                }
                while (!slist_isEmpty(&myList2))
                {
                    int X = slist_front(&myList2);
                    int Y = slist_back(&myList2);
                    if (X != Y)
                    {
                        cek = 1;
                        printf("Tidak\n");
                        break;
                    }
                    slist_popBack(&myList2);
                    slist_popFront(&myList2);
                }
                if (!cek)
                {
                    printf("Ya\n");
                }
            }
            i++;
        }
    }
}