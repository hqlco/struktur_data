/**
 * nama file 	: 3.cpp
 * nama			: moh rosy haqqy aminy
 * nrp			: 5025211012
 * @date 2022-05-21
 *
 * @copyright Copyright (c) 2022
 *
 */
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

//? VARIABEL BEGIN()

int arr[101][101];
int visit[101][101];
int cek = 0;
map<string, int> MM;
vi arry[10001];
vi visited(10001, 0);
set<int> white; // white container
set<int> grey;  // grey container
set<int> black; // black container
int tanda = 0;
//? VARIABEL END()

//! FUNGSI FUNGSI BEGIN()

void foo(int u, vector<int> adj[])
{
    // if (X < 0 || X > 9 || Y < 0 || Y > 9)
    //     return;

    // if (!visit[X][Y])
    // {

    //     if (arr[X][Y] == 1)
    //     {
    //         visit[X][Y] = 1;
    //         foo(X + 1, Y); // bawah
    //         foo(X, Y - 1); // kiri
    //         foo(X - 1, Y); // atas
    //         foo(X, Y + 1); // kanan
    //     }
    // }
    //     visited[S] = 1;
    //     cek++;
    //     for (int i = 0; i < v[S].size(); i++)
    //     {
    //         int ll = v[S][i];
    //         if (!visited[ll])
    //         {
    //             foo(ll, v, visited);
    //         }
    //     }
    // }
    white.erase(u);
    grey.insert(u);
    for (int i = 0; i < 5; i++)
    {
        if (white.find(adj[u][i]) != white.end())
        {
            foo(adj[u][i], adj);
        }
        if (grey.find(adj[u][i]) != grey.end())
        {
            tanda = 1;
        }
    }
    black.insert(u);
    grey.erase(u);
}
void edge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool isCyclicConntected(vector<int> adj[], int s, int V, vector<bool> &visited)
{
    vector<int> parent(V, -1);

    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
                parent[v] = u;
            }
            else if (parent[u] != v)
                return true;
        }
    }
    return false;
}

bool isCyclicDisconntected(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i] && isCyclicConntected(adj, i, V, visited))
            return true;
    return false;
}

//! FUNGSI FUNGSI END()

//* INTI BEGIN()

void input()
{
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }

    // MM["A1"] = 1;
    // MM["A2"] = 2;
    // MM["A3"] = 3;
    // MM["B1"] = 4;
    // MM["B2"] = 5;
    // MM["B3"] = 6;
    // MM["C1"] = 7;
    // MM["C2"] = 8;
    // MM["C3"] = 9;
    // int T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    //     string A, B, C;
    //     cin >> A >> B >> C;
    //     int ww = MM[A];
    //     int yy = MM[C];
    //     arry[ww].push_back(yy);
    //     arry[yy].push_back(ww);
    // }
    // vi NN;
    // int XXXX = 0;
    // for (int i = 1; i <= 9; i++)
    // {
    //     if (!visited[i])
    //     {
    //         cek = 0;
    //         foo(i, arry, visited);
    //         NN.push_back(cek);
    //         XXXX++;
    //     }
    // }
    // int leka = 0;
    // for (int i = 0; i < XXXX - 1; i++)
    // {
    //     for (int j = i + 1; j < XXXX; j++)
    //     {
    //         int JJJ = NN[i] * NN[j];
    //         leka = leka + JJJ;
    //     }
    // }
    // cout << leka << endl;
    int N;
    cin >> N;
    vector<int> adj[1000]; // vector of array to store the graph
    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        edge(adj, A, B);
    }
    if (isCyclicDisconntected(adj, 1000))
        cout << "Tch, let's find another multiverse" << endl;
    else
        cout << "Mary, let's meet again" << endl;
}
void solved()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (!visit[i][j] && arr[i][j] == 1)
            {
                cek++;
                // foo(i, j);
            }
        }
    }
    cout << cek;
}

//* INTI END()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    // solved();
}