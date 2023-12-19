#include <bits/stdc++.h>
using namespace std;

int x, m;
int ans;

bool solve()
{
    for (int i = 1; i < m; i++)
    {
        if ((x * i) % m == 1)
        {
            ans = i;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> m;
    if (solve())
    {
        cout << ans << '\n';
    }
    else
    {
        cout << "no such integer exists." << '\n';
    }
    return 0;
}