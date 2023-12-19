#include <bits/stdc++.h>
using namespace std;

int aromatic(char c)
{
    if (c == 'I')
    {
        return 1;
    }
    else if (c == 'V')
    {
        return 5;
    }
    else if (c == 'X')
    {
        return 10;
    }
    else if (c == 'L')
    {
        return 50;
    }
    else if (c == 'C')
    {
        return 100;
    }
    else if (c == 'D')
    {
        return 500;
    }
    else if (c == 'M')
    {
        return 1000;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int ans = 0;
    int prev_aro = InT_MAX;
    int prev_ans = 0;

    for (int i = 0; i < s.size(); i += 2)
    {
        int curr_arabic = s[i] - '0';
        int curr_aro = aromatic(s[i + 1]);
        int curr_ans = curr_arabic * curr_aro;

        ans += curr_ans;

        if (curr_aro > prev_aro)
        {
            ans = ans - 2 * prev_ans;
        }
        prev_aro = curr_aro;
        prev_ans = curr_ans;
    }

    cout << ans << '\n';
    return 0;
}