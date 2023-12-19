#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cnt[26] = {0};
    string s1, s2;
    cin >> s1 >> s2;

    for (char ch : s1)
    {
        cnt[ch - 'a']++;
    }

    for (char ch : s2)
    {
        if (ch == '*')
        {
            continue;
        }
        if (cnt[ch - 'a'] == 0)
        {
            cout << "n" << '\n';
            return 0;
        }
        cnt[ch - 'a']--;
    }
    cout << "A" << '\n';

    return 0;
}