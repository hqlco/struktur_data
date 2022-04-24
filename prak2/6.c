#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct snode_t
{
    int data, jarak;
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

void slist_pushBack(SinglyList *list, int value, int value2)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        newNode->data = value;
        newNode->jarak = value2;
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

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        return list->_head->data;
    }
    return 0;
}

int slist_front2(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        return list->_head->jarak;
    }
    return 0;
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

typedef struct bstnode_t
{
    int key, jarak;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

BSTNode *__search(BSTNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __search(bst->_root, value);
    if (temp == NULL)
        return false;
    if (temp->key == value)
        return true;
    else
        return false;
}

BSTNode *createNode(int value, int hitung)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->jarak = hitung;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *insert(BSTNode *root, int value, int hitung, SinglyList *leaf)
{
    if (root == NULL)
    {
        slist_pushBack(leaf, value, 1);
        return createNode(value, hitung);
    }
    if (value < root->key)
    {

        if (root->left == NULL)
        {
            slist_remove(leaf, root->key);
        }

        root->left = insert(root->left, value, hitung, leaf);
    }
    else if (value > root->key)
    {

        if (root->right == NULL)
        {
            slist_remove(leaf, root->key);
        }

        root->right = insert(root->right, value, hitung, leaf);
    }
    return root;
}

void bst_insert(BST *bst, int value, int hitung, SinglyList *leaf)
{
    if (!bst_find(bst, value))
    {
        bst->_root = insert(bst->_root, value, hitung, leaf);
        bst->_size++;
    }
}

int jarakk(BSTNode *root, SinglyList *SS, int k)
{
    if (root == NULL)
    {
        return 0;
    }
    slist_pushBack(SS, root->key, root->jarak);
    if (root->key == k)
    {
        return 1;
    }
    if ((root->left && jarakk(root->left, SS, k)) || (root->right && jarakk(root->right, SS, k)))
        return 1;
    slist_popBack(SS);
    return 0;
}

int temp11(BST *bst, int xx, int xy)
{
    SinglyList l1, l2;
    slist_init(&l1);
    slist_init(&l2);
    jarakk(bst->_root, &l1, xx);
    jarakk(bst->_root, &l2, xy);
    int hitung1 = 0, hitung2 = 0;
    while (!slist_isEmpty(&l1))
    {
        if (slist_front(&l1) == slist_front(&l2))
        {
            slist_popFront(&l1);
            slist_popFront(&l2);
        }
        else
        {
            hitung1 += slist_front2(&l1);
            slist_popFront(&l1);
        }
    }
    while (!slist_isEmpty(&l2))
    {
        hitung2 += slist_front2(&l2);
        slist_popFront(&l2);
    }

    return hitung1 + hitung2;
}

int solved(BST *bst, int a, SinglyList *leaf)
{
    int min = 100000000;
    SListNode *temp = leaf->_head;

    while (1)
    {
        int p = temp11(bst, a, temp->data);
        if (p < min)
            min = p;
        if (temp->next == NULL)
            break;
        temp = temp->next;
    }

    return min;
}

int main()
{
    BST bst;
    bst_init(&bst);

    SinglyList leaf;
    slist_init(&leaf);
    int n, a, b;
    scanf("%d %d", &n, &a);
    bst_insert(&bst, a, 0, &leaf);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &a, &b);
        bst_insert(&bst, a, b, &leaf);
    }

    int kk;
    scanf("%d", &kk);

    for (int i = 0; i < kk; i++)
    {

        int X;
        scanf("%d", &X);
        if (bst_find(&bst, X))
        {
            printf("%d ", solved(&bst, X, &leaf));
        }
        else
        {
            printf("0 ");
        }
    }
    printf("\n");
}
//   sc:hq_lco