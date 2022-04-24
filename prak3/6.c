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

int main()
{
    AVL avlku;
    avl_init(&avlku);
    int N, jrk = 0;
    scanf("%d", &N);
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
}