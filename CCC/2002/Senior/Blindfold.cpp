#include <bits/stdc++.h>
using namespace std;

// UNFINISHED, TLE LAST 2 TEST CASES

int row, col, num_of_moves;
char moves[30000];
vector<vector<char>> grid;

void solve(int r, int c, int dir)
{
    int k = 0;

    while (r >= 0 && r < row && c >= 0 && c < col && k < num_of_moves && (grid[r][c] == '.' || grid[r][c] == '*'))
    {
        if (moves[k] == 'R')
        {
            dir = (dir + 90) % 360;
        }
        else if (moves[k] == 'L')
        {
            dir -= 90;
            if (dir == -90)
                dir = 270;
        }
        else if (moves[k] == 'F')
        {
            if (dir == 0)
            {
                r -= 1;
            }
            else if (dir == 90)
            {
                c += 1;
            }
            else if (dir == 180)
            {
                r += 1;
            }
            else
            {
                c -= 1;
            }
        }
        // cout << '(' << r << ',' << c << ')' << '\n';
        k++;
    }

    if (k >= num_of_moves && r >= 0 && r < row && c >= 0 && c < col &&
        grid[r][c] == '.')
        grid[r][c] = '*';
    // cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col;

    char ch;
    vector<char> temp;
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            cin >> ch;
            temp.push_back(ch);
        }
        grid.push_back(temp);
        temp.clear();
    }

    cin >> num_of_moves;

    for (int i = 0; i < num_of_moves; i++)
    {
        cin >> moves[i];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < 360; k += 90)
            {
                solve(i, j, k);
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << grid[i][j];
        }
        cout << '\n';
    }
    return 0;
}