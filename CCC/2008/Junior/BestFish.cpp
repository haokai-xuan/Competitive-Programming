#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c, n, maxc = 0, maxn = 0;

    cin >> c;

    for (int i = 0; i < c; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 * c2 > maxc)
        {
            maxc = c1 * c2;
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        if (n1 * n2 > maxn)
        {
            maxn = n1 * n2;
        }
    }

    if (maxc == maxn)
    {
        cout << "Tie" << '\n';
    }
    else if (maxn > maxc)
    {
        cout << "Natalie" << '\n';
    }
    else if (maxc > maxn)
    {
        cout << "Casper" << '\n';
    }

    return 0;
}