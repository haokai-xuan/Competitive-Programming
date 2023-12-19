#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int j, a;
    cin >> j >> a;

    char jersey_sizes[j];
    for (int i = 0; i < j; i++)
    {
        cin >> jersey_sizes[i];
    }

    char c;
    int num, satisfied = 0;
    for (int i = 0; i < a; i++)
    {
        cin >> c >> num;

        num -= 1;

        if (jersey_sizes[num] != 'F')
        {
            if (c == jersey_sizes[num] || c == 'S' || (c == 'M' && jersey_sizes[num] == 'L'))
            {
                satisfied++;
                jersey_sizes[num] = 'F';
            }
        }
    }
    cout << satisfied << '\n';
    return 0;
}