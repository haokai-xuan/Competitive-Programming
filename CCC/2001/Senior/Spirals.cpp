#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int start, end_;
    int curr_row = 4, curr_col = 4;
    int spiral[10][10] = {{0}};

    cin >> start >> end_;
    if (start == end_)
    {
        cout << start << '\n';
        return 0;
    }

    int k = 1, cnt = start;
    spiral[curr_row][curr_col] = start;

    bool exit = false;

    while (true)
    {
        for (int i = 0; i < k; i++)
        {
            curr_row++;
            cnt++;
            spiral[curr_row][curr_col] = cnt;
            if (cnt == end_)
            {
                exit = true;
                break;
            }
        }

        if (exit)
            break;

        for (int i = 0; i < k; i++)
        {
            curr_col++;
            cnt++;
            spiral[curr_row][curr_col] = cnt;
            if (cnt == end_)
            {
                exit = true;
                break;
            }
        }
        if (exit)
            break;
        k++;

        for (int i = 0; i < k; i++)
        {
            curr_row--;
            cnt++;
            spiral[curr_row][curr_col] = cnt;
            if (cnt == end_)
            {
                exit = true;
                break;
            }
        }

        if (exit)
            break;

        for (int i = 0; i < k; i++)
        {
            curr_col--;
            cnt++;
            spiral[curr_row][curr_col] = cnt;
            if (cnt == end_)
            {
                exit = true;
                break;
            }
        }
        if (exit)
            break;
        k++;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (spiral[i][j] == 0)
                cout << "   ";
            else
                cout << spiral[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}