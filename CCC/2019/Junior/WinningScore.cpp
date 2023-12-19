#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short a1, a2, a3;
    short b1, b2, b3;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    short atot = 0;
    short btot = 0;
    atot += 3 * a1 + 2 * a2 + a3;
    btot += 3 * b1 + 2 * b2 + b3;

    if (atot > btot)
    {
        cout << 'A' << '\n';
    }
    else if (btot > atot)
    {
        cout << 'B' << '\n';
    }
    else
    {
        cout << 'T' << '\n';
    }
}