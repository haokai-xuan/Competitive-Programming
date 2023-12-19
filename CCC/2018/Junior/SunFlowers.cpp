#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int grid[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int i, j;

    if (grid[0][0] < grid[0][n - 1])
        j = 0;
    else
        j = n - 1;

    if (grid[0][j] < grid[n - 1][j])
        i = 0;
    else
        i = n - 1;

    if (i == 0 && j == 0)
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                cout << grid[x][y] << ' ';
            }
            cout << '\n';
        }
    }

    else if (i == 0 && j == n - 1)
    {
        for (int y = n - 1; y >= 0; y--)
        {
            for (int x = 0; x < n; x++)
            {
                cout << grid[x][y] << ' ';
            }
            cout << '\n';
        }
    }

    else if (i == n - 1 && j == n - 1)
    {
        for (int x = n - 1; x >= 0; x--)
        {
            for (int y = n - 1; y >= 0; y--)
            {
                cout << grid[x][y] << ' ';
            }
            cout << '\n';
        }
    }
    else
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = n - 1; y >= 0; y--)
            {
                cout << grid[y][x] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}