#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> day(n);
    for (int i = 0; i < n; i++)
    {
        cin >> day[i];
    }

    vector<int> counts(5, 0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (day[j][i] == 'Y')
            {
                counts[i]++;
            }
        }
    }

    int max_count = *max_element(counts.begin(), counts.end());
    vector<int> ans;
    for (int i = 0; i < 5; i++)
    {
        if (counts[i] == max_count)
        {
            ans.push_back(i + 1);
        }
    }

    if (ans.size() == 1)
    {
        cout << ans[0] << '\n';
    }

    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            if (i == ans.size() - 1)
            {
                cout << ans[i];
            }
            else
            {
                cout << ans[i] << ',';
            }
        }
        cout << '\n';
    }

    return 0;
}
