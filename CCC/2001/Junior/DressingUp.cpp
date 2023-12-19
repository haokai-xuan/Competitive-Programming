#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i += 2)
    {
        cout << string(i, '*') << string(2 * n - i * 2, ' ') << string(i, '*') << '\n';
    }
    for (int i = n - 2; i >= 1; i -= 2)
    {
        cout << string(i, '*') << string(2 * n - i * 2, ' ') << string(i, '*') << '\n';
    }
    return 0;
}