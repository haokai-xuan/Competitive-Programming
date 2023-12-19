#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;

    getline(cin >> ws, s1);
    getline(cin >> ws, s2);

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
    s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());

    if (s1 == s2)
    {
        cout << "Is an anagram." << '\n';
    }
    else
    {
        cout << "Is not an anagram." << '\n';
    }
    return 0;
}