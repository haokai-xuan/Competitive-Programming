#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int cnt = 0;
    for (int i = 1; i < 22; i++)
    {
        int n = i * i * i * i * i * i;
        if (n > b)
        {
            break;
        }
        if (n >= a)
        {
            cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}