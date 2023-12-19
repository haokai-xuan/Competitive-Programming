#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> data;
    pair<double, double> nums;

    for (int x = 0; x < n; x++)
    {
        cin >> nums.first >> nums.second;
        data.push_back(nums);
    }

    sort(data.begin(), data.end());

    double ans;

    for (int x = 0; x < n; x++)
    {
        double num = data[x + 1].second - data[x].second;
        double current_time = num / (data[x + 1].first - data[x].first);
        if (current_time < 0)
        {
            current_time = -current_time;
        }

        if (current_time > ans)
        {
            ans = current_time;
        }
    }

    cout << fixed << setprecision(1) << ans;

    return 0;
}