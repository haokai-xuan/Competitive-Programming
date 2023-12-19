#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> adjectives;
    vector<string> nouns;

    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        adjectives.push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        string a;
        cin >> a;
        nouns.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << adjectives[i] << " as " << nouns[j] << '\n';
        }
    }

    return 0;
}