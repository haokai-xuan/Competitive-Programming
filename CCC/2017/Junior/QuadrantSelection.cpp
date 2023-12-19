#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short num1, num2;
    cin >> num1 >> num2;

    if (num1 > 0 && num2 > 0)
        cout << 1 << '\n';

    else if (num1 < 0 && num2 > 0)
        cout << 2 << '\n';
    else if (num1 < 0 && num1 < 0)
        cout << 3 << '\n';
    else
        cout << 4 << '\n';
}