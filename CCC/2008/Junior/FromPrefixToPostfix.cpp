#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-')
        return true;
    return false;
}

string solve(string prefix)
{
    stack<string> stk;
    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        if (isOperator(prefix[i]))
        {
            string s1 = stk.top();
            stk.pop();

            string s2 = stk.top();
            stk.pop();

            stk.push(s1 + s2 + string(1, prefix[i]));
        }
        else // is num
        {
            stk.push(string(1, prefix[i]));
        }
    }
    return stk.top();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        string input;
        getline(cin >> ws, input);
        if (input == "0")
        {
            break;
        }
        else
        {
            input.erase(remove(input.begin(), input.end(), ' '), input.end());
            string ans = solve(input);

            for (char c : ans)
                cout << c << ' ';
            cout << '\n';
        }
    }

    return 0;
}