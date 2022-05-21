/**
 * nama file 	: 5.cpp
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
//? VARIABEL END()

//! FUNGSI FUNGSI BEGIN()

void foo(int S, vi v[], vi &visited)
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
    visited[S] = 1;
    cek++;
    int Leo = v[S].size();
    for (int i = 0; i < Leo; i++)
    {
        int ll = v[S][i];
        if (!visited[ll])
        {
            foo(ll, v, visited);
        }
    }
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

    MM["A1"] = 1;
    MM["A2"] = 2;
    MM["A3"] = 3;
    MM["B1"] = 4;
    MM["B2"] = 5;
    MM["B3"] = 6;
    MM["C1"] = 7;
    MM["C2"] = 8;
    MM["C3"] = 9;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string A, B, C;
        cin >> A >> B >> C;
        int ww = MM[A];
        int yy = MM[C];
        arry[ww].push_back(yy);
        arry[yy].push_back(ww);
    }
    vi NN;
    int XXXX = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (!visited[i])
        {
            cek = 0;
            foo(i, arry, visited);
            NN.push_back(cek);
            XXXX++;
        }
    }
    int leka = 0;
    for (int i = 0; i < XXXX - 1; i++)
    {
        for (int j = i + 1; j < XXXX; j++)
        {
            int JJJ = NN[i] * NN[j];
            leka = leka + JJJ;
        }
    }
    cout << leka << endl;
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