#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int rsa = 0;

    int start, end;
    cin >> start >> end;

    for (int i = start; i <= end; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                cnt++;
            }
        }
        if (cnt == 4)
        {
            rsa++;
        }
    }
    cout << "The number of RSA numbers between " << start << " and " << end << " is " << rsa << '\n';
    return 0;
}