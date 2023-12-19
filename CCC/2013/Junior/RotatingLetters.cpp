#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    string str = "ABCDEFGJKLMPQRTUVWY";

    for (char c : s)
    {
        if (str.find(c) == -1)
        {
            continue;
        }
        else
        {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}