#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>
    adj = {
        {},
        {6},
        {6},
        {4, 5, 6, 15},
        {3, 5, 6},
        {3, 4, 6},
        {1, 2, 3, 4, 5, 7},
        {6, 8},
        {7, 9},
        {8, 10, 12},
        {9, 11},
        {10, 12},
        {9, 11, 13},
        {12, 14, 15},
        {13},
        {3, 13},
        {17, 18},
        {16, 18},
        {16, 17},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
};

int bfs(int x, int y)
{
    queue<int> q;
    q.push(x);

    unordered_map<int, int> visited;
    visited.insert({x, 0});

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == y)
        {
            return visited[curr];
        }

        for (int neighbour : adj[curr])
        {
            if (!visited.count(neighbour))
            {
                visited[neighbour] = visited[curr] + 1;
                q.push(neighbour);
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char cmd;
    int x, y;
    set<int> friends_of_friends;
    bool run = true;

    while (run)
    {
        cin >> cmd;
        if (cmd == 'i')
        {
            cin >> x >> y;

            if (find(adj[x].begin(), adj[x].end(), y) == adj[x].end())
            {
                adj[x].push_back(y);
            }
            if (find(adj[y].begin(), adj[y].end(), x) == adj[y].end())
            {
                adj[y].push_back(x);
            }
        }
        else if (cmd == 'd')
        {
            cin >> x >> y;

            auto it = find(adj[x].begin(), adj[x].end(), y);
            if (it != adj[x].end())
            {
                adj[x].erase(it);
            }

            it = find(adj[y].begin(), adj[y].end(), x);
            if (it != adj[y].end())
            {
                adj[y].erase(it);
            }
        }
        else if (cmd == 'n')
        {
            cin >> x;

            cout << adj[x].size() << '\n';
        }
        else if (cmd == 'f')
        {
            cin >> x;

            for (int friend_of_x : adj[x])
            {
                friends_of_friends.insert(adj[friend_of_x].begin(), adj[friend_of_x].end());
            }

            friends_of_friends.erase(x);
            for (int friend_of_x : adj[x])
            {
                friends_of_friends.erase(friend_of_x);
            }

            cout << friends_of_friends.size() << '\n';
            friends_of_friends.clear();
        }
        else if (cmd == 's')
        {
            cin >> x >> y;
            int ans = bfs(x, y);

            if (ans == -1)
            {
                cout << "Not connected" << '\n';
            }
            else
            {
                cout << ans << '\n';
            }
        }
        else if (cmd == 'q')
            run = false;
    }

    return 0;
}