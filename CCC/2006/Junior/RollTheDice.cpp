#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    int ways = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i + j == 10)
                ways++;
        }
    }
    if (ways != 1)
        cout << "There are " << ways << " ways to get the sum 10.";
    else
        cout << "There is " << ways << " way to get the sum 10.";
    return 0;
}
