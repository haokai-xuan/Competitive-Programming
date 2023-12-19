#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s, ans = "";
        cin >> s;
        int j = 0;
        while (ans.length() < 12)
        {

            if (s[j] == '0')
            {
                ans.push_back('0');
            }
            else if (s[j] == '1')
            {
                ans.push_back('1');
            }
            else if (s[j] == '2' || s[j] == 'A' || s[j] == 'B' || s[j] == 'C')
            {
                ans.push_back('2');
            }
            else if (s[j] == '3' || s[j] == 'D' || s[j] == 'E' || s[j] == 'F')
            {
                ans.push_back('3');
            }
            else if (s[j] == '4' || s[j] == 'G' || s[j] == 'H' || s[j] == 'I')
            {
                ans.push_back('4');
            }
            else if (s[j] == '5' || s[j] == 'J' || s[j] == 'K' || s[j] == 'L')
            {
                ans.push_back('5');
            }
            else if (s[j] == '6' || s[j] == 'M' || s[j] == 'n' || s[j] == 'O')
            {
                ans.push_back('6');
            }
            else if (s[j] == '7' || s[j] == 'P' || s[j] == 'Q' || s[j] == 'R' || s[j] == 'S')
            {
                ans.push_back('7');
            }
            else if (s[j] == '8' || s[j] == 'T' || s[j] == 'U' || s[j] == 'V')
            {
                ans.push_back('8');
            }
            else if (s[j] == '9' || s[j] == 'W' || s[j] == 'X' || s[j] == 'Y' || s[j] == 'Z')
            {
                ans.push_back('9');
            }
            if (ans.size() == 3 || ans.size() == 7)
            {
                ans.push_back('-');
            }
            j++;
        }
        for (char c : ans)
        {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}