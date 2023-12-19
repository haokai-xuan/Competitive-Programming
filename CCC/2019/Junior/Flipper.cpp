#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int grid[2][2];
    grid[0][0] = 1;
    grid[0][1] = 2;
    grid[1][0] = 3;
    grid[1][1] = 4;

    string s;
    cin >> s;
    for (char c : s)
    {
        if (c == 'H')
        {
            swap(grid[0][0], grid[1][0]);
            swap(grid[0][1], grid[1][1]);
        }
        else
        {
            swap(grid[0][1], grid[0][0]);
            swap(grid[1][1], grid[1][0]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}