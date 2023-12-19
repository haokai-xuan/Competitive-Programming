#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int pos = 1;
    map<int, int> mp = {
        {54, 19},
        {90, 48},
        {99, 77},
        {9, 34},
        {40, 64},
        {67, 86}};

    while (pos != 100)
    {
        int dice_value;
        cin >> dice_value;

        if (dice_value == 0)
        {
            cout << "You Quit!" << '\n';
            return 0;
        }

        if (pos + dice_value > 100)
        {
            cout << "You are now on square " << pos << '\n';
            continue;
        }
        else
        {
            pos += dice_value;
        }

        if (mp.count(pos) > 0)
        {
            pos = mp[pos];
        }

        if (pos == 100)
        {
            cout << "You are now on square " << pos << '\n';
            cout << "You Win!" << '\n';
            return 0;
        }
        else
        {
            cout << "You are now on square " << pos << '\n';
        }
    }
}