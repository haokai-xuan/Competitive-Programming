#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    int n;
    cin >> n;
    int cnt = 0;

    for (int i = 0; i <= n / 4; i++)
    {
        if ((n - 4 * i) % 5 == 0)
        {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}