#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string t, s;
    cin >> t >> s;
    bool found = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (t.find(s) != string::npos)
        {
            found = true;
            break;
        }
        string newstr = s.substr(1) + s[0];
        s = newstr;
    }
    if (found)
    {
        cout << "yes" << '\n';
    }
    else
    {
        cout << "no" << '\n';
    }
    return 0;
}