#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int p, c;
    cin >> p >> c;

    cout << (p > c ? p * 50 - c * 10 + 500 : p * 50 - c * 10) << '\n';

    return 0;
}