#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> mp;

    string main_str;
    int temp;

    string city, coldest_city = "Waterloo";
    int coldest_temp = 201;

    while (true)
    {
        getline(cin >> ws, main_str);

        int pos = main_str.find(" ");
        city = main_str.substr(0, pos);
        temp = stoi(main_str.substr(pos + 1));

        // cout << "City: " << city << " Temp: " << temp << '\n';

        mp.insert({city, temp});

        if (city == "Waterloo")
        {
            break;
        }
    }

    for (auto const &[key, val] : mp)
    {
        if (val < coldest_temp)
        {
            coldest_temp = val;
            coldest_city = key;
        }
    }

    cout << coldest_city << '\n';

    return 0;
}
