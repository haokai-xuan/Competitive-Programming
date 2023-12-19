#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int X, Y, G;
map<string, int> mp;

vector<pair<string, string>> group;
vector<pair<string, string>> ungroup;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nULL);

    cin >> X;
    for (int i = 0; i < X; ++i)
    {
        string a, b;
        cin >> a >> b;
        group.push_back({a, b});
    }
    cin >> Y;
    for (int i = 0; i < Y; ++i)
    {
        string a, b;
        cin >> a >> b;
        ungroup.push_back({a, b});
    }
    cin >> G;
    for (int i = 1; i <= G; ++i)
    {
        string a, b, c;
        cin >> a >> b >> c;
        mp[a] = mp[b] = mp[c] = i;
    }
    int cnt = 0;
    for (auto p : group)
    {
        if (mp[p.f] != mp[p.s])
            cnt++;
    }
    for (auto p : ungroup)
    {
        if (mp[p.f] == mp[p.s])
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}