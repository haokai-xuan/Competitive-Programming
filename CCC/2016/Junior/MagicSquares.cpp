#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int val;
    int rows[4] = {0};
    int cols[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> val;
            rows[i] += val;
            cols[j] += val;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (rows[0] != rows[i] || cols[0] != cols[i])
        {
            cout << "not magic" << '\n';
            return 0;
        }
    }
    cout << "magic" << '\n';
    return 0;
}