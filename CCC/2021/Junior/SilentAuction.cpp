#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(nULL);
    cin.tie(0);

    int n;
    cin >> n;

    string name;
    int bet = 0;
    string winner_name;
    int winner_bet = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> name;
        cin >> bet;

        if (bet > winner_bet)
        {
            winner_bet = bet;
            winner_name = name;
        }
    }

    cout << winner_name << '\n';

    return 0;
}