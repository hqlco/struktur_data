#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// DENGAN STRUKDAT
typedef struct snode_t
{
    char fn[100];
    char ln[100];
    int a, index;
    float b;
    struct snode_t *next;
} SListNode;

typedef struct slist_t
{
    unsigned _size;
    SListNode *_head;
} SinglyList;

bool slist_isEmpty(SinglyList *list)
{
    return (list->_head == NULL);
}

void slist_init(SinglyList *list)
{
    list->_head = NULL;
    list->_size = 0;
}

void Add(SinglyList *list, char *fname, char *lname, int umur, float bmi, int _i)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        strcpy(newNode->fn, fname);
        strcpy(newNode->ln, lname);
        newNode->a = umur;
        newNode->b = bmi;
        newNode->index = _i;
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

    printf("Data added successfully\n");
}

void Change(SinglyList *list, char *fname, char *lname, int umur, float bmi, int _i)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));

    strcpy(newNode->fn, fname);
    strcpy(newNode->ln, lname);
    newNode->a = umur;
    newNode->b = bmi;
    newNode->index = _i;
    newNode->next = NULL;

    SListNode *temp = list->_head;
    SListNode *prev = temp;

    if (_i == 0)
    {
        newNode->next = temp->next;
        list->_head = newNode;
        free(temp);
    }

    else
    {
        int cek = 0;
        while (temp != NULL && cek < _i)
        {
            prev = temp;
            temp = temp->next;
            cek++;
        }
        prev->next = newNode;
        newNode->next = temp->next;
        free(temp);
    }

    printf("Data changed successfully\n");
}

void Print(SinglyList *list, int cek)
{
    SListNode *temp = list->_head;
    int p = 0;

    while (temp != NULL && p < cek)
    {
        printf("%d. %s, %s %d %.2f\n", (temp->index) + 1, temp->ln, temp->fn, temp->a, temp->b);
        temp = temp->next;
        p++;
    }
}

int main()
{
    SinglyList myList;
    slist_init(&myList);
    int n = 0;
    char first[100], last[100];
    int umur, i;
    float berat, tinggi, bmi;
    char arr[100];
    while (scanf("%s", arr) != EOF)
    {
        if (strcmp(arr, "ADD") == 0)
        {
            scanf("%s %s %d %f %f", first, last, &umur, &berat, &tinggi);
            bmi = berat / pow((tinggi / 100), 2);
            i = n;
            Add(&myList, first, last, umur, bmi, i);
            n++;
        }
        else if (strcmp(arr, "CHG") == 0)
        {
            scanf("%s %s %d %f %f %d", first, last, &umur, &berat, &tinggi, &i);
            bmi = berat / pow((tinggi / 100), 2);
            Change(&myList, first, last, umur, bmi, i);
        }
        else if (strcmp(arr, "PRT") == 0)
        {
            Print(&myList, n);
        }
    }
    return 0;
}