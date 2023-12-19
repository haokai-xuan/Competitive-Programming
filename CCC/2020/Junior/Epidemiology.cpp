#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int p; // limit
    int n; // ppl that have disease on day 0
    int r; // each person infects r ppl per day
    int day = 0;

    int total = 0;
    cin >> p >> n >> r;
    while (1)
    {
        total = n + total * r;
        day++;
        if (total > p)
            break;
    }
    cout << day - 1 << '\n';
}