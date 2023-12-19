#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string key, msg;

    cin >> key;
    getline(cin >> ws, msg);

    int ans;

    int currKey = 0;
    for (int j = 0; j < msg.size(); j++)
    {
        if (msg[j] >= 'A' && msg[j] <= 'Z')
        {
            ans = msg[j] + (key[currKey] - 'A');
            if (ans > 'Z')
            {
                ans = 'A' + (ans - 'Z' - 1);
            }
            cout << char(ans);
            currKey++;
            if (currKey >= key.size())
            {
                currKey = 0;
            }
        }
    }
    return 0;
}