// INCOMPLETE
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int mod = 1e9 + 7;

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int cnt = 0;
    sort(nums, nums + n);

    if (cnt >= 1e9 + 7)
    {
        cout << cnt % mod << '\n';
    }
    else
    {
        cout << cnt << '\n';
    }

    return 0;
}