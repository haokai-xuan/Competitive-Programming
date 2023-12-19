#include <bits/stdc++.h>
using namespace std;

// if this function returns false, the first argument should be placed after the second
// if this function returns true, the first argument should be placed before the second
bool comparator(pair<string, int> computer1, pair<string, int> computer2)
{
    if (computer1.second == computer2.second)
    {
        return computer1.first < computer2.first;
    }
    return computer1.second > computer2.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        string s;
        cin >> s;
        cout << s;
        return 0;
    }

    vector<pair<string, int>> computer(n);

    for (int i = 0; i < n; i++)
    {
        string name;
        int r, s, d;
        cin >> name >> r >> s >> d;

        computer.push_back({name, 2 * r + 3 * s + d});
    }

    sort(computer.begin(), computer.end(), comparator);

    cout << computer[0].first << '\n'
         << computer[1].first << '\n';

    return 0;
}