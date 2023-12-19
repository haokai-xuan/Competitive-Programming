#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        char previous_char;
        int cnt = 0;
        for (char c : s)
        {
            if (cnt > 0 && previous_char != c)
            {
                cout << cnt << ' ' << previous_char << ' ';
                cnt = 0;
            }
            previous_char = c;
            cnt++;
        }
        cout << cnt << ' ' << previous_char << '\n';
    }
    return 0;
}