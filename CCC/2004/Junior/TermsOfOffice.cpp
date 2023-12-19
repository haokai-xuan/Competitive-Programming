#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> x >> y;
    cout << "All positions change in year " << x << '\n';
    while (x + 60 <= y)
    {
        x += 60;
        cout << "All positions change in year " << x << '\n';
    }

    return 0;
}
