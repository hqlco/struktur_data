/**
 * nama file 	: 2.cpp
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

//? VARIABEL END()

//! FUNGSI FUNGSI BEGIN()

void foo(int X, int Y)
{
    if (X < 0 || X > 9 || Y < 0 || Y > 9)
        return;

    if (!visit[X][Y])
    {

        if (arr[X][Y] == 1)
        {
            visit[X][Y] = 1;
            foo(X + 1, Y); // bawah
            foo(X, Y - 1); // kiri
            foo(X - 1, Y); // atas
            foo(X, Y + 1); // kanan
        }
    }
}

//! FUNGSI FUNGSI END()

//* INTI BEGIN()

void input()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
        }
    }
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
                foo(i, j);
            }
        }
    }
    cout << cek;
    return;
}

//* INTI END()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solved();
    return 0;
}