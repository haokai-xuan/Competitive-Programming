#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int x = 0; x < t; x++)
    {
        int rows, cols;
        cin >> rows >> cols;

        vector<vector<char>> maze(rows, vector<char>(cols));
        vector<vector<int>> dist(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> maze[i][j];
                dist[i][j] = -1; // unvisited
            }
        }

        dist[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty())
        {
            pair<int, int> s = q.front();
            q.pop();

            int r = s.first;
            int c = s.second;

            // up
            if ((maze[r][c] == '+' || maze[r][c] == '|') && r > 0 && maze[r - 1][c] != '*' && dist[r - 1][c] == -1)
            {
                dist[r - 1][c] = dist[r][c] + 1;
                q.push({r - 1, c});
            }
            // down
            if ((maze[r][c] == '+' || maze[r][c] == '|') && r < rows - 1 && maze[r + 1][c] != '*' && dist[r + 1][c] == -1)
            {
                dist[r + 1][c] = dist[r][c] + 1;
                q.push({r + 1, c});
            }
            // right
            if ((maze[r][c] == '+' || maze[r][c] == '-') && c < cols - 1 && maze[r][c + 1] != '*' && dist[r][c + 1] == -1)
            {
                dist[r][c + 1] = dist[r][c] + 1;
                q.push({r, c + 1});
            }
            // left
            if ((maze[r][c] == '+' || maze[r][c] == '-') && c > 0 && maze[r][c - 1] != '*' && dist[r][c - 1] == -1)
            {
                dist[r][c - 1] = dist[r][c] + 1;
                q.push({r, c - 1});
            }
        }
        cout << dist[rows - 1][cols - 1] << '\n';
    }

    return 0;
}