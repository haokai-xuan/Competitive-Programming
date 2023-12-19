#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    string result = "";
    string consonants = "bcdfghjklmnpqrstvwxyz";
    string closestvowel = "aaeeeiiiiooooouuuuuuu";
    string nextconsonant = "cdfghjklmnpqrstvwxyzz";

    for (char c : s)
    {
        int i = consonants.find(c);
        result += c;
        if (i > -1)
            result = result + closestvowel[i] + nextconsonant[i];
    }
    cout << result << '\n';
    return 0;
}