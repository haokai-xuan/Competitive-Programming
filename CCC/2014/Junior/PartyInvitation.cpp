#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    vector<int> friends;

    for (int i = 0; i < k; i++)
    {
        friends.push_back(i + 1);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int factor;
        cin >> factor;
        vector<int> new_friends;
        for (int j = 0; j < friends.size(); j++)
        {
            if ((j + 1) % factor != 0)
            {
                new_friends.push_back(friends[j]);
            }
        }
        friends.clear();
        for (int fri : new_friends)
        {
            friends.push_back(fri);
        }
    }

    for (int x : friends)
        cout << x << '\n';
    return 0;
}