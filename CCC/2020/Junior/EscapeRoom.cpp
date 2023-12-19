#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> grid[1000003];
bool visited[1000003];

void dfs(int node)
{
    if (visited[node])
        return;
    visited[node] = true;

    if (node == m * n)
    {
        cout << "yes" << '\n';
        exit(EXIT_SUCCESS);
    }

    for (auto u : grid[node])
    {
        dfs(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int node;
            cin >> node;
            grid[i * j].push_back(node);
        }
    }
    dfs(1);
    cout << "no" << '\n';
    return 0;
}