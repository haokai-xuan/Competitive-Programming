#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
vector<int> adj[N];
bool vis[N];

bool dfs(int start, int end)
{
    vis[start] = true;
    for (int i = 0; i < adj[start].size(); i++)
    {
        if (adj[start][i] == end)
            return true;
        if (!vis[adj[start][i]] && dfs(adj[start][i], end))
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, x, y, p, q;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[y].push_back(x);
    }

    cin >> p >> q;

    memset(vis, false, sizeof vis);
    if (dfs(q, p))
    {
        cout << "yes" << '\n';
    }
    else
    {
        memset(vis, false, sizeof vis);
        if (dfs(p, q))
            cout << "no" << '\n';
        else
            cout << "unknown" << '\n';
    }

    return 0;
}