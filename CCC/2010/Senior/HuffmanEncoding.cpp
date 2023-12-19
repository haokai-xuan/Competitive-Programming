#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<char, string> legend;

    for (int i = 0; i < n; i++)
    {
        char c;
        string s;

        cin >> c >> s;

        legend.insert({c, s});
    }

    string sequence, curr = "", ans = "";

    cin >> sequence;

    for (int i = 0; i < sequence.size(); i++)
    {
        curr += sequence[i];
        for (auto j : legend)
        {
            if (j.second == curr)
            {
                ans += j.first;

                curr.clear();
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}