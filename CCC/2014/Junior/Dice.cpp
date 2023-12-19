#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> play;

    int antonia = 100;
    int david = 100;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        play.push_back(make_pair(x, y));
    }
    for (int i = 0; i < n; i++)
    {
        if (play[i].first > play[i].second)
        {
            david -= play[i].first;
        }
        else if (play[i].second > play[i].first)
        {
            antonia -= play[i].second;
        }
    }
    cout << antonia << endl
         << david << '\n';
    return 0;
}