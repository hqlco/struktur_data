/**
 * nama file 	: 6.cpp
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

// int arr[101][101];
int visit[101][101];
int cek = 0;
map<string, int> MM;
vi arry[10001];
vi visited(10001, 0);
set<int> white; // white container
set<int> grey;  // grey container
set<int> black; // black container
int tanda = 0;
multiset<pii> MEO;
int KN;
#define MAKS 10000
// int arr[100][10000];
// vector<vi> arr(1000, vi(MAKS + 1, -1));
//? VARIABEL END()

//! FUNGSI FUNGSI BEGIN()

// void foo(int u, vector<int> adj[])
// {
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
//     white.erase(u);
//     grey.insert(u);
//     for (int i = 0; i < adj[u].size(); i++)
//     {
//         if (white.find(adj[u][i]) != white.end())
//         {
//             foo(adj[u][i], adj);
//         }
//         if (grey.find(adj[u][i]) != grey.end())
//         {
//             tanda = 1;
//         }
//     }
//     black.insert(u);
//     grey.erase(u);
// }
// void edge(vector<int> adj[], int u, int v)
// {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
// bool isCyclicConntected(vector<int> adj[], int s, int V, vector<bool> &visited)
// {
//     vector<int> parent(V, -1);

//     queue<int> q;

//     visited[s] = true;
//     q.push(s);

//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();

//         for (auto v : adj[u])
//         {
//             if (!visited[v])
//             {
//                 visited[v] = true;
//                 q.push(v);
//                 parent[v] = u;
//             }
//             else if (parent[u] != v)
//                 return true;
//         }
//     }
//     return false;
// }

// bool isCyclicDisconntected(vector<int> adj[], int V)
// {
//     vector<bool> visited(V, false);

//     for (int i = 0; i < V; i++)
//         if (!visited[i] && isCyclicConntected(adj, i, V, visited))
//             return true;
//     return false;
// }
// void print1(multiset<pair<int, int>> &multisetOfPairs)
// {
//     int tempp = 0;
//     // auto i=;
//     for (auto cuurentPair : multisetOfPairs)
//     {
//         pii pr = cuurentPair;
//         if (pr.first <= KN + 1)
//         {
//             if (tempp != pr.first)
//             {
//                 cout << 1;
//             }
//         }

//         tempp = pr.first;
//         cout << "[ " << pr.first << ' ' << pr.second << " ]" << '\n';
//     }
// }
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
    // int N;
    // cin >> N;
    // vector<int> adj[1000]; // vector of array to store the graph
    // for (int i = 0; i < N; i++)
    // {
    //     int A, B;
    //     cin >> A >> B;
    //     edge(adj, A, B);
    // }
    // if (isCyclicDisconntected(adj, 1000))
    //     cout << "Tch, let's find another multiverse" << endl;
    // else
    //     cout << "Mary, let's meet again" << endl;
    // cin >> KN;
    // for (int i = 0; i < KN; i++)
    // {
    //     int AA, BB;
    //     cin >> AA >> BB;
    //     pii PP;
    //     PP = make_pair(BB, AA);
    //     MEO.insert(PP);
    // }
    // int leka = 0;
    // auto it1 = MEO.begin();
    // it1++;
    // auto it2 = MEO.end();
    // for (it1; it1 != it2; it1++)
    // {
    //     if (it1->first <= KN + 1)
    //     {
    //         int MA = it1->first;
    //         it1--;
    //         int MB = it1->first;
    //         if (MA != MB)
    //         {
    //             leka = leka + it1->second;
    //         }
    //         it1++;
    //     }
    // }
    // cout << leka;
    // int t, p;
    // while (cin >> t >> p)
    // {
    //     if (t == 0 && p == 0)
    //     {
    //         break;
    //     }
    //     int input, sahamku;
    //     // for (int i = 0; i < 100; i++)
    //     // {
    //     //     for (int j = 0; j < 10000; j++)
    //     //     {
    //     //         arr[i][j] = -1;
    //     //     }
    //     // }
    //     vector<int> saham(1);
    //     vector<vi> arr(MAKS, vi(MAKS + 1, -1));
    //     // int saham[1000];
    //     for (int i = 1; i <= t; i++)
    //     {
    //         int A1, A2;
    //         scanf("%d.%d", &A1, &A2);
    //         input = 100 * A1 + A2;
    //         if (i == p)
    //         {
    //             sahamku = input;
    //         }
    //         else
    //         {
    //             saham.push_back(input);
    //             // saham[i] = input;
    //         }
    //     }
    //     // saham[0] = 0;
    //     // for (int i = 0; i < t; i++)
    //     // {
    //     //     cout << "saham: " << saham[i] << " \n";
    //     // }
    //     // cout << "\n";
    //     arr[0][0] = 0;
    //     if (sahamku > 5000)
    //     {
    //         cout << "100.00 1\n";
    //         continue;
    //     }
    //     // arr[a][b]
    //     // a= index
    //     // b= hasil penjumlahan
    //     for (int idx = 1; idx < t; idx++)
    //     {
    //         for (int jumlah = 0; jumlah <= MAKS; jumlah++)
    //         {
    //             int s = arr[idx - 1][jumlah], xx = -1;
    //             if (jumlah >= saham[idx])
    //             {
    //                 xx = arr[idx - 1][jumlah - saham[idx]];
    //                 if (xx > -1)
    //                 {
    //                     xx++;
    //                 }
    //             }
    //             if (s > 0 || xx > 0)
    //             {
    //                 if (s > 0 && xx > 0)
    //                 {
    //                     arr[idx][jumlah] = min(s, xx);
    //                     continue;
    //                 }
    //                 else
    //                 {
    //                     arr[idx][jumlah] = max(s, xx);
    //                     continue;
    //                 }
    //             }
    //             arr[idx][jumlah] = max(s, xx);
    //         }
    //     }
    //     // cari mana yang kecil
    //     int hasil = -1, banyak = -1;
    //     for (int jumlah = 5001 - sahamku; jumlah <= MAKS; jumlah++)
    //     {
    //         for (int idx = 1; idx < t; idx++)
    //         {
    //             if (arr[idx][jumlah] > 0)
    //             {
    //                 banyak = arr[idx][jumlah];
    //                 hasil = jumlah;
    //                 break;
    //             }
    //         }
    //         if (hasil != -1)
    //         {
    //             break;
    //         }
    //     }
    //     for (int idx = 1; idx < t; idx++)
    //     {
    //         if (arr[idx][hasil] > 0)
    //         {
    //             banyak = min(banyak, arr[idx][hasil]);
    //         }
    //     }
    //     double hasil_asli = 100.0 * (double)sahamku / (double)(sahamku + hasil);
    //     cout << fixed << setprecision(2) << hasil_asli << " " << ++banyak << endl;
    // }
    int n;
    cin >> n;
    vector<pair<int, int>> V;
    for (int i = 0; i < n; i++)
    {
        int A, B;
        cin >> A >> B;
        V.push_back(make_pair(A, B));
    }
    sort(V.rbegin(), V.rend()); // mengurutkan terbesar
    vector<bool> visit(10001, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int P = V[i].first;
        int j = V[i].second;
        while (visit[j]) // kunjungan
        {
            j--;
            if (j == 0)
            {
                break;
            }
        }
        if (j == 0) // jika 0 maka tidak perlu di tambah lagi
        {
            continue;
        }
        ans = ans + P;
        visit[j] = true;
    }
    cout << ans;
}
// void solved()
// {
//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             if (!visit[i][j] && arr[i][j] == 1)
//             {
//                 cek++;
//                 // foo(i, j);
//             }
//         }
//     }
//     cout << cek;
// }

//* INTI END()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    // solved();
}