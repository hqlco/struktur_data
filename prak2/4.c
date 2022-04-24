#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct bstnode_t
{
    int key;
    struct bstnode_t
        *left,
        *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;
//! queue
typedef struct queueNode_t
{
    int data;
    struct queueNode_t *next;
} QueueNode;
typedef struct queue_t
{
    QueueNode *_front,
        *_rear;
    unsigned _size;
} Queue;
void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}
bool queue_isEmpty(Queue *queue)
{
    return (queue->_front == NULL && queue->_rear == NULL);
}
void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode)
    {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (queue_isEmpty(queue))
            queue->_front = queue->_rear = newNode;
        else
        {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}
void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue))
    {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);

        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}
int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue))
    {
        return (queue->_front->data);
    }
    return (int)0;
}
int queue_size(Queue *queue)
{
    return queue->_size;
}

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions,
 * unless you need to modify or you know how these functions work.
 */
BSTNode *__bst__createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BSTNode *__bst__insert(BSTNode *root, int value)
{
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);

    return root;
}
BSTNode *__bst__search(BSTNode *root, int value)
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
BSTNode *__bst__findMinNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}
BSTNode *__bst__remove(BSTNode *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value > root->key)
        root->right = __bst__remove(root->right, value);
    else if (value < root->key)
        root->left = __bst__remove(root->left, value);
    else
    {

        if (root->left == NULL)
        {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL)
        {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key = temp->key;
        root->right = __bst__remove(root->right, temp->key);
    }
    return root;
}
int cari(BSTNode *root, int n1, int n2)
{
    while (root != NULL)
    {

        if (root->key > n1 && root->key > n2)
            root = root->left;

        else if (root->key < n1 && root->key < n2)
            root = root->right;

        else
            break;
    }
    return root->key;
}
void __bst__inorder(BSTNode *root)
{
    if (root)
    {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}
void __bst__postorder(BSTNode *root)
{
    if (root)
    {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}
void __bst__preorder(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

// TODO AKSES DI MAIN
void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}
bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}
bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}
void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}
void bst_remove(BST *bst, int value)
{
    if (bst_find(bst, value))
    {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}
void bst_inorder(BST *bst)
{
    __bst__inorder(bst->_root);
}
void bst_postorder(BST *bst)
{
    __bst__postorder(bst->_root);
}
void bst_preorder(BST *bst)
{
    __bst__preorder(bst->_root);
}
int bst_insert2(BST *bst, int value1, int value2)
{

    int WW = cari(bst->_root, value1, value2);
    return WW;
}
//! TAMBAHAN
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int main()
{
    BST set;
    bst_init(&set);
    /*
    bst_insert(&set, 15);
    bst_insert(&set, 6);
    bst_insert(&set, 20);
    bst_insert(&set, 2);
    bst_insert(&set, 7);
    bst_insert(&set, 16);
    bst_insert(&set, 25);
    bst_insert(&set, 22);
    bst_insert(&set, 27);
    int number;
    scanf("%d", &number);
    if (bst_find(&set, number))
    {
        printf("ada\n");
    }
    else
    {
        printf("tidak ada\n");
    }
    printf("%d\n", find_depth(&set));
    printf("%d\n", find_max(&set));
    printf("%d\n", find_min(&set));
    return 0;
    */

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int X;
        scanf("%d", &X);
        if (X == 1)
        {
            int a;
            scanf("%d", &a);
            bst_insert(&set, a);
        }
        else if (X == 2)
        {
            int x1, x2;
            scanf("%d %d", &x1, &x2);
            if (!bst_find(&set, x1))
            {
                printf("Data tidak valid.\n");
                continue;
            }
            if (!bst_find(&set, x2))
            {
                printf("Data tidak valid.\n");
                continue;
            }
            int hasil = bst_insert2(&set, x1, x2);
            printf("%d\n", hasil);
        }
        else
        {
            printf("Input tidak valid.\n");
        }
    }

    // sc:hq_lco
}