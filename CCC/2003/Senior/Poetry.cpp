#include <bits/stdc++.h>
using namespace std;

string lastSyllable(string s)
{
    int i = s.length() - 1;
    while (i != 0 && s[i] != ' ')
    {
        --i;
    }
    string lastword = s.substr(i + 1);

    if (s.find(' ') == string::npos)
    {
        return s;
    }

    else if (lastword.find('a') == string::npos && lastword.find('e') == string::npos && lastword.find('i') == string::npos && lastword.find('o') == string::npos && lastword.find('u') == string::npos)
    {
        return lastword;
    }
    else
    {
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                s = s.substr(i, s.size() - i);
                return s;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string l1, l2, l3, l4;

        getline(cin >> ws, l1);
        getline(cin >> ws, l2);
        getline(cin >> ws, l3);
        getline(cin >> ws, l4);

        transform(l1.begin(), l1.end(), l1.begin(), [](unsigned char c)
                  { return tolower(c); });
        transform(l2.begin(), l2.end(), l2.begin(), [](unsigned char c)
                  { return tolower(c); });
        transform(l3.begin(), l3.end(), l3.begin(), [](unsigned char c)
                  { return tolower(c); });
        transform(l4.begin(), l4.end(), l4.begin(), [](unsigned char c)
                  { return tolower(c); });

        l1 = lastSyllable(l1);
        l2 = lastSyllable(l2);
        l3 = lastSyllable(l3);
        l4 = lastSyllable(l4);

        if (l1 == l2 && l2 == l3 && l3 == l4)
        {
            cout << "perfect" << '\n';
        }
        else if (l1 == l2 && l3 == l4)
        {
            cout << "even" << '\n';
        }
        else if (l1 == l3 && l2 == l4)
        {
            cout << "cross" << '\n';
        }
        else if (l1 == l4 && l2 == l3)
        {
            cout << "shell" << '\n';
        }
        else
        {
            cout << "free" << '\n';
        }
    }
    return 0;
}