#include <bits/stdc++.h>
using namespace std;

int compare(int size)
{
    if (size == 0)
    {
        return 3;
    }
    else if (size == 1)
    {
        return 2;
    }
    else if (size == 2)
    {
        return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    vector<char> clubs, diamonds, hearts, spades;
    int clubs_pt = 0, diamonds_pt = 0, hearts_pt = 0, spades_pt = 0;

    int index = 1;
    while (s[index] != 'D')
    {
        clubs.push_back(s[index]);
        index++;
    }
    clubs_pt = compare(clubs.size());

    index++;
    while (s[index] != 'H')
    {
        diamonds.push_back(s[index]);
        index++;
    }
    diamonds_pt = compare(diamonds.size());

    index++;
    while (s[index] != 'S')
    {
        hearts.push_back(s[index]);
        index++;
    }
    hearts_pt = compare(hearts.size());

    index++;
    while (index < s.length())
    {
        spades.push_back(s[index]);
        index++;
    }
    spades_pt = compare(spades.size());

    map<char, int> mp = {
        {'A', 4},
        {'K', 3},
        {'Q', 2},
        {'J', 1}};

    for (auto p : clubs)
    {
        clubs_pt += mp[p];
    }

    for (auto p : diamonds)
    {
        diamonds_pt += mp[p];
    }

    for (auto p : hearts)
    {
        hearts_pt += mp[p];
    }

    for (auto p : spades)
    {
        spades_pt += mp[p];
    }

    cout << "Cards Dealt              Points" << endl;
    cout << "Clubs ";
    for (auto p : clubs)
    {
        cout << p << " ";
    }
    cout << "             " << clubs_pt << endl;

    cout << "Diamonds ";
    for (auto p : diamonds)
    {
        cout << p << " ";
    }
    cout << "             " << diamonds_pt << endl;

    cout << "Hearts ";
    for (auto p : hearts)
    {
        cout << p << " ";
    }
    cout << "             " << hearts_pt << endl;

    cout << "Spades ";
    for (auto p : spades)
    {
        cout << p << " ";
    }
    cout << "             " << spades_pt << endl;

    int total = clubs_pt + diamonds_pt + hearts_pt + spades_pt;
    cout << "                       Total " << total << '\n';

    return 0;
}