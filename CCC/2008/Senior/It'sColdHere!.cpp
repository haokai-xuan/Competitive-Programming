#include <bits/stdc++.h>
using namespace std;

bool starts_with_waterloo(string main_str, string match)
{
    if (main_str.find(match) == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string main_str;

    string city, coldest_city;
    int cp, coldest_cp;

    getline(cin >> ws, main_str);

    while (!starts_with_waterloo(main_str, "Waterloo"))
    {
        getline(cin >> ws, main_str);

        for (int i = 0; i < main_str.size(); i++)
        {
            if (main_str[i] == ' ')
            {
                city = main_str.substr(0, i);
                cp = stoi(main_str.substr(i));
                // cout << coldest_cp << '\n';
                break;
            }
        }

        if (cp < coldest_cp)
        {
            coldest_city = city;
            coldest_cp = cp;
        }
    }
    cout << coldest_city << '\n';

    return 0;
}