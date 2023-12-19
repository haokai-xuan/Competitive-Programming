#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

char grid[102][102];
set<pii> cameras;
map<pii, int> cells;
map<pii, pii> conveyor;
bool vis[102][102];

void setCamera()
{
    vector<pii> invalid;
    for (pii p : cameras)
    {
        grid[p.first][p.second] = 'W';

        int cx = p.first, cy = p.second;
        while (grid[++cx][cy] != 'W')
            if (conveyor.find({cx, cy}) == conveyor.end())
                invalid.push_back({cx, cy});

        cx = p.first, cy = p.second;
        while (grid[--cx][cy] != 'W')
            if (conveyor.find({cx, cy}) == conveyor.end())
                invalid.push_back({cx, cy});

        cx = p.first, cy = p.second;
        while (grid[cx][++cy] != 'W')
            if (conveyor.find({cx, cy}) == conveyor.end())
                invalid.push_back({cx, cy});

        cx = p.first, cy = p.second;
        while (grid[cx][--cy] != 'W')
            if (conveyor.find({cx, cy}) == conveyor.end())
                invalid.push_back({cx, cy});
    }
    for (pii p : invalid)
    {
        grid[p.first][p.second] = 'W';
    }
}

pii conveyorMove(pii node)
{
    set<pii> seen;
    while (conveyor.find(node) != conveyor.end())
    {
        if (seen.find(node) != seen.end())
            node = {-1, -1};
        else
        {
            vis[node.first][node.second] = true;
            seen.insert(node);
            node = conveyor[node];
        }
    }

    return node;
}

bool isValid(int nx, int ny)
{
    if (conveyor.find({nx, ny}) != conveyor.end())
    {
        pii node = conveyorMove({nx, ny});
        if (node == pii{-1, -1})
            return false;
        nx = node.first;
        ny = node.second;
    }

    return (!vis[nx][ny] && grid[nx][ny] != 'W');
}

pii nextStep(int nnx, int nny, int dist)
{
    pii nextN = {nnx, nny};
    if (conveyor.find(nextN) != conveyor.end())
    {
        nextN = conveyorMove({nnx, nny});
        if (isValid(nextN.first, nextN.second))
        {
            if (cells.find(nextN) != cells.end())
                cells[nextN] = dist;

            vis[nextN.first][nextN.second] = true;
            return nextN;
        }
    }
    if (cells.find(nextN) != cells.end())
        cells[nextN] = dist;

    vis[nextN.first][nextN.second] = true;
    return nextN;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;

    pii start;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            char c;
            cin >> c;
            grid[i][j] = c;
            if (c == 'S')
            {
                start.first = i;
                start.second = j;
            }
            else if (c == '.')
                cells.insert({{{i, j}, -1}});
            else if (c == 'C')
                cameras.insert({i, j});
            else if (c == 'L')
                conveyor.insert({{i, j}, {i, j - 1}});
            else if (c == 'R')
                conveyor.insert({{i, j}, {i, j + 1}});
            else if (c == 'U')
                conveyor.insert({{i, j}, {i - 1, j}});
            else if (c == 'D')
                conveyor.insert({{i, j}, {i + 1, j}});
        }
    }

    setCamera();

    // if spawnpoint is under camera:
    if (grid[start.first][start.second] == 'W')
    {
        for (pair<pii, int> pp : cells)
            cout << pp.second << '\n';
        return 0;
    }

    queue<pii> q;
    q.push(start);
    vis[start.first][start.second] = true;

    int dist = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        dist++;
        for (int i = 0; i < qSize; i++)
        {
            pii node = q.front();
            q.pop();

            int nx = node.first, ny = node.second;
            if (isValid(nx + 1, ny))
                q.push(nextStep(nx + 1, ny, dist));
            if (isValid(nx - 1, ny))
                q.push(nextStep(nx - 1, ny, dist));
            if (isValid(nx, ny + 1))
                q.push(nextStep(nx, ny + 1, dist));
            if (isValid(nx, ny - 1))
                q.push(nextStep(nx, ny - 1, dist));
        }
    }
    for (pair<pii, int> pp : cells)
        cout << pp.second << '\n';
    return 0;
}