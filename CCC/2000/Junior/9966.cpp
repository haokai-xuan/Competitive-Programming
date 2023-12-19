#include <bits/stdc++.h>
using namespace std;

bool rotate_is_same(int n)
{
    string s = to_string(n);
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    
    int a = s.length();

    for (int i = 0; i < a; i++)
    {
        if ((s[i] == '0' || s[i] == '1' || s[i] == '8') && s[i] != rev_s[i])
        {
            return false;
        }
        else if ((s[i] == '6' && rev_s[i] != '9') || (s[i] == '9' && rev_s[i] != '6'))
        {
            return false;
        }
        else if (s[i] != '0' && s[i] != '1' && s[i] != '6' && s[i] != '8' && s[i] != '9')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int start, end;
    cin >> start >> end;

    int cnt = 0;

    for (int i = start; i <= end; i++)
    {
        if (rotate_is_same(i))
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}