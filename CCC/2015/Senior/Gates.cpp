// TLE on DMOJ 15/30

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int g, p;
    cin >> g >> p;

    set<int> gates;
    for (int i = p; i >= 1; i--)
    {
        gates.insert(-i);
    }

    // cout << "gates: ";
    // for (int i : gates)
    //     cout << i << ' ';
    // cout << '\n';

    int x, ans = 0;
    for (int i = 0; i < p; i++)
    {
        cin >> x;
        auto it = gates.lower_bound(-x);
        if (it == gates.end())
            break;
        ans++;
        gates.erase(it);
    }
    cout << ans;
    return 0;
}