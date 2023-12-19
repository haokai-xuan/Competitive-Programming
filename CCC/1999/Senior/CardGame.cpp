#include <bits/stdc++.h>
using namespace std;

string cards[52];

bool check(int index, int length)
{
    if (index + length > 51)
        return false;
    for (int i = index + 1; i < length + index + 1; i++)
    {
        if (cards[i] == "ace" || cards[i] == "king" || cards[i] == "queen" || cards[i] == "jack")
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
    cout.tie(0);

    for (int i = 0; i < 52; i++)
    {
        cin >> cards[i];
    }

    int playerA = 0, playerB = 0;
    for (int i = 0; i < 52; i++)
    {
        int points = 0;
        int player = i % 2; // 0 means player A. 1 means player B

        if (cards[i] == "ace" && check(i, 4))
        {
            points = 4;
        }
        else if (cards[i] == "king" && check(i, 3))
        {
            points = 3;
        }
        else if (cards[i] == "queen" && check(i, 2))
        {
            points = 2;
        }
        else if (cards[i] == "jack" && check(i, 1))
        {
            points = 1;
        }
        if (points > 0)
        {
            if (player == 0) // player A
            {
                playerA += points;
                cout << "Player A scores " << points << " point(s)." << '\n';
            }
            else
            {
                playerB += points;
                cout << "Player B scores " << points << " point(s)." << '\n';
            }
        }
    }
    cout << "Player A: " << playerA << " point(s). " << '\n';
    cout << "Player B: " << playerB << " point(s). " << '\n';

    return 0;
}