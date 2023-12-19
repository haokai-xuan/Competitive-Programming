#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
int row, col;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int room_num)
{
    if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 0)
    {
        grid[x][y] = room_num;
        for (int i = 0; i < 4; i++)
            dfs(x + dx[i], y + dy[i], room_num);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int flooring;
    cin >> flooring;

    cin >> row >> col;

    char c;
    vector<int> temp;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> c;
            if (c == '.')
                temp.push_back(0);
            else
                temp.push_back(-1);
        }
        grid.push_back(temp);
        temp.clear();
    }

    int room_num = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 0)
            {
                dfs(i, j, room_num);
                room_num++;
            }
        }
    }

    int largest_room_area[room_num] = {0};

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] > 0)
                largest_room_area[grid[i][j]]++;
        }
    }

    sort(largest_room_area, largest_room_area + room_num, greater<int>());

    int rooms_covered = 0;
    for (int i : largest_room_area)
    {
        if (flooring - i < 0 || i == 0)
            break;
        flooring -= i;
        rooms_covered++;
    }

    rooms_covered == 1 ? cout << rooms_covered << " room, " : cout << rooms_covered << " rooms, ";
    cout << flooring << " square metre(s) left over" << '\n';

    return 0;
}