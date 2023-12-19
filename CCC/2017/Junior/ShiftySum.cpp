#include <bits/stdc++.h>
using namespace std;

int shifty_sum(int n, int k)
{
    int result = n;
    for (int i = 1; i <= k; i++)
    {
        n *= 10;
        result += n;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    cout << shifty_sum(n, k) << '\n';
}