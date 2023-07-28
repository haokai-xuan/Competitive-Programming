#include <bits/stdc++.h>
using namespace std;

vector<int> factors(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> f = factors(60);
    for (int i : f)
    {
        cout << i << ' ';
    }
}
