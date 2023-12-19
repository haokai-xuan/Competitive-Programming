#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;
    cin >> m >> n >> k;

    bool rows[m];
    bool cols[n];

    for (int i = 0; i < m; i++)
    {
        rows[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        cols[i] = false;
    }

    bool painting[m][n];

    for (int i = 0; i < k; i++)
    {
        char c;
        int num;
        cin >> c >> num;

        if (c == 'R')
        {
            rows[num - 1] = !rows[num - 1];
        }
        else
        {
            cols[num - 1] = !cols[num - 1];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            painting[i][j] = false;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (rows[i])
        {
            for (int j = 0; j < n; j++)
            {
                painting[i][j] = !painting[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (cols[i])
        {
            for (int j = 0; j < m; j++)
            {
                painting[j][i] = !painting[j][i];
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (painting[i][j] == true)
            {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}