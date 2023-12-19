#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[n][n] = {0};

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        const int a = x, b = y;

        while (x <= n && y <= n && x > 0 && y > 0)
        {
            arr[x - 1][y - 1] = 1;
            x++;
            y++;
        }
        x = a;
        y = b;
        while (x <= n && y <= n && x > 0 && y > 0)
        {
            arr[x - 1][y - 1] = 1;
            x++;
            y--;
        }
        x = a;
        y = b;
        while (x <= n && y <= n && x > 0 && y > 0)
        {
            arr[x - 1][y - 1] = 1;
            x--;
            y++;
        }
        x = a;
        y = b;
        while (x <= n && y <= n && x > 0 && y > 0)
        {
            arr[x - 1][y - 1] = 1;
            x--;
            y--;
        }
        x = a;
        y = b;
        while (x <= n && y <= n && x > 0 && y > 0)
        {
            arr[x - 1][y - 1] = 1;
            x--;
        }
        x = a;
        y = b;
        while (x <= n && y <= n && x > 0 && y > 0)
        {
            arr[x - 1][y - 1] = 1;
            y--;
        }
        x = a;
        y = b;
        while (x <= n && y <= n && x > 0 && y > 0)
        {
            arr[x - 1][y - 1] = 1;
            x++;
        }
        x = a;
        y = b;
        while (x <= n && y <= n && x > 0 && y > 0)
        {
            arr[x - 1][y - 1] = 1;
            y++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 1)
                cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}