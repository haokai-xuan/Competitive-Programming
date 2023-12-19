#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;

    for (int j = 0; j < n; j++)
    {
        getline(cin >> ws, s);
        for (int i = 0; i < s.length(); i++)
        {
            if ((isalpha(s[0]) && s[4] == ' '))
            {
                s[0] = '*';
                s[1] = '*';
                s[2] = '*';
                s[3] = '*';
            }
            if (s[i] == ' ' && isalpha(s[i + 1]) && s[i + 5] == ' ')
            {
                s[i + 1] = '*';
                s[i + 2] = '*';
                s[i + 3] = '*';
                s[i + 4] = '*';
            }
            if (isalpha(s[s.length() - 1]) && s[s.length() - 5] == ' ')
            {
                s[s.length() - 1] = '*';
                s[s.length() - 2] = '*';
                s[s.length() - 3] = '*';
                s[s.length() - 4] = '*';
            }
            if (s.length() == 4)
            {
                s = "****";
            }
        }
        cout << s << '\n';
        s.clear();
    }

    return 0;
}