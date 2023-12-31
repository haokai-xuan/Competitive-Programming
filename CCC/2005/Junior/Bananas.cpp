#include <bits/stdc++.h>
using namespace std;

string check(string main_str)
{
    size_t pos_ANA;
    size_t pos_BAS;

    while (true)
    {
        pos_ANA = main_str.find("ANA");
        pos_BAS = main_str.find("BAS");

        if (pos_ANA == string::npos && pos_BAS == string::npos)
        {
            break;
        }

        if (pos_ANA != string::npos)
        {
            main_str.replace(pos_ANA, 3, "A");
        }
        else if (pos_BAS != string::npos)
        {
            main_str.replace(pos_BAS, 3, "A");
        }
    }

    return (main_str == "A") ? "YES" : "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string main_str;

    while (cin >> main_str && main_str != "X")
    {
        cout << check(main_str) << '\n';
    }

    return 0;
}