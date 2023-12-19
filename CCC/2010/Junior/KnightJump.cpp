#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y)
{
    if (x >= 1 && x <= 8 && y >= 1 && y <= 8)
        return true;
    return false;
}

int bfs(int startX, int startY, int endX, int endY)
{
    queue<pair<int, int>> q;
    q.push({startX, startY});

    vector<vector<int>> dist(9, vector<int>(9, -1));
    dist[startX][startY] = 0;

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        int x = node.first;
        int y = node.second;

        if (x == endX && y == endY)
        {
            return dist[x][y];
        }

        if (isValid(x + 1, y + 2))
        {
            // cout << 'valid: ' << x + 1 << ", " << y + 2;
            if (dist[x + 1][y + 2] == -1)
            {
                // cout << 'not visited: ' << x + 1 << ", " << y + 2;

                dist[x + 1][y + 2] = dist[x][y] + 1;
                q.push({x + 1, y + 2});
            }
        }

        if (isValid(x + 2, y + 1))
        {
            if (dist[x + 2][y + 1] == -1)
            {
                dist[x + 2][y + 1] = dist[x][y] + 1;
                q.push({x + 2, y + 1});
            }
        }

        if (isValid(x + 2, y - 1))
        {
            if (dist[x + 2][y - 1] == -1)
            {
                dist[x + 2][y - 1] = dist[x][y] + 1;
                q.push({x + 2, y - 1});
            }
        }

        if (isValid(x + 1, y - 2))
        {
            if (dist[x + 1][y - 2] == -1)
            {
                dist[x + 1][y - 2] = dist[x][y] + 1;
                q.push({x + 1, y - 2});
            }
        }

        if (isValid(x - 1, y - 2))
        {
            if (dist[x - 1][y - 2] == -1)
            {
                dist[x - 1][y - 2] = dist[x][y] + 1;
                q.push({x - 1, y - 2});
            }
        }

        if (isValid(x - 2, y - 1))
        {
            if (dist[x - 2][y - 1] == -1)
            {
                dist[x - 2][y - 1] = dist[x][y] + 1;
                q.push({x - 2, y - 1});
            }
        }

        if (isValid(x - 2, y + 1))
        {
            if (dist[x - 2][y + 1] == -1)
            {
                dist[x - 2][y + 1] = dist[x][y] + 1;
                q.push({x - 2, y + 1});
            }
        }

        if (isValid(x - 1, y + 2))
        {
            if (dist[x - 1][y + 2] == -1)
            {
                dist[x - 1][y + 2] = dist[x][y] + 1;
                q.push({x - 1, y + 2});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int startX, startY;
    cin >> startX >> startY;

    int endX, endY;
    cin >> endX >> endY;

    cout << bfs(startX, startY, endX, endY) << '\n';

    return 0;
}