#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m; // m lines of incout <<
    cin >> m;

    char command; // the type of command
    int x;        // x is the number of the friend
    int time = 0; // the total time taken
    int r[101] = {0};
    int s[101] = {0};
    int f[101] = {0};

    for (int i = 0; i < m; i++)
    {
        cin >> command >> x;
        if (command == 'R')
        {
            r[x] = -1;
            s[x] = time;
        }
        else if (command == 'S')
        {
            f[x] += time - s[x];
            r[x] = 1;
        }
        else
        {
            time += x - 2;
        }
        time++;
    }

    for (int i = 0; i < 101; i++)
    {
        if (r[i] != 0)
        {
            if (r[i] > 0)
                cout << i << ' ' << f[i] << '\n';
            else
                cout << i << ' ' << r[i] << '\n';
        }
    }
    return 0;
}