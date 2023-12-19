#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int x[n], y[n];

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    vector<int> areas;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (abs(x[i] - x[j]) > abs(y[i] - y[j]))
                {
                    areas.push_back((x[i] - x[j]) * (x[i] - x[j]));
                }
                else
                {
                    areas.push_back((y[i] - y[j]) * (y[i] - y[j]));
                }
            }
        }
    }
    sort(areas.begin(), areas.end());
    cout << areas[0] << '\n';

    return 0;
}