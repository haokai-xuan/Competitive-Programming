#include <bits/stdc++.h>
using namespace std;

bool check_start(string main_str, string prefix)
{
    if (main_str.rfind(prefix, 0) == 0)
    {
        return true;
    }
    return false;
}

bool check_end(string main_str, string prefix)
{
    if (main_str.size() >= prefix.size() &&
        main_str.compare(main_str.size() - prefix.size(), prefix.size(), prefix) == 0)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            string s;
            cin >> s;
            words.push_back(s);
        }
        if (check_start(words[0], words[1]) || check_start(words[0], words[2]) || check_start(words[1], words[0]) || check_start(words[1], words[2]) || check_start(words[2], words[0]) || check_start(words[2], words[1]) || check_end(words[0], words[1]) || check_end(words[0], words[2]) || check_end(words[1], words[0]) || check_end(words[1], words[2]) || check_end(words[2], words[0]) || check_end(words[2], words[1]))
        {
            cout << "no" << '\n';
        }
        else
        {
            cout << "Yes" << '\n';
        }
        words.clear();
    }
    return 0;
}