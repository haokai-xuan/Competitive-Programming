#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;
    int a = 0, b = 0;

    for (char c : s)
    {
        if (c == 'A')
            a++;
        else
            b++;
    }

    if (a > b)
        cout << "A" << '\n';
    else if (b > a)
        cout << "B" << '\n';
    else
        cout << "Tie" << '\n';
    return 0;
}