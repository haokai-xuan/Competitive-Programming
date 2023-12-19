#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if (b <= a)
        cout << "Congratulations, you are within the speed limit!";
    else if ((b - a >= 1) && (b - a <= 20))
        cout << "You are speeding and your fine is $100.";
    else if ((b - a >= 21) && (b - a <= 30))
        cout << "You are speeding and your fine is $270.";
    else if (b - a >= 31)
        cout << "You are speeding and your fine is $500.";

    return 0;
}