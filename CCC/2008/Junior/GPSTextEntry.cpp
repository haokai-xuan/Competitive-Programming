#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> keypad = {
    {"A", "B", "C", "D", "E", "F"},
    {"G", "H", "I", "J", "K", "L"},
    {"M", "N", "O", "P", "Q", "R"},
    {"S", "T", "U", "V", "W", "X"},
    {"Y", "Z", " ", "-", ".", "enter"},

};

pair<int, int> find_index(string node)
{
    for (int i = 0; i < keypad.size(); i++)
    {
        for (int j = 0; j < keypad[i].size(); j++)
        {
            if (keypad[i][j] == node)
            {
                return {i, j};
            }
        }
    }
}

pair<int, int> subtract(pair<int, int> p1, pair<int, int> p2)
{
    return {abs(p1.first - p2.first), abs(p1.second - p2.second)};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin >> ws, s);

    pair<int, int> current = {0, 0};
    int distance = 0;
    for (char i : s)
    {
        string str = "";
        str.push_back(i);
        pair<int, int> pos = find_index(str);
        pair<int, int> value = subtract(current, pos);
        distance += (value.first + value.second);
        current = pos;
    }

    pair<int, int> pos = find_index("enter");
    pair<int, int> value = subtract(current, pos);
    distance += (value.first + value.second);
    cout << distance << '\n';
    return 0;
}
