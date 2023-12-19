#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string alice[n], bob[n];

    for (int i = 0; i < n; i++)
    {
        cin >> alice[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> bob[i];
    }

    int alicescore = 0, bobscore = 0;

    for (int i = 0; i < n; i++)
    {
        if ((alice[i] == "rock" && bob[i] == "scissors") || (alice[i] == "paper" && bob[i] == "rock") || (alice[i] == "scissors" && bob[i] == "paper"))
        {
            alicescore++;
        }
        else if ((bob[i] == "rock" && alice[i] == "scissors") || (bob[i] == "paper" && alice[i] == "rock") || (bob[i] == "scissors" && alice[i] == "paper"))
        {
            bobscore++;
        }
    }

    cout << alicescore << ' ' << bobscore << '\n';

    return 0;
}