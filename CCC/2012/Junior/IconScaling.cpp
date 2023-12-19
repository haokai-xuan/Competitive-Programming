#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    string star = "";
    string x = "";
    string space = "";

    for (int i = 0; i < k; i++)
    {
        star.push_back('*');
        x.push_back('x');
        space.push_back(' ');
    }

    for (int i = 0; i < k; i++)
    {
        cout << star << x << star << '\n';
    }

    for (int i = 0; i < k; i++)
    {
        cout << space << x << x << '\n';
    }

    for (int i = 0; i < k; i++)
    {
        cout << star << space << star << '\n';
    }
    return 0;
}