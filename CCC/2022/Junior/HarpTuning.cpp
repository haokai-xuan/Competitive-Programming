#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    string res;
    string str = "+-1234567890";
    for (int i = 0; i < s.length(); i++)
    {
        if (str.find(s[i]) == string::npos)
        {
            res.push_back(s[i]);
        }
        if (s[i] == '+')
        {
            string new_str;
            for (char c : s.substr(i + 1))
            {
                if (isdigit(c))
                {
                    new_str.push_back(c);
                }
                else
                {
                    break;
                }
            }
            cout << res << ' ' << "tighten" << ' ' << new_str << '\n';
            res.clear();
        }
        else if (s[i] == '-')
        {
            string new_str;
            for (char c : s.substr(i + 1))
            {
                if (isdigit(c))
                {
                    new_str.push_back(c);
                }
                else
                {
                    break;
                }
            }
            cout << res << ' ' << "loosen" << ' ' << new_str << '\n';
            res.clear();
        }
    }
    return 0;
}