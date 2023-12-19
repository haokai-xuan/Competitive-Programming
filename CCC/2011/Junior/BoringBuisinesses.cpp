#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<pair<int, int>, bool> ground;

    for (int col = -200; col <= 200; ++col)
    {
        for (int row = -1; row >= -201; --row)
        {
            ground[{col, row}] = false;
        }
    }

    ground[{0, -1}] = true;
    ground[{0, -2}] = true;
    ground[{0, -3}] = true;
    ground[{1, -3}] = true;
    ground[{2, -3}] = true;
    ground[{3, -3}] = true;
    ground[{3, -4}] = true;
    ground[{3, -5}] = true;
    ground[{4, -5}] = true;
    ground[{5, -5}] = true;
    ground[{5, -4}] = true;
    ground[{5, -3}] = true;
    ground[{6, -3}] = true;
    ground[{7, -3}] = true;
    ground[{7, -4}] = true;
    ground[{7, -5}] = true;
    ground[{7, -6}] = true;
    ground[{7, -7}] = true;
    ground[{6, -7}] = true;
    ground[{5, -7}] = true;
    ground[{4, -7}] = true;
    ground[{3, -7}] = true;
    ground[{2, -7}] = true;
    ground[{1, -7}] = true;
    ground[{0, -7}] = true;
    ground[{-1, -7}] = true;
    ground[{-1, -6}] = true;
    ground[{-1, -5}] = true;

    pair<int, int> curr = {-1, -5};

    bool stop = false;

    char c;
    int i;

    while (true)
    {
        cin >> c >> i;

        if (c == 'q' || stop)
            break;

        short dirC = 0, dirR = 0;
        if (c == 'u')
            dirR = 1;
        else if (c == 'd')
            dirR = -1;
        else if (c == 'r')
            dirC = 1;
        else if (c == 'l')
            dirC = -1;

        while (i > 0)
        {
            curr.first += dirC;
            curr.second += dirR;
            if (ground[{curr.first, curr.second}] == true)
                stop = true;
            else
                ground[{curr.first, curr.second}] = true;
            i--;
        }
        if (stop != true)
            cout << curr.first << ' ' << curr.second << ' ' << "safe" << '\n';
        else
            cout << curr.first << ' ' << curr.second << ' ' << "DANGER" << '\n';
    }

    return 0;
}