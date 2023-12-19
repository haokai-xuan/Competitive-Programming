#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(nULL);
    cin.tie(0);

    short cperature;
    cin >> cperature;

    short ans = 5 * cperature - 400;
    cout << ans << '\n';

    if (ans < 100)
    {
        cout << 1 << '\n';
    }
    else if (ans > 100)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }

    return 0;
}