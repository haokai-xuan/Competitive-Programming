#include <bits/stdc++.h>
using namespace std;

int ways(vector<int> friends, int n, int x)
{
    int ans = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (friends[i] == x)
        {
            ans *= 1 + ways(friends, n, i + 1);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> friends;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        friends.push_back(x);
    }
    cout << ways(friends, n, n) << '\n';
    return 0;
}