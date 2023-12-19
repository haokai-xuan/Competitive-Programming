#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    string msg;
    cin >> msg;

    string ans;
    for (int i = 0; i < msg.length(); i++)
    {
        char letter = msg[i];
        int shift = 3 * (i + 1) + k;

        letter -= shift;

        if (letter < 'A')
        {
            letter += 'Z' - 'A' + 1;
        }
        ans += letter;
    }
    cout << ans << '\n';
    return 0;
}
