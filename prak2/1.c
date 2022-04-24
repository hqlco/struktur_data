// Kenapa soal B selalu susah ^-^
// nyoba pake bruteforce dulu.. masih belum nemu ide lain^-^
// Don't give up until Friday 7 p.m.
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int arr1[1000001];
int x1 = 0;
int arr2[1000001];
int x2 = 0;
int arr3[1000001];
int x3 = 0;
int arr4[1000001];
int x4 = 0;
int arr5[1000001];
int x5 = 0;
int arr6[1000001];
int x6 = 0;
int arr7[1000001];
int x7 = 0;
int arr8[1000001];
int x8 = 0;
int HHHH;
//!
typedef struct dynamicarr_t
{
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;

// Prototipe fungsi

// Definisi fungsi

void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int *)malloc(sizeof(int) * 2);
}

bool dArray_isEmpty(DynamicArray *darray)
{
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, int value)
{
    if (darray->_size + 1 > darray->_capacity)
    {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int *)malloc(sizeof(int) * darray->_capacity);

        for (it = 0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];

        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}

void dArray_popBack(DynamicArray *darray)
{
    if (!dArray_isEmpty(darray))
        darray->_size--;
    else
        return;
}

int dArray_back(DynamicArray *darray)
{
    if (!dArray_isEmpty(darray))
        return darray->_arr[darray->_size - 1];
    else
        return 0;
}

int dArray_front(DynamicArray *darray)
{
    if (!dArray_isEmpty(darray))
        return darray->_arr[0];
    else
        return 0;
}

void dArray_setAt(DynamicArray *darray, unsigned index, int value)
{
    if (!dArray_isEmpty(darray))
    {
        if (index >= darray->_size)
            darray->_arr[darray->_size - 1] = value;
        else
            darray->_arr[index] = value;
    }
}

int dArray_getAt(DynamicArray *darray, unsigned index)
{
    if (!dArray_isEmpty(darray))
    {
        if (index >= darray->_size)
        {
            return darray->_arr[darray->_size - 1];
        }
        else
        {
            return darray->_arr[index];
        }
    }
    return -1;
}

//!
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
void __bst__inorder(BSTNode *root, DynamicArray *darray)
{
    if (root)
    {
        __bst__inorder(root->left, darray);
        dArray_pushBack(darray, root->key);
        __bst__inorder(root->right, darray);
    }
}
void __bst__postorder(BSTNode *root, DynamicArray *darray)
{
    if (root)
    {
        __bst__postorder(root->left, darray);
        __bst__postorder(root->right, darray);
        dArray_pushBack(darray, root->key);
    }
}
void __bst__preorder(BSTNode *root, DynamicArray *darray)
{
    if (root)
    {
        dArray_pushBack(darray, root->key);
        __bst__preorder(root->left, darray);
        __bst__preorder(root->right, darray);
    }
}
void __bst__inorder2(BSTNode *root, DynamicArray *darray)
{
    if (root)
    {
        __bst__inorder2(root->right, darray);
        dArray_pushBack(darray, root->key);
        __bst__inorder2(root->left, darray);
    }
}
void __bst__postorder2(BSTNode *root, DynamicArray *darray)
{
    if (root)
    {
        __bst__postorder2(root->right, darray);
        __bst__postorder2(root->left, darray);
        dArray_pushBack(darray, root->key);
    }
}
void __bst__preorder2(BSTNode *root, DynamicArray *darray)
{
    if (root)
    {
        dArray_pushBack(darray, root->key);
        __bst__preorder2(root->right, darray);
        __bst__preorder2(root->left, darray);
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
void bst_inorder(BST *bst, DynamicArray *darray)
{
    __bst__inorder(bst->_root, darray);
}
void bst_postorder(BST *bst, DynamicArray *darray)
{
    __bst__postorder(bst->_root, darray);
}
void bst_preorder(BST *bst, DynamicArray *darray)
{
    __bst__preorder(bst->_root, darray);
}
//!
void bst_inorder2(BST *bst, DynamicArray *darray)
{
    __bst__inorder2(bst->_root, darray);
}
void bst_postorder2(BST *bst, DynamicArray *darray)
{
    __bst__postorder2(bst->_root, darray);
}
void bst_preorder2(BST *bst, DynamicArray *darray)
{
    __bst__preorder2(bst->_root, darray);
}
//!

//! TAMBAHAN
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
int Finddepth(BSTNode *root)
{
    if (root == NULL)
    {
        return -1;
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
////!!!!
int height(BSTNode *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
int tinggi(BST *bst)
{
    int C = height(bst->_root);
    return C;
}
void printCurrentLevelL(BSTNode *root, int level, DynamicArray *darray)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        dArray_pushBack(darray, root->key);
        x1++;
    }
    else if (level > 1)
    {
        printCurrentLevelL(root->left, level - 1, darray);
        printCurrentLevelL(root->right, level - 1, darray);
    }
}
void printLevelOrderL(BSTNode *root, DynamicArray *darray)
{
    for (int i = 1; i <= HHHH; i++)
    {
        printCurrentLevelL(root, i, darray);
    }
}

void printCurrentLevelR(BSTNode *root, int level, DynamicArray *darray)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        dArray_pushBack(darray, root->key);
        return;
    }
    else if (level > 1)
    {
        printCurrentLevelR(root->right, level - 1, darray);
        printCurrentLevelR(root->left, level - 1, darray);
    }
    return;
}

void printLevelOrderR(BSTNode *root, DynamicArray *darray)
{
    for (int i = 1; i <= HHHH; i++)
    {
        printCurrentLevelR(root, i, darray);
    }
}
// todo
void printCurrentLevelLL(BSTNode *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        printf("%d ", root->key);
    }
    else if (level > 1)
    {
        printCurrentLevelLL(root->left, level - 1);
        printCurrentLevelLL(root->right, level - 1);
    }
}
void printLevelOrderLL(BSTNode *root)
{
    for (int i = 1; i <= HHHH; i++)
    {
        printCurrentLevelLL(root, i);
        if (i != HHHH)
        {
            printf("-> ");
        }
    }
}

void printCurrentLevelRR(BSTNode *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        printf("%d ", root->key);
    }
    else if (level > 1)
    {
        printCurrentLevelRR(root->right, level - 1);
        printCurrentLevelRR(root->left, level - 1);
    }
}

void printLevelOrderRR(BSTNode *root)
{
    for (int i = 1; i <= HHHH; i++)
    {
        printCurrentLevelRR(root, i);
        if (i != HHHH)
        {
            printf("-> ");
        }
    }
}
//!
void levelL(BST *bst, DynamicArray *darray)
{
    printLevelOrderL(bst->_root, darray);
}

void levelR(BST *bst, DynamicArray *darray)
{
    printLevelOrderR(bst->_root, darray);
}
//!!!!
void levelLL(BST *bst)
{
    printLevelOrderLL(bst->_root);
}

void levelRR(BST *bst)
{
    printLevelOrderRR(bst->_root);
}
//!
void __bst__preorderCL(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        __bst__preorderCL(root->left);
    }
}
void bst_preorderCL(BST *bst)
{
    __bst__preorderCL(bst->_root);
}

void __bst__preorderCR(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        __bst__preorderCR(root->right);
    }
}
void bst_preorderCR(BST *bst)
{
    __bst__preorderCR(bst->_root);
}

void __bst__preorderLC(BSTNode *root)
{
    if (root)
    {
        __bst__preorderLC(root->left);
        printf("%d ", root->key);
    }
}
void bst_preorderLC(BST *bst)
{
    __bst__preorderLC(bst->_root);
}
void __bst__preorderRC(BSTNode *root)
{
    if (root)
    {
        __bst__preorderRC(root->right);
        printf("%d ", root->key);
    }
}
void bst_preorderRC(BST *bst)
{
    __bst__preorderRC(bst->_root);
}
//!
void __bst__preorderCCL(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        printf("%d ", root->key);
        __bst__preorderCCL(root->left);
    }
}
void bst_preorderCCL(BST *bst)
{
    __bst__preorderCCL(bst->_root);
}

void __bst__preorderCLC(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        __bst__preorderCLC(root->left);
        printf("%d ", root->key);
    }
}
void bst_preorderCLC(BST *bst)
{
    __bst__preorderCLC(bst->_root);
}

void __bst__preorderLCC(BSTNode *root)
{
    if (root)
    {
        __bst__preorderLCC(root->left);
        printf("%d ", root->key);
        printf("%d ", root->key);
    }
}
void bst_preorderLCC(BST *bst)
{
    __bst__preorderLCC(bst->_root);
}
//!
void __bst__preorderCCR(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        printf("%d ", root->key);
        __bst__preorderCCR(root->right);
    }
}
void bst_preorderCCR(BST *bst)
{
    __bst__preorderCCR(bst->_root);
}

void __bst__preorderCRC(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        __bst__preorderCRC(root->right);
        printf("%d ", root->key);
    }
}
void bst_preorderCRC(BST *bst)
{
    __bst__preorderCRC(bst->_root);
}

void __bst__preorderRCC(BSTNode *root)
{
    if (root)
    {
        __bst__preorderRCC(root->right);
        printf("%d ", root->key);
        printf("%d ", root->key);
    }
}
void bst_preorderRCC(BST *bst)
{
    __bst__preorderRCC(bst->_root);
}
//!
void __bst__preorderCLL(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        __bst__preorderCLL(root->left);
        __bst__preorderCLL(root->left);
    }
}
void bst_preorderCLL(BST *bst)
{
    __bst__preorderCLL(bst->_root);
}

void __bst__preorderLCL(BSTNode *root)
{
    if (root)
    {
        __bst__preorderLCL(root->left);
        printf("%d ", root->key);
        __bst__preorderLCL(root->left);
    }
}
void bst_preorderLCL(BST *bst)
{
    __bst__preorderLCL(bst->_root);
}

void __bst__preorderLLC(BSTNode *root)
{
    if (root)
    {
        __bst__preorderLLC(root->left);
        __bst__preorderLLC(root->left);
        printf("%d ", root->key);
    }
}
void bst_preorderLLC(BST *bst)
{
    __bst__preorderLLC(bst->_root);
}
//!
void __bst__preorderCRR(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        __bst__preorderCRR(root->right);
        __bst__preorderCRR(root->right);
    }
}
void bst_preorderCRR(BST *bst)
{
    __bst__preorderCRR(bst->_root);
}

void __bst__preorderRCR(BSTNode *root)
{
    if (root)
    {
        __bst__preorderRCR(root->right);
        printf("%d ", root->key);
        __bst__preorderRCR(root->right);
    }
}
void bst_preorderRCR(BST *bst)
{
    __bst__preorderRCR(bst->_root);
}

void __bst__preorderRRC(BSTNode *root)
{
    if (root)
    {
        __bst__preorderRRC(root->right);
        __bst__preorderRRC(root->right);
        printf("%d ", root->key);
    }
}
void bst_preorderRRC(BST *bst)
{
    __bst__preorderRRC(bst->_root);
}
//!
void __bst__inorderLCR(BSTNode *root)
{
    if (root)
    {
        __bst__inorderLCR(root->left);
        printf("%d ", root->key);
        __bst__inorderLCR(root->right);
    }
}
void __bst__postorderLRC(BSTNode *root)
{
    if (root)
    {
        __bst__postorderLRC(root->left);
        __bst__postorderLRC(root->right);
        printf("%d ", root->key);
    }
}
void __bst__preorderCLR(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        __bst__preorderCLR(root->left);
        __bst__preorderCLR(root->right);
    }
}
void __bst__inorderRCL(BSTNode *root)
{
    if (root)
    {
        __bst__inorderRCL(root->right);
        printf("%d ", root->key);
        __bst__inorderRCL(root->left);
    }
}
void __bst__postorderRLC(BSTNode *root)
{
    if (root)
    {
        __bst__postorderRLC(root->right);
        __bst__postorderRLC(root->left);
        printf("%d ", root->key);
    }
}
void __bst__preorderCRL(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        __bst__preorderCRL(root->right);
        __bst__preorderCRL(root->left);
    }
}
void bst_inorderLCR(BST *bst)
{
    __bst__inorderLCR(bst->_root);
}
void bst_postorderLRC(BST *bst)
{
    __bst__postorderLRC(bst->_root);
}
void bst_preorderCLR(BST *bst)
{
    __bst__preorderCLR(bst->_root);
}
//!
void bst_inorderRCL(BST *bst)
{
    __bst__inorderRCL(bst->_root);
}
void bst_postorderRLC(BST *bst)
{
    __bst__postorderRLC(bst->_root);
}
void bst_preorderCRL(BST *bst)
{
    __bst__preorderCRL(bst->_root);
}
//!
typedef struct BinarySearchTree
{
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
    int val;
} bst;

typedef struct Queue
{
    bst *val;
    struct Queue *next;
} qu;

void enqueu(qu **, bst *);
bst *dequeu(qu **);
int isempty(qu *);

bst *create(bst *, int);

void inorder(bst *);
void preorder(bst *);
void postorder(bst *);
void levelorder(bst *, DynamicArray *);

int main()
{
    BST set;
    bst *root = NULL;
    bst_init(&set);
    DynamicArray myArray1;
    dArray_init(&myArray1);
    DynamicArray myArray2;
    dArray_init(&myArray2);
    DynamicArray myArray3;
    dArray_init(&myArray3);
    DynamicArray myArray4;
    dArray_init(&myArray4);
    DynamicArray myArray5;
    dArray_init(&myArray5);
    DynamicArray myArray6;
    dArray_init(&myArray6);
    DynamicArray myArray7;
    dArray_init(&myArray7);
    DynamicArray myArray8;
    dArray_init(&myArray8);
    int N;
    int tanda = 0, awal;
    int mm = 0;
    while (1)
    {
        mm++;
        scanf("%d", &N);
        if (tanda == 0)
        {
            tanda = 1;
            awal = N;
        }
        if (N == -1)
        {
            break;
        }
        bst_insert(&set, N);
        // root = create(root, N);
    }
    char kata[100];
    HHHH = tinggi(&set);
    bst_inorder(&set, &myArray1);    //*LCR
    bst_postorder(&set, &myArray2);  //*LRC
    bst_preorder(&set, &myArray3);   //*CLR
    bst_inorder2(&set, &myArray4);   //*RCL
    bst_postorder2(&set, &myArray5); //*RLC
    bst_preorder2(&set, &myArray6);  //*CRL
    levelL(&set, &myArray7);         //*LEVEL L
    if (mm < 100)
    {
        levelR(&set, &myArray8);
    }
    // levelR(&set, &myArray8);         //*LEVEL R
    // levelorder(root, &myArray8);
    while (scanf("%s", kata) != EOF)
    {
        int akan1 = 1;
        int akan2 = 1;
        int akan3 = 1;
        int akan4 = 1;
        int akan5 = 1;
        int akan6 = 1;
        int akan7 = 1;
        int akan8 = 1;
        int tanda = 0;
        if (strcmp("TRAVERSE", kata) == 0)
        {
            char nama[100];
            scanf("%[^\n]s", nama);
            if (set._root == NULL)
            {
                printf("Tidak ada Output\n");
                continue;
            }

            if (strcmp(" LEVEL L", nama) == 0)
            {
                levelLL(&set);
                printf("\n");
            }
            else if (strcmp(" LEVEL R", nama) == 0)
            {
                levelRR(&set);
                printf("\n");
            }
            else if (strcmp(" C", nama) == 0)
            {
                printf("%d\n", awal);
            }
            else if (strcmp(" C C", nama) == 0)
            {
                printf("%d %d\n", awal, awal);
            }
            else if (strcmp(" C C C", nama) == 0)
            {
                printf("%d %d %d\n", awal, awal, awal);
            }
            else if (strcmp(" L C R", nama) == 0)
            {
                bst_inorderLCR(&set);
                printf("\n");
            }
            else if (strcmp(" L R C", nama) == 0)
            {
                bst_postorderLRC(&set);
                printf("\n");
            }
            else if (strcmp(" C L R", nama) == 0)
            {
                bst_preorderCLR(&set);

                printf("\n");
            }
            else if (strcmp(" R C L", nama) == 0)
            {
                bst_inorderRCL(&set);
                printf("\n");
            }
            else if (strcmp(" R L C", nama) == 0)
            {
                bst_postorderRLC(&set);
                printf("\n");
            }
            else if (strcmp(" C R L", nama) == 0)
            {
                bst_preorderCRL(&set);
                printf("\n");
            }
            else if (strcmp(" C L", nama) == 0)
            {
                bst_preorderCL(&set);
                printf("\n");
            }
            else if (strcmp(" C R", nama) == 0)
            {
                bst_preorderCR(&set);
                printf("\n");
            }
            else if (strcmp(" L C", nama) == 0)
            {
                bst_preorderLC(&set);
                printf("\n");
            }
            else if (strcmp(" R C", nama) == 0)
            {
                bst_preorderRC(&set);
                printf("\n");
            }
            else if (strcmp(" C D", nama) == 0)
            {
                printf("%d\n", awal);
            }
            else if (strcmp(" D C", nama) == 0)
            {
                printf("%d\n", awal);
            }

            else if (strcmp(" C L D", nama) == 0)
            {
                bst_preorderCL(&set);
                printf("\n");
            }
            else if (strcmp(" C D L", nama) == 0)
            {
                bst_preorderCL(&set);
                printf("\n");
            }
            else if (strcmp(" L C D", nama) == 0)
            {
                bst_preorderLC(&set);
                printf("\n");
            }
            else if (strcmp(" L D C", nama) == 0)
            {
                bst_preorderLC(&set);
                printf("\n");
            }
            else if (strcmp(" D L C", nama) == 0)
            {
                bst_preorderLC(&set);
                printf("\n");
            }
            else if (strcmp(" D C L", nama) == 0)
            {
                bst_preorderCL(&set);
                printf("\n");
            }
            else if (strcmp(" C R D", nama) == 0)
            {
                bst_preorderCR(&set);
                printf("\n");
            }
            else if (strcmp(" C D R", nama) == 0)
            {
                bst_preorderCR(&set);
                printf("\n");
            }
            else if (strcmp(" R C D", nama) == 0)
            {
                bst_preorderRC(&set);
                printf("\n");
            }
            else if (strcmp(" R D C", nama) == 0)
            {
                bst_preorderRC(&set);
                printf("\n");
            }
            else if (strcmp(" D R C", nama) == 0)
            {
                bst_preorderRC(&set);
                printf("\n");
            }
            else if (strcmp(" D C R", nama) == 0)
            {
                bst_preorderCR(&set);
                printf("\n");
            }

            else if (strcmp(" C C L", nama) == 0)
            {
                bst_preorderCCL(&set);
                printf("\n");
            }
            else if (strcmp(" C L C", nama) == 0)
            {
                bst_preorderCLC(&set);
                printf("\n");
            }
            else if (strcmp(" L C C", nama) == 0)
            {
                bst_preorderLCC(&set);
                printf("\n");
            }
            else if (strcmp(" C C R", nama) == 0)
            {
                bst_preorderCCR(&set);
                printf("\n");
            }
            else if (strcmp(" C R C", nama) == 0)
            {
                bst_preorderCRC(&set);
                printf("\n");
            }
            else if (strcmp(" R C C", nama) == 0)
            {
                bst_preorderRCC(&set);
                printf("\n");
            }

            else if (strcmp(" C C D", nama) == 0)
            {
                printf("%d %d\n", awal, awal);
            }
            else if (strcmp(" C D C", nama) == 0)
            {
                printf("%d %d\n", awal, awal);
            }
            else if (strcmp(" D C C", nama) == 0)
            {
                printf("%d %d\n", awal, awal);
            }
            else if (strcmp(" D D C", nama) == 0)
            {
                printf("%d\n", awal);
            }
            else if (strcmp(" D C D", nama) == 0)
            {
                printf("%d\n", awal);
            }
            else if (strcmp(" C D D", nama) == 0)
            {
                printf("%d\n", awal);
            }

            else if (strcmp(" C L L", nama) == 0)
            {
                bst_preorderCLL(&set);
                printf("\n");
            }
            else if (strcmp(" L C L", nama) == 0)
            {
                bst_preorderLCL(&set);
                printf("\n");
            }
            else if (strcmp(" L L C", nama) == 0)
            {
                bst_preorderLLC(&set);
                printf("\n");
            }
            else if (strcmp(" C R R", nama) == 0)
            {
                bst_preorderCRR(&set);
                printf("\n");
            }
            else if (strcmp(" R C R", nama) == 0)
            {
                bst_preorderCRR(&set);
                printf("\n");
            }
            else if (strcmp(" R R C", nama) == 0)
            {
                bst_preorderRRC(&set);
                printf("\n");
            }
            else
            {
                printf("Tidak ada Output\n");
            }
        }
        else if (strcmp("GUESS", kata) == 0)
        {
            if (set._root == NULL)
            {
                printf("Tidak bisa ditentukan\n");
                continue;
            }
            for (int i = 0; i < x1; i++)
            {
                int jj;
                scanf("%d", &jj);
                if (dArray_getAt(&myArray1, i) != jj)
                {
                    akan1 = 0;
                }
                if (dArray_getAt(&myArray2, i) != jj)
                {
                    akan2 = 0;
                }
                if (dArray_getAt(&myArray3, i) != jj)
                {
                    akan3 = 0;
                }
                if (dArray_getAt(&myArray4, i) != jj)
                {
                    akan4 = 0;
                }
                if (dArray_getAt(&myArray5, i) != jj)
                {
                    akan5 = 0;
                }
                if (dArray_getAt(&myArray6, i) != jj)
                {
                    akan6 = 0;
                }
                if (dArray_getAt(&myArray7, i) != jj)
                {
                    akan7 = 0;
                }
                if (dArray_getAt(&myArray8, i) != jj)
                {
                    akan8 = 0;
                }
            }
            if (akan1 + akan2 + akan3 + akan4 + akan5 + akan6 + akan7 + akan8 == 1)
            {
                if (akan1 == 1)
                {
                    printf("L-C-R\n");
                    tanda = 1;
                }
                if (akan2 == 1)
                {
                    printf("L-R-C\n");
                    tanda = 1;
                }
                if (akan3 == 1)
                {
                    printf("C-L-R\n");
                    tanda = 1;
                }
                if (akan4 == 1)
                {
                    printf("R-C-L\n");
                    tanda = 1;
                }
                else if (akan5 == 1)
                {
                    printf("R-L-C\n");
                    tanda = 1;
                }
                if (akan6 == 1)
                {
                    printf("C-R-L\n");
                    tanda = 1;
                }
                if (akan7 == 1)
                {
                    printf("LEVEL L\n");
                    tanda = 1;
                }
                if (akan8 == 1)
                {
                    printf("LEVEL R\n");
                    tanda = 1;
                }
            }
            else
            {
                printf("Tidak bisa ditentukan\n");
            }
        }
    }
    /*
        bst_preorder(&set);
        for (int i = 0; i < x1; i++)
        {
            printf("%d ", arr1[i]);
        }
    */
    // sc:hq_lco
}
bst *create(bst *root, int p)
{
    bst *temp, *pre, *ptr;

    temp = (bst *)malloc(sizeof(bst));
    temp->val = p;
    temp->right = temp->left = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        ptr = root;
        while (ptr != NULL)
        {
            pre = ptr;
            if (ptr->val > p)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if (pre->val > p)
            pre->left = temp;
        else
            pre->right = temp;
    }
    return root;
}

void preorder(bst *root)
{
    if (root != NULL)
    {
        printf("%d,", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(bst *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d,", root->val);
        inorder(root->right);
    }
}

void postorder(bst *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d,", root->val);
    }
}

void levelorder(bst *root, DynamicArray *darray)
{
    qu *p = NULL;
    bst *ptr;
    enqueu(&p, root);
    while (!isempty(p))
    {
        ptr = dequeu(&p);
        // printf("%d,", ptr->val);
        dArray_pushBack(darray, ptr->val);
        if (ptr->right != NULL)
            enqueu(&p, ptr->right);
        if (ptr->left != NULL)
            enqueu(&p, ptr->left);
    }
}

void enqueu(qu **p, bst *ptr1)
{
    qu *temp, *ptr;
    temp = (qu *)malloc(sizeof(qu));
    temp->val = ptr1;
    temp->next = NULL;
    if (*p == NULL)
        *p = temp;
    else
    {
        ptr = *p;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

bst *dequeu(qu **p)
{
    bst *ptr;
    ptr = (*p)->val;
    *p = (*p)->next;
    return ptr;
}

int isempty(qu *p)
{
    if (p == NULL)
        return 1;
    else
        return 0;
}