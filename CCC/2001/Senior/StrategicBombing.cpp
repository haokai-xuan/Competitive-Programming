#include <bits/stdc++.h>
using namespace std;

bool disconnected(vector<int> adj[], string edge)
{

    int node1 = edge[0] - 'A';
    int node2 = edge[1] - 'A';
    bool visited[26] = {false};

    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int s = q.front();
        q.pop();

        if (!visited[s])
        {
            visited[s] = true;
            for (int i = 0; i < adj[s].size(); i++)
            {
                if (!(s == node1 && adj[s][i] == node2 || s == node2 && adj[s][i] == node1))
                {
                    q.push(adj[s][i]);
                }
            }
        }
    }

    return !visited['B' - 'A'];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> edges;
    vector<int> adj[26];

    string input;
    cin >> input;

    while (input != "**")
    {
        edges.push_back(input);
        adj[input[0] - 'A'].push_back(input[1] - 'A');
        adj[input[1] - 'A'].push_back(input[0] - 'A');
        cin >> input;
    }
    int cnt = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        if (disconnected(adj, edges[i]))
        {
            cnt++;
            cout << edges[i] << '\n';
        }
    }

    cout << "There are " << cnt << " disconnecting roads.\n";

    return 0;
}