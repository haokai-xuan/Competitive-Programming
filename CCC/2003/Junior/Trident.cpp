#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, s, h;
    cin >> t >> s >> h;

    for (int i = 0; i < t; i++)
    {
        cout << '*' << string(s, ' ') << '*' << string(s, ' ') << '*' << '\n';
    }
    cout << string(3 + (s * 2), '*') << '\n';
    for (int i = 0; i < h; i++)
    {
        cout << string(1 + s, ' ') << '*' << '\n';
    }
    return 0;
}
