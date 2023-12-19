#include <bits/stdc++.h>
using namespace std;

int r, l;

vector<int> solve(vector<vector<int>> grid, int k)
{
    for (int i = 1; i <= l; ++i)
    {
        if (grid[k][i] == grid[k + 1][i])
        {
            grid[k][i] = 0;
        }
        else
        {
            grid[k][i] = 1;
        }
    }
    if (k == 1)
    {
        return grid[1];
    }
    else
    {
        return solve(grid, k - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> l;

    vector<int> columns(l + 1, -1);
    vector<vector<int>> grid(r + 1, columns);

    for (int i = r; i > 0; i--)
    {
        for (int j = 1; j <= l; j++)
        {
            cin >> grid[i][j];
        }
    }

    // cout << '\n';
    // for (int i = r; i >= 0; i--)
    // {
    //     for (int j = 0; j <= l; j++)
    //     {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    set<vector<int>> ans;
    ans.insert(grid[1]);

    for (int i = 1; i < r; i++)
    {
        ans.insert(solve(grid, i));
    }

    cout << ans.size() << '\n';

    return 0;
}