#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    list<int> instructions;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x > 0)
        {
            instructions.push_back(x);
        }
        else
        {
            instructions.pop_back();
        }
    }

    int money = 0;
    for (int i : instructions)
    {
        money += i;
    }
    cout << money << '\n';

    return 0;
}