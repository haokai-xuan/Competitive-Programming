#include <bits/stdc++.h>
using namespace std;

int countPaths(int R, int C, vector<pair<int, int>> cat_cages)
{
    vector<vector<int>> dp(R + 1, vector<int>(C + 1, 0));

    for (auto cage : cat_cages)
    {
        dp[cage.first][cage.second] = -1;
    }

    dp[1][1] = 1;

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (dp[i][j] != -1)
            {
                if (dp[i - 1][j] != -1)
                {
                    dp[i][j] += dp[i - 1][j];
                }
                if (dp[i][j - 1] != -1)
                {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
    }

    // for (int i = 1; i <= R; i++)
    // {
    //     for (int j = 1; j <= C; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    return dp[R][C];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int R, C;
    cin >> R >> C;

    int K;
    cin >> K;

    vector<pair<int, int>> cat_cages;

    for (int i = 0; i < K; i++)
    {
        int row, col;
        cin >> row >> col;

        cat_cages.push_back({row, col});
    }

    cout << countPaths(R, C, cat_cages) << '\n';

    return 0;
}