#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, m;
    cin >> h >> m;
    for (int i = 1; i <= m; i++)
    {
        if (-6 * pow(i, 4) + h * pow(i, 3) + 2 * (i, 2) + i <= 0)
        {
            cout << "The balloon first touches ground at hour:" << '\n';
            cout << i << '\n';
            return 0;
        }
    }
    cout << "The balloon does not touch ground in the given time." << '\n';
    return 0;
}