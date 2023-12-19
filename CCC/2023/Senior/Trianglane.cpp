#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c;
    cin >> c;

    int line1[c], line2[c];

    for (int i = 0; i < c; i++)
    {
        cin >> line1[i];
    }

    for (int i = 0; i < c; i++)
    {
        cin >> line2[i];
    }

    int cnt = 0;

    for (int i = 0; i < c; i++)
    {
        if (line1[i] == 1)
            cnt++;
        if (line2[i] == 1)
            cnt++;
    }

    cnt *= 3;

    for (int i = 0; i < c - 1; i++)
    {

        if (line1[i] == 1 && line1[i + 1] == 1)
        {
            cnt -= 2;
        }
        if (line2[i] == 1 && line2[i + 1] == 1)
        {
            cnt -= 2;
        }
    }

    for (int i = 0; i < c; i++)
    {
        if (line1[i] == 1 && line2[i] == 1 && i % 2 == 0)
        {
            cnt -= 2;
        }
    }

    cout << cnt << '\n';

    return 0;
}
