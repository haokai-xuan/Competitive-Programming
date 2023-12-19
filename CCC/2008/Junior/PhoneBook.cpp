#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<string, int> input;
    map<string, int> occurence;

    for (int i = 0; i < n; i++)
    {
        string s;
        int a;
        cin >> s >> a;
        input.emplace(s, a);
        occurence.emplace(s, 0);
    }

    int d;
    cin >> d;

    for (int i = 0; i < d; i++)
    {
        int num;
        cin >> num;
        for (auto a : input)
        {
            if (a.second == num)
            {
                occurence[a.first]++;
                break;
            }
        }
    }

    int max = 0;
    for (auto i : occurence)
    {
        if (i.second > max)
        {
            max = i.second;
        }
    }

    vector<int> v;
    for (auto i : occurence)
    {
        if (i.second == max)
        {
            v.push_back(input[i.first]);
        }
    }

    sort(v.begin(), v.end());
    for (auto i : input)
    {
        if (i.second == v[0])
        {
            cout << i.first << '\n';
            break;
        }
    }

    return 0;
}