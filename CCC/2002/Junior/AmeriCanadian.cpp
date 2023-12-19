#include <bits/stdc++.h>
using namespace std;

bool ends_with(string str, string suffix)
{
    if (str.length() < suffix.length())
    {
        return false;
    }
    return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
}

bool is_consonant(string x)
{
    if (x == "a" || x == "e" || x == "i" || x == "o" || x == "u")
    {
        return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    while (1)
    {
        cin >> str;
        if (str == "quit!")
        {
            break;
        }

        if (str.length() > 4 && ends_with(str, "or") && is_consonant(str.substr(str.length() - 3, 1)))
        {
            str.insert(str.length() - 1, "u");
            cout << str << '\n';
        }
        else
        {
            cout << str << '\n';
        }

        str.clear();
    }
    return 0;
}
