// RTE 0 points

#include <bits/stdc++.h>
using namespace std;

int r, c;

int countWord(vector<string> grid, string word)
{
    int cnt = 0;

    // horizontal
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= c - word.length(); j++)
        {
            string substring = grid[i].substr(j, word.length());
            if (substring == word || string(substring.rbegin(), substring.rend()) == word)
                cnt++;
        }
    }

    // vertical
    for (int i = 0; i <= r - word.length(); i++)
    {
        for (int j = 0; j < c; j++)
        {
            string substring = "";
            for (int k = 0; k < word.length(); k++)
            {
                substring += grid[i + k][j];
            }
            if (substring == word || substring == string(word.rbegin(), word.rend()))
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string word;
    cin >> word;

    cin >> r >> c;

    vector<string> grid(r);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            string s;
            cin >> s;
            grid[i].append(s);
        }
    }

    int cnt = countWord(grid, word);
    cout << cnt << '\n';
    return 0;
}