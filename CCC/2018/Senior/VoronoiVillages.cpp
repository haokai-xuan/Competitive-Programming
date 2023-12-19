#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    double villages[n];
    for (int i = 0; i < n; i++)
    {
        cin >> villages[i];
    }
    sort(villages, villages + n);

    double ans = InT_MAX;
    for (int i = 1; i < n - 1; i++)
    {
        ans = min(ans, (villages[i] - villages[i - 1]) / 2 + (villages[i + 1] - villages[i]) / 2);
    }
    cout << fixed << setprecision(1) << ans << '\n';
    return 0;
}