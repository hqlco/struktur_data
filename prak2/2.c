#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int akan = 0;
int arr1[10001];
int arr2[10001];
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
int __bst__preorder(BSTNode *root, int data)
{
    if (root)
    {
        int x = root->key + root->left->key + root->right->key;
        if (x == data)
        {
            return 1;
            akan = 1;
        }
        if (__bst__preorder(root->left, data))
        {
            return 1;
            akan = 1;
        }
        if (__bst__preorder(root->right, data))
        {
            return 1;
            akan = 1;
        }
    }
    return 0;
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
void bst_preorder(BST *bst, int data)
{
    if (__bst__preorder(bst->_root, data) == 1)
    {
        printf("%d | | Pintu terbuka! Lanjut eksplorasi.\n", data);
        return;
    }
    if (akan == 0)
    {
        printf("%d >< Tidak ditemukan kombinasi yang tepat! Retreat.\n", data);
    }
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
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}
int Finddepth(BSTNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (max(Finddepth(root->left), Finddepth(root->right)) + 1);
}
int Findmin(BSTNode *root)
{
    if (root == NULL)
    {
        printf("EROR\n");
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->key;
    }
    return Findmin(root->left);
}
int Findmax(BSTNode *root)
{
    if (root == NULL)
    {
        printf("EROR\n");
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->key;
    }
    return Findmax(root->right);
}
int find_min(BST *bst)
{
    int number = Findmin(bst->_root);
    return number;
}
int find_max(BST *bst)
{
    int number = Findmax(bst->_root);
    return number;
}
int find_depth(BST *bst)
{
    int number = Finddepth(bst->_root);
    return number;
}
void funlargest(BSTNode *root, int x)
{
    if (root == NULL)
    {
        return;
    }
    if (x == 0)
    {
        arr1[0] = root->key;
        arr2[0] = root->key;
    }
    else
    {
        arr1[x] = max(arr1[x], root->key);
        arr2[x] = min(arr2[x], root->key);
    }
    funlargest(root->left, x + 1);
    funlargest(root->right, x + 1);
}
void ff(BST *bst, int x)
{
    funlargest(bst->_root, x);
}
int main()
{
    for (int i = 0; i < 10001; i++)
    {
        arr2[i] = 1000001;
    }

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
        int a;
        scanf("%d", &a);
        bst_insert(&set, a);
    }
    int KK = find_depth(&set);
    ff(&set, 0);
    if (KK % 2 == 0)
    {
        for (int i = KK - 1; i >= 0; i--)
        {
            int nn = i + 1;
            if (nn % 2 == 1)
            {
                printf("%d ", arr1[i]);
            }
            else
            {
                printf("%d ", arr2[i]);
            }
        }
    }
    else
    {
        for (int i = KK - 1; i >= 0; i--)
        {
            int nn = i + 1;
            if (nn % 2 == 0)
            {
                printf("%d ", arr1[i]);
            }
            else
            {
                printf("%d ", arr2[i]);
            }
        }
    }
    printf("\n");
    /*
    for (int i = KK - 1; i >= 0; i--)
    {
        int nn = i + 1;
        printf("%d ", arr1[i]);
        // printf("%d ", arr2[i]);
    }
*/
    // int k;
    // scanf("%d", &k);
    //  bst_preorder(&set, k);
    //   sc:hq_lco
}