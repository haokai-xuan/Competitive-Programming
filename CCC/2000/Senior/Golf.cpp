#include <bits/stdc++.h>
using namespace std;

int MAX = 2e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int dist_to_hole;
    cin >> dist_to_hole;

    int n;
    cin >> n;

    int club_dist[n];

    for (int i = 0; i < n; i++)
    {
        cin >> club_dist[i];
    }

    vector<int> dp(5281, MAX);

    dp[0] = 0; // to reach distance of 0, she needs 0 strokes

    for (int i = 1; i <= dist_to_hole; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - club_dist[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - club_dist[j]] + 1);
            }
        }
    }

    if (dp[dist_to_hole] != MAX)
    {
        cout << "Roberta wins in " << dp[dist_to_hole] << " strokes." << '\n';
    }
    else
    {
        cout << "Roberta acknowledges defeat." << '\n';
    }

    return 0;
}