// saya sudah menyerah wkwkwk
// saya lebih suka soal if else karena itu mtk banget daripada soal ini yang CP banget
// ^_^ https://lichess.org/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int hitung;
int hasil, akan;
int arry[200001];
int xxx;
typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left, *right;
    int height;
} AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
} AVL;
typedef struct pqueueNode_t
{
    int data;
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
void pqueue_push(PriorityQueue *pqueue, int value);
void pqueue_pop(PriorityQueue *pqueue);
int pqueue_top(PriorityQueue *pqueue);

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

void pqueue_push(PriorityQueue *pqueue, int value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode =
        (PQueueNode *)malloc(sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue))
    {
        pqueue->_top = newNode;
        return;
    }

    if (value < pqueue->_top->data)
    {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else
    {
        while (temp->next != NULL &&
               temp->next->data < value)
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

int pqueue_top(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else
        return 0;
}
AVLNode *_avl_createNode(int value)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode *_search(AVLNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int _max(int a, int b)
{
    return (a > b) ? a : b;
}

AVLNode *_rightRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left),
                             _getHeight(pivotNode->right)) +
                        1;
    newParrent->height = _max(_getHeight(newParrent->left),
                              _getHeight(newParrent->right)) +
                         1;

    return newParrent;
}

AVLNode *_leftRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left),
                             _getHeight(pivotNode->right)) +
                        1;
    newParrent->height = _max(_getHeight(newParrent->left),
                              _getHeight(newParrent->right)) +
                         1;

    return newParrent;
}

AVLNode *_leftCaseRotate(AVLNode *node)
{
    return _rightRotate(node);
}

AVLNode *_rightCaseRotate(AVLNode *node)
{
    return _leftRotate(node);
}

AVLNode *_leftRightCaseRotate(AVLNode *node)
{
    node->left = _leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode *_rightLeftCaseRotate(AVLNode *node)
{
    node->right = _rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

AVLNode *_insert_AVL(AVL *avl, AVLNode *node, int value)
{

    if (node == NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if (value < node->data)
        node->left = _insert_AVL(avl, node->left, value);
    else if (value > node->data)
        node->right = _insert_AVL(avl, node->right, value);

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

    int balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 && value < node->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if (balanceFactor > 1 && value > node->left->data) //
        return _leftRightCaseRotate(node);
    if (balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if (balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);

    return node;
}

AVLNode *_findMinNode(AVLNode *node)
{
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode *_remove_AVL(AVLNode *node, int value)
{
    if (node == NULL)
        return node;
    if (value > node->data)
        node->right = _remove_AVL(node->right, value);
    else if (value < node->data)
        node->left = _remove_AVL(node->left, value);
    else
    {
        AVLNode *temp;
        if ((node->left == NULL) || (node->right == NULL))
        {
            temp = NULL;
            if (node->left == NULL)
                temp = node->right;
            else if (node->right == NULL)
                temp = node->left;

            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;

            free(temp);
        }
        else
        {
            temp = _findMinNode(node->right);
            node->data = temp->data;
            node->right = _remove_AVL(node->right, temp->data);
        }
    }

    if (node == NULL)
        return node;

    node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

    int balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
        return _leftCaseRotate(node);

    if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
        return _leftRightCaseRotate(node);

    if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
        return _rightCaseRotate(node);

    if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
        return _rightLeftCaseRotate(node);

    return node;
}

void avl_init(AVL *avl)
{
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl)
{
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int value)
{
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl, int value)
{
    if (!avl_find(avl, value))
    {
        avl->_root = _insert_AVL(avl, avl->_root, value);
        avl->_size++;
    }
}

void avl_remove(AVL *avl, int value)
{
    if (avl_find(avl, value))
    {
        avl->_root = _remove_AVL(avl->_root, value);
        avl->_size--;
    }
}

void preorder(AVLNode *root, int lk)
{
    if (root)
    {
        arry[xxx] = root->data;
        xxx++;
        preorder(root->right, lk);
        preorder(root->left, lk);
    }
}
void bst_preorder(AVL *avl, int qw)
{
    xxx = 0;
    preorder(avl->_root, qw);
}
int height(AVLNode *root)
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
void printCurrentLevelRR(AVLNode *root, int level, int ww)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        hitung++;
        if (root->data == ww)
        {
            hasil = hitung;
            akan = 1;
            return;
        }
    }
    else if (level > 1)
    {
        printCurrentLevelRR(root->right, level - 1, ww);
        printCurrentLevelRR(root->left, level - 1, ww);
    }
    return;
}
void printLevelOrderR(AVLNode *root, int tt)
{
    int h = height(root);
    int i;
    hitung = 0;
    akan = 0;
    for (i = 1; i <= h; i++)
    {
        printCurrentLevelRR(root, i, tt);
        if (akan == 1)
        {
            return;
        }
    }
}
void levelR(AVL *avl, int aa)
{
    printLevelOrderR(avl->_root, aa);
}
void solved(AVLNode *root, int col)
{
    if (root == NULL)
    {
        return;
    }
    solved(root->left, col - 1);
    arry[col] += root->data;
    solved(root->right, col + 1);
    return;
}
int sibling(AVLNode *root, int side)
{
    int hasil;
    if (side == 1 && root->right != NULL)
    {
        hasil = root->right->data;
    }
    else if (side == 0 && root->left != NULL)
    {
        hasil = root->left->data;
    }
    else
    {
        hasil = 0;
    }
    return hasil;
}

void solved1(AVLNode *root, int num)
{
    if ((root->left != NULL && root->left->data == num) || (root->right != NULL && root->right->data == num))
    {
        printf("%d\n", root->data);
        return;
    }
    int sib;
    AVLNode *temp = NULL;
    while ((root->left != NULL && root->left->data != num) && (root->left != NULL && root->right->data != num))
    {
        if (num < root->data)
        {
            temp = root;
            root = root->left;
        }
        else if (num > root->data)
        {
            temp = root;
            root = root->right;
        }
    }
    if (temp->left != NULL && temp->left == root)
    {
        sib = sibling(temp, 1);
        printf("%d\n", abs(root->data - sib));
        return;
    }
    if (temp->right != NULL && temp->right == root)
    {
        sib = sibling(temp, 0);
        printf("%d\n", abs(root->data - sib));
        return;
    }
}
void SS(AVL *avl, int kkk)
{
    solved1(avl->_root, kkk);
}
void printkdistanceNodeDown(AVLNode *root, int k, PriorityQueue *pqueue)
{

    if (root == NULL || k < 0)
        return;

    if (k == 0)
    {
        pqueue_push(pqueue, root->data);
        return;
    }

    printkdistanceNodeDown(root->left, k - 1, pqueue);
    printkdistanceNodeDown(root->right, k - 1, pqueue);
}

int printkdistanceNode(AVLNode *root, int target, int k, PriorityQueue *pqueue)
{

    if (root == NULL)
        return -1;

    if (root->data == target)
    {
        printkdistanceNodeDown(root, k, pqueue);
        return 0;
    }

    int dl = printkdistanceNode(root->left, target, k, pqueue);

    if (dl != -1)
    {

        if (dl + 1 == k)
            pqueue_push(pqueue, root->data);

        else
            printkdistanceNodeDown(root->right, k - dl - 2, pqueue);

        return 1 + dl;
    }

    int dr = printkdistanceNode(root->right, target, k, pqueue);
    if (dr != -1)
    {
        if (dr + 1 == k)
            pqueue_push(pqueue, root->data);
        else
            printkdistanceNodeDown(root->left, k - dr - 2, pqueue);
        return 1 + dr;
    }

    return -1;
}
void printElement(PriorityQueue *pqueue, int kk)
{
    PQueueNode *temp = pqueue->_top;
    while (temp != NULL && kk--)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void printElement1(PriorityQueue *pqueue)
{
    PQueueNode *temp = pqueue->_top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    AVL avlku;
    avl_init(&avlku);
    // Buat objek PriorityQueue
    PriorityQueue myPque;

    // PENTING! Jangan lupa diinisialisasi
    pqueue_init(&myPque);
    int N, jrk = 0, T;
    // scanf("%d %d", &N, &T);
    while (1)
    {
        scanf("%d", &N);
        if (N == -1)
        {
            printf("End of Program\n");
            return 0;
        }
        else if (N == 0)
        {
            int k, l, m;
            scanf("%d %d %d", &k, &l, &m);
            if (avl_isEmpty(&avlku) || !avl_find(&avlku, k))
            {
                printf("Error : orangnya belum datang\n");
                continue;
            }
            for (int i = l; i >= 0; i--)
            {
                printkdistanceNode(avlku._root, k, i, &myPque);
            }
            if (m == -1)
            {
                printElement1(&myPque);
                printf("\n");
                myPque._top = NULL;
                continue;
            }
            printElement(&myPque, m);
            printf("\n");
            myPque._top = NULL;
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                int QQ;
                scanf("%d", &QQ);
                avl_insert(&avlku, QQ);
            }
        }
    }

    /*
    for (int i = 0; i < N; i++)
    {
        char arr[100];
        scanf("%s", arr);
        if (strcmp(arr, "masuk") == 0)
        {
            int xyz;
            scanf("%d", &xyz);
            avl_insert(&avlku, xyz);
        }
        else if (strcmp(arr, "kode") == 0)
        {
            memset(arry, 0, sizeof(arry));
            solved(avlku._root, 6000);
            for (int i = 0; i < 10000; i++)
            {
                if (arry[i] != 0)
                {
                    printf("%d", arry[i]);
                }
            }
            printf("\n");
        }
    }
    */
    /*
    for (int i = 0; i < N; i++)
    {
        char arr[100];
        scanf("%s", arr);
        if (strcmp(arr, "buat") == 0)
        {
            int a;
            scanf("%d", &a);
            avl_insert(&avlku, a);
            jrk++;
        }
        else if (strcmp(arr, "cari") == 0)
        {
            int y;
            scanf("%d", &y);
            if (!avl_find(&avlku, y))
            {
                printf("Lah, ruangannya mana?\n");
                continue;
            }
            bst_preorder(&avlku, y);
            for (int i = 0; i < jrk; i++)
            {
                if (arry[i] == y)
                {
                    hasil = i;
                    break;
                }
            }

            printf("Ruangannya ada di urutan ke-%d\n", hasil + 1);
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("Maksudnya gimana?\n");
        }
    }
    */

    /*
    for (int i = 0; i < N; i++)
     {
         int kk;
         scanf("%d", &kk);
         avl_insert(&avlku, kk);
     }
     for (int i = 0; i < T; i++)
     {
         int xx;
         scanf("%d", &xx);
         if (avlku._root->data != xx)
         {
             SS(&avlku, xx);
         }
         else
         {
             printf("0\n");
         }
     }
     */
}