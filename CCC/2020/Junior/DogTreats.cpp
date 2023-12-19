#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short s, m, l;
    cin >> s >> m >> l;

    if (s + 2 * m + 3 * l >= 10)
        cout << "happy" << '\n';
    else
        cout << "sad" << '\n';
}