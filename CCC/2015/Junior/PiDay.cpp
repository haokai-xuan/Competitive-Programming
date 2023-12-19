#include <bits/stdc++.h>
using namespace std;

const int MAXn = 251;
int memo[MAXn][MAXn][MAXn] = {0};

int dp(int pieces, int people, int minimum)
{
    if (memo[pieces][people][minimum] == 0) // not visited
    {
        if (pieces == people || people == 1)
        {
            memo[pieces][people][minimum] = 1;
        }
        else
        {
            int current = 0;
            for (int i = minimum; i <= pieces / people; i++)
            {
                current += dp(pieces - i, people - 1, i);
            }
            memo[pieces][people][minimum] = current;
        }
    }
    return memo[pieces][people][minimum]; // visited, just return answer without looping
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int pieces, people;
    cin >> pieces >> people;

    cout << dp(pieces, people, 1) << '\n';

    return 0;
}