#include <bits/stdc++.h>
using namespace std;

int k, n, m;
const int MAXN = 2005;

vector<pair<int, int>> adj[MAXN];
vector<pair<int, int>> hull[MAXN];

int dijkstra(int a, int b)
{
    int new_k = k;
    vector<int> dist(MAXN, INT_MAX);
    vector<bool> visited(MAXN, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pair {dist, node}

    dist[a] = 0;
    pq.push({0, a});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (int i = 0; i < adj[u].size(); i++)
        {
            int node = adj[u][i].first;
            int weight = adj[u][i].second;
            int new_dist = dist[u] + weight;

            if (new_dist < dist[node])
            {
                if (new_k - hull[u][i].second > 0)
                {
                    dist[node] = new_dist;
                    new_k -= hull[u][i].second;
                    pq.push({dist[node], node});
                }
            }
        }
    }

    if (dist[b] == INT_MAX)
        return -1;
    else
        return dist[b];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, t, h;
        cin >> a >> b >> t >> h;

        adj[a].push_back({b, t});
        adj[b].push_back({a, t});

        hull[a].push_back({b, h});
        hull[b].push_back({a, h});
    }

    int start, end;
    cin >> start >> end;

    cout << dijkstra(start, end) << '\n';

    return 0;
}