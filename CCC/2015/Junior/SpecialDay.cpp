#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short month, day;

    cin >> month >> day;

    if (month == 2 && day < 18)
        cout << "Before" << '\n';
    else if (month < 2)
        cout << "Before" << '\n';
    else if (month == 2 && day > 18)
        cout << "After" << '\n';
    else if (month > 2)
        cout << "After" << '\n';
    else
        cout << "Special" << '\n';
}