#include <bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    if (n == 1)
    {
        return false;
    }

    int i = 2;
    // This will loop from 2 to int(sqrt(x))
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            return false;
        }
        i += 1;
    }
    return true;
}

void solve(int num)
{
    for (int i = 2; i <= 2 * num; i++)
    {
        int j = 2 * num - i; // x + y must be 2 * n
        if (isprime(i) && isprime(j) && i + j == 2 * num)
        {
            cout << i << ' ' << j << '\n';
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        solve(num);
    }
    return 0;
}