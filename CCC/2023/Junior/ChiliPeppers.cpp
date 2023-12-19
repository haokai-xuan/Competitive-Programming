#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> mp = {
        {"Poblano", 1500},
        {"Mirasol", 6000},
        {"Serrano", 15500},
        {"Cayenne", 40000},
        {"Thai", 75000},
        {"Habanero", 125000},
    };

    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ans += mp[s];
    }

    cout << ans << '\n';

    return 0;
}