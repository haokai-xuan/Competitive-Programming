#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, c;
    vector<int> chores;
    cin >> t >> c;

    for (int i = 0; i < c; i++)
    {
        int a;
        cin >> a;
        chores.push_back(a);
    }

    sort(chores.begin(), chores.end());

    int cnt = 0, sum = 0;
    while (cnt < chores.size() && sum <= t)
    {
        sum += chores[cnt];
        cnt++;
    }

    if (sum > t)
    {
        cout << cnt - 1 << '\n';
    }
    else
    {
        cout << cnt << '\n';
    }

    return 0;
}