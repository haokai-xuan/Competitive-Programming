#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX_N = 1e4 + 5;
vector<int> adj[MAX_N];
int dp[MAX_N] = {0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int x, y;
    cin >> x >> y;
    while (x != 0 && y != 0)
    {
        adj[x].push_back(y);
        cin >> x >> y;
    }

    dp[n] = 1;

    for (int i = n - 1; i > 0; i--)
    {
        for (int neighbour : adj[i])
        {
            dp[i] += dp[neighbour];
        }
    }

    cout << dp[1] << '\n';

    return 0;
}