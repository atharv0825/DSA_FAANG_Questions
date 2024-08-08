#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, int m, int src, vector<vector<int>> &edges)
{
    vector<int> dis(n + 1, 1e8);
    dis[src] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dis[u] != 1e8 && ((dis[u] + wt) < dis[v]))
            {
                dis[v] = dis[u] + wt;
            }
        }
    }

    bool flag = false;
    for (int j = 0; j < n; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dis[u] != 1e8 && ((dis[u] + wt) < dis[v]))
        {
            flag = true;
        }
    }

    if(!flag)
        return dis;
    else
        return vector<int>(1,-1);

}

int main()
{
    int n = 3; // vertex
    int m = 3; // edges
    int src = 1;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 3, -1},
        {3, 1, 2}};

    vector<int> result = bellmanFord(n, m, src, edges);

    if (result.size() == 1 && result[0] == -1)
    {
        cout << "Negative cycle detected" << endl;
    }
    else
    {
        cout<<"Shortest Distance : ";
        for (int i = 1; i <= n; i++)
        {
            cout <<result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}