#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string, string> msg = {
        {"CU", "see you"},
        {":-)", "I'm happy"},
        {":-(", "I'm unhappy"},
        {";-)", "wink"},
        {":-P", "stick out my tongue"},
        {"(~.~)", "sleepy"},
        {"TA", "totally awesome"},
        {"CCC", "Canadian Computing Competition"},
        {"CUZ", "because"},
        {"TY", "thank-you"},
        {"YW", "you're welcome"},
        {"TTYL", "talk to you later"}};

    string s;
    cin >> s;
    while (s != "TTYL")
    {
        if (msg.find(s) == msg.end())
        {
            cout << s << '\n';
            // break;
        }
        else
        {
            cout << msg[s] << '\n';
        }
        cin >> s;
    }
    cout << msg["TTYL"] << '\n';
    return 0;
}
