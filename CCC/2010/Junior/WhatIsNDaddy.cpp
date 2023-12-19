#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i + j == n)
            {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}