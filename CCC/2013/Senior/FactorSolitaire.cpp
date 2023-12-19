#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, ans = 0;

    cin >> c;
    while (c != 1)
    {
        a = 1;
        b = c;
        for (int i = 2; i * i <= c; i++)
        {
            if (c % i == 0)
            {
                b = i;
                a = c / b;
                break;
            }
        }
        c = a * (b - 1);
        ans += b - 1;
    }
    cout << ans << '\n';
    return 0;
}