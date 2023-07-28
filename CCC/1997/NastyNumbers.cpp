#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        vector<pair<int, int>> factors;
        for (int i = 1; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                factors.push_back({abs(i - num / i), i + num / i});
            }
        }

        // for (auto a : factors)
        // {
        //     cout << a.first << ' ' << a.second << '\n';
        // }

        bool nasty = false;
        for (int i = 0; i < factors.size() && !nasty; i++)
        {
            for (int j = i + 1; j < factors.size() && !nasty; j++)
            {
                if (factors[i].first == factors[j].second || factors[i].second == factors[j].first)
                {
                    nasty = true;
                }
            }
        }
        cout << num;
        if (nasty)
        {
            cout << " is nasty" << '\n';
        }
        else
        {
            cout << " is not nasty" << '\n';
        }
    }
    return 0;
}