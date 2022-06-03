#include <bits/stdc++.h>
#define euler using
#define feyman namespace
#define lebinz std

euler feyman lebinz;

#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define pii pair<int, int>
#define MOD 1000000007
// string findSum(string str1, string str2)
// {
//     if (str1.length() > str2.length())
//         swap(str1, str2);

//     string str = "";

//     int n1 = str1.length(), n2 = str2.length();

//     reverse(str1.begin(), str1.end());
//     reverse(str2.begin(), str2.end());

//     int carry = 0;
//     for (int i = 0; i < n1; i++)
//     {
//         int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
//         str.push_back(sum % 10 + '0');

//         carry = sum / 10;
//     }

//     for (int i = n1; i < n2; i++)
//     {
//         int sum = ((str2[i] - '0') + carry);
//         str.push_back(sum % 10 + '0');
//         carry = sum / 10;
//     }

//     if (carry)
//         str.push_back(carry + '0');

//     reverse(str.begin(), str.end());

//     return str;
// }
// class TNode
// {
// public:
//     int data;
//     TNode *left;
//     TNode *right;
// };

// TNode *newNode(int data);

// TNode *sortedArrayToBST(int arr[],
//                         int start, int end)
// {

//     if (start > end)
//         return NULL;

//     int mid = (start + end) / 2;
//     TNode *root = newNode(arr[mid]);

//     root->left = sortedArrayToBST(arr, start,
//                                   mid - 1);

//     root->right = sortedArrayToBST(arr, mid + 1, end);

//     return root;
// }

// TNode *newNode(int data)
// {
//     TNode *node = new TNode();
//     node->data = data;
//     node->left = NULL;
//     node->right = NULL;

//     return node;
// }

// void prea(TNode *node)
// {
//     if (node == NULL)
//         return;
//     cout << node->data << "\n";
//     prea(node->left);
//     prea(node->right);
// }
// typedef struct bstnode_t
// {
//     int key;
//     int level;
//     int arrx;
//     struct bstnode_t
//         *left,
//         *right;
// } BSTNode;

// typedef struct bst_t
// {
//     BSTNode *_root;
//     unsigned int _size;
// } BST;

// int level, M_lvl = 0, arr[100];

// BSTNode *__bst__createNode(int value)
// {
//     BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
//     newNode->key = value;
//     newNode->level = level;
//     arr[level]++;
//     newNode->arrx = arr[level];
//     newNode->left = newNode->right = NULL;

//     if (level > M_lvl)
//         M_lvl = level;

//     return newNode;
// }

// BSTNode *__bst__insert(BSTNode *root, int value)
// {
//     if (root == NULL)
//         return __bst__createNode(value);

//     if (value < root->key)
//     {
//         level++;
//         root->left = __bst__insert(root->left, value);
//     }
//     else if (value > root->key)
//     {
//         level++;
//         root->right = __bst__insert(root->right, value);
//     }

//     return root;
// }

// BSTNode *__bst__search(BSTNode *root, int value)
// {
//     while (root != NULL)
//     {
//         if (value < root->key)
//             root = root->left;
//         else if (value > root->key)
//             root = root->right;
//         else
//             return root;
//     }
//     return root;
// }

// BSTNode *__bst__findMinNode(BSTNode *node)
// {
//     BSTNode *currNode = node;
//     while (currNode && currNode->left != NULL)
//         currNode = currNode->left;

//     return currNode;
// }

// BSTNode *__bst__remove(BSTNode *root, int value)
// {
//     if (root == NULL)
//         return NULL;

//     if (value > root->key)
//         root->right = __bst__remove(root->right, value);
//     else if (value < root->key)
//         root->left = __bst__remove(root->left, value);
//     else
//     {

//         if (root->left == NULL)
//         {
//             BSTNode *rightChild = root->right;
//             free(root);
//             return rightChild;
//         }
//         else if (root->right == NULL)
//         {
//             BSTNode *leftChild = root->left;
//             free(root);
//             return leftChild;
//         }

//         BSTNode *temp = __bst__findMinNode(root->right);
//         root->key = temp->key;
//         root->right = __bst__remove(root->right, temp->key);
//     }
//     return root;
// }

// bool cek = false;

// void __bst__ina(BSTNode *root)
// {
//     if (root)
//     {
//         __bst__ina(root->left);

//         if ((root->level != 0 && root->level != 1) && (root->left != 0 || root->right != 0))
//         {
//             if (root->arrx != 0 && root->arrx != arr[root->level])
//             {
//                 printf("%d ", root->key);
//                 cek = true;
//             }
//         }

//         __bst__ina(root->right);
//     }
// }

// void __bst__posta(BSTNode *root)
// {
//     if (root)
//     {
//         __bst__posta(root->left);
//         __bst__posta(root->right);
//         printf("%d ", root->key);
//     }
// }

// void __bst__prea(BSTNode *root)
// {
//     if (root)
//     {
//         printf("%d ", root->key);
//         __bst__prea(root->left);
//         __bst__prea(root->right);
//     }
// }

// void bst_init(BST *bst)
// {
//     bst->_root = NULL;
//     bst->_size = 0u;
// }

// bool bst_isEmpty(BST *bst)
// {
//     return bst->_root == NULL;
// }

// bool bst_find(BST *bst, int value)
// {
//     BSTNode *temp = __bst__search(bst->_root, value);
//     if (temp == NULL)
//         return false;

//     if (temp->key == value)
//         return true;
//     else
//         return false;
// }

// void bst_insert(BST *bst, int value)
// {
//     if (!bst_find(bst, value))
//     {
//         bst->_root = __bst__insert(bst->_root, value);
//         bst->_size++;
//     }
// }

// void bst_remove(BST *bst, int value)
// {
//     if (bst_find(bst, value))
//     {
//         bst->_root = __bst__remove(bst->_root, value);
//         bst->_size--;
//     }
// }

// void bst_ina(BST *bst)
// {
//     __bst__ina(bst->_root);
// }

// void bst_posta(BST *bst)
// {
//     __bst__posta(bst->_root);
// }

// void bst_prea(BST *bst)
// {
//     __bst__prea(bst->_root);
// }

// typedef struct AVLNode_t
// {
//     int data;
//     struct AVLNode_t *left, *right;
//     int height;
// } AVLNode;

// typedef struct AVL_t
// {
//     AVLNode *_root;
//     unsigned int _size;
// } AVL;

// int arr[100000];
// int e = 0;

// AVLNode *_avl_createNode(int value)
// {
//     AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
//     newNode->data = value;
//     newNode->height = 1;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// AVLNode *_search(AVLNode *root, int value)
// {
//     while (root != NULL)
//     {
//         if (value < root->data)
//             root = root->left;
//         else if (value > root->data)
//             root = root->right;
//         else
//             return root;
//     }
//     return root;
// }

// int _getHeight(AVLNode *node)
// {
//     if (node == NULL)
//         continue;
//     return node->height;
// }

// int _max(int a, int b)
// {
//     return (a > b) ? a : b;
// }

// AVLNode *_rightRotate(AVLNode *pivotNode)
// {

//     AVLNode *newParrent = pivotNode->left;
//     pivotNode->left = newParrent->right;
//     newParrent->right = pivotNode;

//     pivotNode->height = _max(_getHeight(pivotNode->left),
//                              _getHeight(pivotNode->right)) +
//                         1;
//     newParrent->height = _max(_getHeight(newParrent->left),
//                               _getHeight(newParrent->right)) +
//                          1;

//     return newParrent;
// }

// AVLNode *_leftRotate(AVLNode *pivotNode)
// {

//     AVLNode *newParrent = pivotNode->right;
//     pivotNode->right = newParrent->left;
//     newParrent->left = pivotNode;

//     pivotNode->height = _max(_getHeight(pivotNode->left),
//                              _getHeight(pivotNode->right)) +
//                         1;
//     newParrent->height = _max(_getHeight(newParrent->left),
//                               _getHeight(newParrent->right)) +
//                          1;

//     return newParrent;
// }

// AVLNode *_leftCaseRotate(AVLNode *node)
// {
//     return _rightRotate(node);
// }

// AVLNode *_rightCaseRotate(AVLNode *node)
// {
//     return _leftRotate(node);
// }

// AVLNode *_leftRightCaseRotate(AVLNode *node)
// {
//     node->left = _leftRotate(node->left);
//     return _rightRotate(node);
// }

// AVLNode *_rightLeftCaseRotate(AVLNode *node)
// {
//     node->right = _rightRotate(node->right);
//     return _leftRotate(node);
// }

// int _getBalanceFactor(AVLNode *node)
// {
//     if (node == NULL)
//         continue;
//     return _getHeight(node->left) - _getHeight(node->right);
// }

// AVLNode *_insert_AVL(AVL *avl, AVLNode *node, int value)
// {

//     if (node == NULL) // udah mencapai leaf
//         return _avl_createNode(value);
//     if (value < node->data)
//         node->left = _insert_AVL(avl, node->left, value);
//     else if (value > node->data)
//         node->right = _insert_AVL(avl, node->right, value);

//     node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

//     int balanceFactor = _getBalanceFactor(node);

//     if (balanceFactor > 1 && value < node->left->data) // skewed kiri (left-left case)
//         return _leftCaseRotate(node);
//     if (balanceFactor > 1 && value > node->left->data) //
//         return _leftRightCaseRotate(node);
//     if (balanceFactor < -1 && value > node->right->data)
//         return _rightCaseRotate(node);
//     if (balanceFactor < -1 && value < node->right->data)
//         return _rightLeftCaseRotate(node);

//     return node;
// }
// int XXXX, V, E, tanda = 0;
// bool visit[10001];
// int arr2[10001][10001];
// void dfs(int curVertex, int count)
// {
//     if (count == V - 1)
//     {
//         tanda = 1;
//         XXXX = count;
//         return;
//     }
//     visit[curVertex] = 1;
//     for (int i = 0; i < V; i++)
//     {
//         if (tanda == 1)
//             return;
//         int nextVertex = i;
//         if (!visit[nextVertex] && arr2[curVertex][i] == 1)
//         {
//             dfs(nextVertex, count + 1);
//         }
//     }
//     visit[curVertex] = 0;
// }

int n, m, q;
int a[100000], val[100000], sum[100000];
vector<int> arr1[100000], arr2[100000];
// AVLNode *_findMinNode(AVLNode *node)
// {
//     AVLNode *currNode = node;
//     while (currNode && currNode->left != NULL)
//         currNode = currNode->left;
//     return currNode;
// }

// AVLNode *_remove_AVL(AVLNode *node, int value)
// {
//     if (node == NULL)
//         return node;
//     if (value > node->data)
//         node->right = _remove_AVL(node->right, value);
//     else if (value < node->data)
//         node->left = _remove_AVL(node->left, value);
//     else
//     {
//         AVLNode *temp;
//         if ((node->left == NULL) || (node->right == NULL))
//         {
//             temp = NULL;
//             if (node->left == NULL)
//                 temp = node->right;
//             else if (node->right == NULL)
//                 temp = node->left;

//             if (temp == NULL)
//             {
//                 temp = node;
//                 node = NULL;
//             }
//             else
//                 *node = *temp;

//             free(temp);
//         }
//         else
//         {
//             temp = _findMinNode(node->right);
//             node->data = temp->data;
//             node->right = _remove_AVL(node->right, temp->data);
//         }
//     }

//     if (node == NULL)
//         return node;

//     node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

//     int balanceFactor = _getBalanceFactor(node);

//     if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
//         return _leftCaseRotate(node);

//     if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
//         return _leftRightCaseRotate(node);

//     if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
//         return _rightCaseRotate(node);

//     if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
//         return _rightLeftCaseRotate(node);

//     return node;
// }

// void avl_init(AVL *avl)
// {
//     avl->_root = NULL;
//     avl->_size = 0u;
// }

// bool avl_isEmpty(AVL *avl)
// {
//     return avl->_root == NULL;
// }

// bool avl_find(AVL *avl, int value)
// {
//     AVLNode *temp = _search(avl->_root, value);
//     if (temp == NULL)
//         return false;

//     if (temp->data == value)
//         return true;
//     else
//         return false;
// }

// void avl_insert(AVL *avl, int value)
// {
//     if (!avl_find(avl, value))
//     {
//         avl->_root = _insert_AVL(avl, avl->_root, value);
//         avl->_size++;
//     }
// }

// void avl_remove(AVL *avl, int value)
// {
//     if (avl_find(avl, value))
//     {
//         avl->_root = _remove_AVL(avl->_root, value);
//         avl->_size--;
//     }
// }

// void preorder(AVLNode *root)
// {
//     if (root)
//     {
//         preorder(root->left);
//         printf("%d ", root->data);
//         preorder(root->right);
//     }
// }

// bool getPath(AVLNode *root, vector<int> &arr, int x)
// {

//     if (!root)
//         return false;

//     arr.push_back(root->data);

//     if (root->data == x)
//         return true;
//     if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
//         return true;

//     arr.pop_back();
//     return false;
// }

// void printPathBetweenNodes(AVLNode *root, int n1, int n2)
// {
//     vector<int> path1;

//     vector<int> path2;

//     getPath(root, path1, n1);
//     getPath(root, path2, n2);

//     int intersection = -1;

//     int i = 0, j = 0;
//     while (i != path1.size() || j != path2.size())
//     {

//         if (i == j && path1[i] == path2[j])
//         {
//             i++;
//             j++;
//         }
//         else
//         {
//             intersection = j - 1;
//             break;
//         }
//     }

//     for (int i = path1.size() - 1; i > intersection; i--)
//     {
//         arr[e] = path1[i];
//         e++;
//     }

//     for (int i = intersection; i < path2.size(); i++)
//     {
//         arr[e] = path2[i];
//         e++;
//     }
// }
// class Graph
// {
//     int V;

//     list<int> *adj;

//     void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

//     bool isCyclicUtil(int v, bool visited[], bool *rs);

// public:
//     Graph(int V);

//     void addEdge(int v, int w);

//     void topologicalSort();

//     bool isCyclic();
// };

// Graph::Graph(int V)
// {
//     this->V = V;
//     adj = new list<int>[V];
// }

// void Graph::addEdge(int v, int w)
// {
//     adj[v].push_back(w);
// }

// void Graph::topologicalSortUtil(int v, bool visited[],
//                                 stack<int> &Stack)
// {
//     visited[v] = true;

//     list<int>::iterator i;
//     for (i = adj[v].begin(); i != adj[v].end(); ++i)
//         if (!visited[*i])
//             topologicalSortUtil(*i, visited, Stack);

//     Stack.push(v);
// }

// bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
// {
//     if (visited[v] == false)
//     {
//         visited[v] = true;
//         recStack[v] = true;

//         list<int>::iterator i;
//         for (i = adj[v].begin(); i != adj[v].end(); ++i)
//         {
//             if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
//                 return true;
//             else if (recStack[*i])
//                 return true;
//         }
//     }
//     recStack[v] = false;
//     return false;
// }
// void Graph::topologicalSort()
// {
//     stack<int> Stack;

//     bool *visited = new bool[V];
//     for (int i = 0; i < V; i++)
//         visited[i] = false;

//     for (int i = 0; i < V; i++)
//         if (visited[i] == false)
//             topologicalSortUtil(i, visited, Stack);

//     while (Stack.empty() == false)
//     {
//         if (Stack.size() == 1)
//             break;
//         cout << Stack.top() << " ";
//         Stack.pop();
//     }
// }

// bool Graph::isCyclic()
// {
//     bool *visited = new bool[V];
//     bool *recStack = new bool[V];
//     for (int i = 0; i < V; i++)
//     {
//         visited[i] = false;
//         recStack[i] = false;
//     }
//     for (int i = 0; i < V; i++)
//         if (!visited[i] && isCyclicUtil(i, visited, recStack))
//             return true;

//     return false;
// }
// int arry[10001];
// int n, h;
// int leka = 0;
// void solved(int hi, int left, int right)
// {
//     if (left <= right && left > 0 && right <= n)
//     {
//         int L = (pow(2, hi - 1) - 1);
//         int x = right - L;
//         if (x < left)
//         {
//             x = left;
//         }
//         leka = leka + 1;
//         if (leka == n)
//         {
//             cout << arry[x];
//         }
//         else
//         {
//             cout << arry[x] << " ";
//         }
//         solved(hi - 1, left, x - 1);
//         solved(hi - 1, x + 1, right);
//     }
//     else
//     {
//         return;
//     }
// }
// int maze[1000][1000];
// int xx, yy;

// int solved(int x, int y)
// {
//     if (x <= xx && y <= yy)
//     {
//         if (maze[x][y] == 0)
//         {
//             return 0;
//         }
//         if (x == xx - 1 && y == yy - 1)
//         {
//             return 1;
//         }
//         maze[x][y] = 0;
//         return (solved(x + 1, y) || solved(x, y + 1));
//     }
//     else
//     {
//         return 0;
//     }
// }

int main()
{ /*
     string a;
     string b;
     int m, n;
     cin >> m;
     cin >> n;
     for (int i = 0; i < m; i++)
     {
         string x;
         cin >> x;
         a = a + x;
     }
     for (int i = 0; i < n; i++)
     {
         string x;
         cin >> x;
         b = b + x;
     }

     cout << "[" << findSum(a, b) << "]";

    int K;
    cin >> K;
    stack<string> S;
    list<string> L;
    L.push_back("home");
    L.push_back("anton");
    for (int i = 0; i < K; i++)
    {
        string a;
        cin >> a;
        if (a == "goto")
        {
            string nn;
            cin >> nn;
            // S.push(nn);
            L.push_back(nn);
        }
        else if (a == "goback")
        {
            if (L.empty())
            {
                cout << "cannot go back\n";
                continue;
            }
            // S.pop();
            L.pop_back();
        }
        else if (a == "whereami")
        {
            if (L.empty())
            {
                cout << "i am nowhere\n";
                continue;
            }
            for (auto qq = L.begin(); qq != L.end(); qq++)
            {
                auto ss = qq;
                ss++;
                cout << *qq;
                if (ss != L.end())
                {
                    cout << "/";
                }
            }
            cout << "\n";
        }
        else
        {
            cout << "Query not found\n";
        }
    }

    int arr[100001];
    int X;
    cin >> X;
    for (int i = 0; i < X; i++)
    {
        int cc = i + 1;
        arr[i] = cc;
    }

    TNode *root = sortedArrayToBST(arr, 0, X - 1);
    prea(root);

    BST set;
    bst_init(&set);
    int N, a;
    cin >> N;
    memset(arr, -1, sizeof(arr));
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        level = 0;
        bst_insert(&set, a);
    }
    bst_ina(&set);
    if (!cek)
    {
        cout << "It's not safe\n";
    }

    set<unsigned long long> S;
    unsigned long long N;
    unsigned long long X = 0;
    unsigned long long xixi;
    int tanda = 1;
    // cin >> N;
    while (scanf("%lld", &N) != EOF)
    {
        unsigned long long A;
        cin >> A;
        S.insert(A);
        X++;
        unsigned long long Y = S.size();
        if (Y < X)
        {
            if (tanda = 1)
            {
                xixi = A;
                tanda = 0;
            }
        }
    }
    unsigned long long ans = 1;
    if (xixi % 10001 < ans)
        printf("<\n");
    if (xixi % 10001 == ans)
        printf("==\n");
    if (xixi % 10001 > ans)
        printf(">\n");


    cin >> V;
    cin >> E;
    int a, b;
    int arr1[V][V];
    for (int i = 0; i < E; i++)
    {
        cin >> a;
        cin >> b;
        arr1[a][b] = 1;
        arr1[b][a] = 1;
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (arr1[i][j] == 1)
            {
                for (int k = 0; k < V; k++)
                {
                    if (k != i && arr1[j][k] == 1)
                    {
                        arr2[i][k] = 1;
                    }
                }
            }
        }
    }
    dfs(0, 0);
    if (XXXX == V - 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }


     int N;
     cin >> N;
     vector<pii> V;
     for (int i = 0; i < N; i++)
     {
         int tanda = 1;
         string a;
         int jj;
         cin >> a >> jj;
         // scanf("%s", a);
         if (a == "room")
         {
             // int xx;
             // cin >> xx;
             pii C = make_pair(jj, 1);
             V.push_back(C);
         }
         else if (a == "gold")
         {
             // int A;
             //  >> A;
             for (int j = 0; j < V.size(); j++)
             {
                 if (V[j].first == jj)
                 {
                     cout << "The gold at " << V[j].second << " floor\n";
                     V[j].second = V[j].second + 1;
                     tanda = 0;
                     break;
                 }
             }
             if (tanda)
             {
                 cout << "Gold not found\n";
             }
         }
         else
         {
             cout << "Sorry, I don't understand ninuninu\n";
             // continue;
         }
     }

     AVL tower;
     avl_init(&tower);
     int X;
     cin >> X;
     for (int i = 0; i < X; i++)

     {
         string a;
         cin >> a;
         if (a == "room")
         {
             int num;
             cin >> num;
             avl_insert(&tower, num);
         }
         else if (a == "gold")
         {
             int num;
             cin >> num;
             if (!avl_find(&tower, num))
                 cout << "Gold not found" << endl;
             else
             {
                 AVLNode *gold = _search(tower._root, num);
                 int level = _getHeight(gold);
                 cout << "The gold at " << level << " floor" << endl;
             }
         }
         else
         {
             cout << "Sorry, I don't understand ninuninu" << endl;
         }
     }

     AVL avlku;
     avl_init(&avlku);
     int n, num;

     cin >> n;
     for (int i = 0; i < n; i++)
     {

         cin >> num;
         avl_insert(&avlku, num);
     }

     int x, y;
     cin >> x >> y;

     printPathBetweenNodes(avlku._root, x, y);
     int leka = 0;
     for (int i = 0; i < e; i++)
     {
         if (arr[i] != y)
         {
             leka += abs(arr[i] - arr[i + 1]);
         }
     }
     cout << leka;

     int N;
     double A[101], B[101];
     cin >> N;

     double ans = 2000000000;
     for (int i = 0; i < N; i++)
     {
         scanf("%lf%lf", &A[i], &B[i]);
     }
     int tanda = 0;
     for (int i = 1; i <= N - 2; i++)
     {
         for (int j = i + 1; j <= N - 1; j++)
         {
             for (int k = j + 1; k <= N; k++)
             {
                 double leka = ((A[j] * B[i]) + (A[k] * B[j]) + (A[i] * B[k])) - ((A[i] * B[j]) + (A[j] * B[k]) + (A[k] * B[i]));
                 leka = fabs(leka / 2.00);
                 if (leka == ans)
                 {
                     tanda = 1;
                 }
                 if (leka != 0)
                 {
                     if (leka < ans)
                     {
                         tanda = 0;
                         ans = leka;
                     }
                 }
             }
         }
     }
     if (tanda)
     {
         ans = -1.00;
     }
     if (ans != 2000000000)
     {
         printf("%.2lf\n", ans);
     }
     else
     {
         cout << "-1.00\n";
     }

     int N, num, w = 0, xxx = 0;
     vector<int> arr(1000001, 0);
     vector<int> nums(1000001, 0);
     cin >> N;
     for (int i = 0; i < N; i++)
     {
         w++;
         cin >> num;
         if (nums[w - 1] == num)
         {
             w--;
         }
         xxx++;
         arr[w]++;
         nums[w] = num;
         if (arr[w] == num)
         {
             arr[w] = 0;
             nums[w] = 0;
             xxx -= num;
             w--;
         }
         cout << xxx << "\n";
     }

     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     int V, E;
     cin >> V >> E;
     int dis[V + 1];
     for (int i = 0; i < E; i++)
     {
         int A, B, C;
         cin >> A >> B >> C;
         if (A == 0)
         {
             dis[B] = C;
         }
         else
         {
             dis[B] = C;
             dis[B] += dis[A];
         }
     }
     for (int i = 1; i < V; i++)
     {
         printf("%d %d\n", i, dis[i]);
     }

     int m, n;
     cin >> m >> n;
     Graph g(m + 1);
     for (int i = 0; i < m; i++)
     {
         int a, b;
         cin >> a >> b;
         g.addEdge(a, b);
     }
     if (g.isCyclic())
     {
         cout << "-1" << endl;
     }
     else
     {
         g.topologicalSort();
     }


     vector<int> lost, player[5], seeker;
     int out1 = 0, out2 = 0, out3 = 0, out4 = 0;
     string N_1, N_2, N_3, N_4;
     cin >> N_1 >> N_2 >> N_3 >> N_4;
     int langkah, jaga = 0;
     string temp;
     cin >> langkah >> temp;
     if (temp == N_1)
     {
         jaga = 1;
     }
     else if (temp == N_2)
     {
         jaga = 2;
     }
     else if (temp == N_3)
     {
         jaga = 3;
     }
     else if (temp == N_4)
     {
         jaga = 4;
     }
     int a, b;
     for (int i = 0; i < langkah; i++)
     {
         cin >> a;
         cin >> b;
         if (a == jaga)
         {
             seeker.push_back(b);
         }
         else
         {
             player[a].push_back(b);
         }
     }
     for (int i = 0; i < seeker.size(); i++)
     {
         if (jaga != 1 && i < player[1].size() && !out1 && seeker.at(i) == player[1].at(i))
         {
             out1 = 1;
         }
         if (jaga != 2 && i < player[2].size() && !out2 && seeker.at(i) == player[2].at(i))
         {
             out2 = 1;
         }
         if (jaga != 3 && i < player[3].size() && !out3 && seeker.at(i) == player[3].at(i))
         {
             out3 = 1;
         }
         if (jaga != 4 && i < player[4].size() && !out4 && seeker.at(i) == player[4].at(i))
         {
             out4 = 1;
         }
     }
     vector<string> leka;
     if (jaga != 4 && out4)
     {
         leka.push_back(N_4);
     }
     if (jaga != 3 && out3)
     {
         leka.push_back(N_3);
     }
     if (jaga != 2 && out2)
     {
         leka.push_back(N_2);
     }
     if (jaga != 1 && out1)
     {
         leka.push_back(N_1);
     }
     if (leka.empty())
     {
         cout << temp << " jaga lagi";
     }
     else
     {
         for (int i = leka.size() - 1; i >= 0; i--)
         {
             cout << leka.back();
             leka.pop_back();
             if (i == 1)
             {
                 cout << ", dan ";
             }
             else if (i == 0)
             {
                 cout << " ditangkap oleh " << temp;
             }
             else
             {
                 cout << ", ";
             }
         }
     }

     int M, N;
     cin >> M >> N;
     int maze[M + 1][N + 1];
     for (int i = 0; i < M; i++)
     {
         for (int j = 0; j < N; j++)
         {
             char a;
             cin >> a;
             if (a == '.')
             {
                 maze[i][j] = 1;
             }
             else if (a == '#')
             {
                 maze[i][j] = 0;
             }
         }
     }*/
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        a[i] = w;
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        arr1[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            arr1[i][j] = x;
            arr1[i][j]--;
        }
        if (k >= 316)
        {
            for (int x : arr1[i])
            {
                arr2[x].push_back(i);
                val[i] += sum[i] * a[x];
                sum[i] += a[x];
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            int y;
            cin >> x >> y;
            x--;
            for (auto i : arr2[x])
            {
                val[i] += (sum[i] - a[x]) * (y - a[x]);
                sum[i] += (y - a[x]);
            }
            a[x] = y;
        }
        else
        {
            int x;
            cin >> x;
            x--;
            if (arr1[x].size() < 316)
            {
                val[x] = sum[x] = 0;
                for (int i : arr1[x])
                {
                    val[x] += sum[x] * a[i];
                    sum[x] += a[i];
                }
            }
            cout << val[x] << "\n";
        }
    }
    /*
        int X;
        cin >> X;
        for (int i = 0; i < X; i++)
        {

            int M, N, S;
            cin >> M >> N >> S;
            if (S > N && S > M)
            {
                cout << M << "*" << N << "*" << S << " : "
                     << "khusus"
                     << "\n";
                continue;
            }
            int temp = M * N - S;
            if (temp % S == 0)
            {
                int leka = temp / S;
                if (leka % 2 == 0)
                {
                    cout << M << "*" << N << "*" << S << " : " << leka << "\n";
                    continue;
                }
                if (leka % 2 == 1)
                {
                    cout << M << "*" << N << "*" << S << " : " << leka << "\n";
                    continue;
                }
            }
            if (temp % S != 0)
            {
                int leo = temp / S + 1;
                if (leo % 2 == 0)
                {
                    cout << M << "*" << N << "*" << S << " : " << leo << "\n";
                    continue;
                }
                if (leo % 2 == 1)
                {
                    cout << M << "*" << N << "*" << S << " : " << leo << "\n";
                    continue;
                }
            }
        }

        cin >> xx >> yy;
        map<char, int> Mp;
        Mp['.'] = 1;
        Mp['#'] = 0;
        for (int i = 0; i < xx; i++)
        {
            for (int j = 0; j < yy; j++)
            {
                char c;
                cin >> c;
                maze[i][j] = Mp[c];
            }
        }
        int leka = 0;
        if (solved(1, 0))
        {
            leka++;
        }
        if (solved(0, 1))
        {
            leka++;
        }
        cout << leka;


        for (int i = 0; i < 10001; i++)
        {
            arry[i] = i;
        }
        int a = 1;
        while (1)
        {
            cin >> n >> h;
            if (n == 0 && h == 0)
            {
                return 0;
            }
            cout << "Case " << a << ": ";
            if (n < h)
            {
                cout << "Impossible.\n";
                continue;
            }
            if ((pow(2, h) - 1) < n)
            {
                cout << "Impossible.\n";
            }
            else
            {
                leka = 0;
                solved(h, 1, n);
                cout << "\n";
            }
        }
        */
}