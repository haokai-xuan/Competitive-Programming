#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c, r;
    cin >> c >> r;

    pair<int, int> motion;
    cin >> motion.first >> motion.second;

    pair<int, int> pos = {0, 0};

    while (motion != make_pair(0, 0))
    {

        if (pos.first + motion.first > c)
        {
            pos.first = c;
        }
        if (pos.first + motion.first < 0)
        {
            pos.first = 0;
        }

        if (pos.second + motion.second > r)
        {
            pos.second = r;
        }
        if (pos.second + motion.second < 0)
        {
            pos.second = 0;
        }

        if (pos.first + motion.first <= c && pos.first + motion.first >= 0)
        {
            pos.first += motion.first;
        }
        if (pos.second + motion.second <= r && pos.second + motion.second >= 0)
        {
            pos.second += motion.second;
        }

        cout << pos.first << ' ' << pos.second << '\n';
        cin >> motion.first >> motion.second;
    }
    return 0;
}