#include <bits/stdc++.h>
using namespace std;

bool solve(int m, int x, int y)
{
    int length = pow(5, m - 1);

    if (x == 0 && y == 0)
        return false;

    int x1 = (int)x % length;
    int y1 = (int)y % length;

    x /= length;
    y /= length;

    if ((x > 0 && x < 4 && y == 0) || (x == 2 && y == 1))
        return true;
    if (((x == 1 || x == 3) && y == 1) || (x == 2 && y == 2))
        return solve(m - 1, x1, y1);
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    int m, x, y;

    for (int i = 0; i < t; i++)
    {
        cin >> m >> x >> y;

        if (solve(m, x, y))
        {
            cout << "crystal\n";
        }
        else
        {
            cout << "empty\n";
        }
    }

    return 0;
}
