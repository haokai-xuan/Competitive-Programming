#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int daytime, evening, weekend;
    cin >> daytime >> evening >> weekend;

    float a = 0, b = 0;

    if (daytime - 100 <= 0)
    {
        a += 0;
    }
    else
    {
        a += (daytime - 100) * 0.25;
    }

    if (daytime - 250 <= 0)
    {
        b += 0;
    }
    else
    {
        b += (daytime - 250) * 0.45;
    }

    a += (0.15 * evening) + (0.2 * weekend);
    b += (0.35 * evening) + (0.25 * weekend);

    cout << "Plan A costs " << fixed << setprecision(2) << a << '\n';
    cout << "Plan B costs " << fixed << setprecision(2) << b << '\n';
    if (a > b)
    {
        cout << "Plan B is cheapest.";
    }
    else if (b > a)
    {
        cout << "Plan A is cheapest.";
    }
    else
    {
        cout << "Plan A and B are the same price.";
    }

    return 0;
}