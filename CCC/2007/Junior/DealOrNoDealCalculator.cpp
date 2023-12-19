#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<int, int> mp = {
        {1, 100},
        {2, 500},
        {3, 1000},
        {4, 5000},
        {5, 10000},
        {6, 25000},
        {7, 50000},
        {8, 100000},
        {9, 500000},
        {10, 1000000}};

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        map<int, int>::iterator it;
        it = mp.find(a);
        mp.erase(it);
    }

    int briefcase_total = accumulate(begin(mp), end(mp), 0, [](int value, const map<int, int>::value_type &p)
                                     { return value + p.second; });
    briefcase_total /= mp.size();

    int offer;
    cin >> offer;

    if (offer > briefcase_total)
    {
        cout << "deal" << '\n';
    }
    else
    {
        cout << "no deal" << '\n';
    }

    return 0;
}