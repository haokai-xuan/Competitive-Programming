#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int j;
    cin >> j;

    if (j < 4)
    {
        cout << 0 << '\n';
        return 0;
    }
    else
    {
        if (j == 4)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << ((j - 3) * (j - 2) * (j - 1)) / 6 << '\n';
        }
    }

    return 0;
}