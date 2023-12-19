#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int radius;
    cin >> radius;

    while (radius != 0)
    {
        int pennies = 0;

        for (int i = 1; i <= radius; i++)
        {
            pennies += sqrt(radius * radius - i * i) + 1;
        }
        pennies = pennies * 4 + 1;

        cout << pennies << '\n';
        cin >> radius;
    }
    return 0;
}