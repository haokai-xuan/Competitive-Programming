#include <bits/stdc++.h>
using namespace std;

vector<int> book[10000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            book[i].push_back(x);
        }
        else
        {
            for (int j = 0; j < x; j++)
            {
                int num;
                cin >> num;
                book[i].push_back(num);
            }
        }
    }

    queue<int> q;
    q.push(1);
    bool visited[n + 1] = {false};
    int distance[n + 1] = {1};

    int shortest = n + 1;

    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        visited[s] = true;
        for (auto u : book[s])
        {
            if (visited[u])
                continue;

            visited[u] = true;
            distance[u] = distance[s] + 1;
            if (u == 0)
            {
                shortest = min(shortest, distance[u]);
            }
            q.push(u);
        }
    }
    bool allvisited = true;
    for (auto x : visited)
    {
        if (!x)
        {
            allvisited = false;
            break;
        }
    }

    cout << (allvisited ? 'Y' : 'n') << '\n';

    cout << shortest << '\n';
    return 0;
}