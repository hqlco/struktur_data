/**
 * nama file 	: 4.cpp
 * nama			: moh rosy haqqy aminy
 * nrp			: 5025211012
 * @date 2022-05-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;
void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    // adj[dest].push_back(src);
}
bool BFS(vector<int> adj[], int src, int dest, int v, int pred[], int dist[])
{
    list<int> queue;
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    visited[src] = true;
    dist[src] = 0;
    int temp = src;

    queue.push_back(src);
    int ttd = 0;
    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop_front();
        // cout << "\n\ntanda\n";
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int K = 0;
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (ttd % 2 == 1)
            {
                // cout << "PP" << endl;
                if (visited[adj[u][i]] == false)
                {
                    if (src == temp)
                    {
                        visited[adj[u][i]] = true;
                        dist[adj[u][i]] = dist[u] + 1;
                        pred[adj[u][i]] = u;
                        // cout << "u: " << u << endl;
                        K = adj[u][i];
                        if (K > mini)
                        {
                            mini = K;
                        }
                        K = mini;
                        // cout << "mini :" << mini << "\n";
                        //  if (adj[u][i] > 3)
                        //  {
                        //      queue.push_back(adj[u][i]);
                        //  }
                        queue.push_back(adj[u][i]);
                        //  cout << "adj: " << adj[u][i] << endl;
                        if (adj[u][i] == dest)
                            return true;
                    }
                }
            }
            else
            {
                // cout << "KK" << endl;
                if (visited[adj[u][i]] == false)
                {
                    if (src == temp)
                    {
                        visited[adj[u][i]] = true;
                        dist[adj[u][i]] = dist[u] + 1;
                        pred[adj[u][i]] = u;
                        // cout << "u: " << u << endl;
                        K = adj[u][i];
                        if (K < maxi)
                        {
                            maxi = K;
                        }
                        K = maxi;
                        // cout << "maxi:" << maxi << "\n";
                        // if (adj[u][i] > 3)
                        // {
                        //     queue.push_back(adj[u][i]);
                        // }
                        queue.push_back(adj[u][i]);
                        // cout << "adj: " << adj[u][i] << endl;
                        if (adj[u][i] == dest)
                            return true;
                    }
                }
            }
        }
        if (K == 0)
        {
            continue;
        }
        ttd++;
        // cout << "K: " << K << endl;
        //  queue.push_back(K);
    }
    return false;
}
void BFS1(vector<int> adj[], int src, int dest, int v, int pred[], int dist[])
{
    list<int> queue;
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    visited[src] = true;
    dist[src] = 0;
    int temp = src;

    queue.push_back(src);
    int ttd = 0;
    printf("%d", src);
    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop_front();
        // cout << "\n\ntanda\n";
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int K = 0;
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (ttd % 2 == 1)
            {
                // cout << "PP" << endl;
                if (visited[adj[u][i]] == false)
                {
                    if (src == temp)
                    {
                        visited[adj[u][i]] = true;
                        dist[adj[u][i]] = dist[u] + 1;
                        pred[adj[u][i]] = u;
                        // cout << "u: " << u << endl;
                        K = adj[u][i];
                        if (K > mini)
                        {
                            mini = K;
                        }
                        K = mini;
                        // cout << "mini :" << mini << "\n";
                        //  if (adj[u][i] > 3)
                        //  {
                        //      queue.push_back(adj[u][i]);
                        //  }
                        queue.push_back(adj[u][i]);
                        //  cout << "adj: " << adj[u][i] << endl;
                        if (adj[u][i] == dest)
                        {
                            cout << " -> " << dest << "\n";
                            return;
                        }
                    }
                }
            }
            else
            {
                // cout << "KK" << endl;
                if (visited[adj[u][i]] == false)
                {
                    if (src == temp)
                    {
                        visited[adj[u][i]] = true;
                        dist[adj[u][i]] = dist[u] + 1;
                        pred[adj[u][i]] = u;
                        // cout << "u: " << u << endl;
                        K = adj[u][i];
                        if (K < maxi)
                        {
                            maxi = K;
                        }
                        K = maxi;
                        // cout << "maxi:" << maxi << "\n";
                        // if (adj[u][i] > 3)
                        // {
                        //     queue.push_back(adj[u][i]);
                        // }
                        queue.push_back(adj[u][i]);
                        // cout << "adj: " << adj[u][i] << endl;
                        if (adj[u][i] == dest)
                        {
                            cout << " -> " << dest << "\n";
                            return;
                        }
                    }
                }
            }
        }
        if (K == 0)
        {
            continue;
        }
        ttd++;
        cout << " -> " << K;
        // queue.push_back(K);
    }
    cout << " -> " << dest << "\n";
    return;
}

void printShortestDistance(vector<int> adj[], int s, int dest, int v)
{
    int pred[v], dist[v];
    if (BFS(adj, s, dest, v, pred, dist) == false)
    {
        cout << "Path tidak ditemukan\n";
        return;
    }
    BFS1(adj, s, dest, v, pred, dist);
    // vector<int> path;
    // int crawl = dest;
    // // cout << "pola :";
    // // for (int i = 0; i < v; i++)
    // // {
    // //     cout << pred[i] << " ";
    // // }
    // // cout << "\n";
    // path.push_back(crawl);
    // while (pred[crawl] != -1)
    // {
    //     path.push_back(pred[crawl]);
    //     crawl = pred[crawl];
    // }
    // // cout << "Shortest path length is : " << dist[dest];
    // // cout << "\nPath is::\n";
    // for (int i = path.size() - 1; i >= 0; i--)
    // {
    //     cout << path[i];
    //     if (i != 0)
    //     {
    //         cout << " -> ";
    //     }
    // }
    // cout << "\n";
}
int main()
{
    int v;
    cin >> v;
    v = v + 1;
    vector<int> adj[v];
    set<pair<int, int>> S;
    pair<int, int> P;
    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1)
        {
            break;
        }
        if (a == b)
        {
            continue;
        }
        P = make_pair(a, b);
        S.insert(P);
    }
    for (auto i = S.begin(); i != S.end(); i++)
    {
        int x = i->first;
        int y = i->second;
        add_edge(adj, x, y);
    }

    while (1)
    {
        int source, dest;
        cin >> source >> dest;
        if (source == -1 && dest == -1)
        {
            break;
        }
        if (source == dest)
        {
            cout << source << "\n";
            continue;
        }
        printShortestDistance(adj, source, dest, v);
    }
    return 0;
}
