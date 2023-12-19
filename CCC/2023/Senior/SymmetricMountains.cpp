#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
int h[MAXN];
int asym[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int left = 1, right = i;
        int ans = INT_MAX;

        while (right <= n)
        {
            asym[left][right] = abs(h[left] - h[right]) + asym[left + 1][right - 1];
            ans = min(ans, asym[left][right]);
            left++;
            right++;
        }
        cout << ans << ' ';
    }

    return 0;
}