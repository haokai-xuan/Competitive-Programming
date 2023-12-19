#include <bits/stdc++.h>
using namespace std;

vector<int> getFactors(int n)
{
    vector<int> f;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0 && i != n)
        {
            f.push_back(i);
        }
    }
    return f;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    for (int i = 1000; i <= 9999; i++)
    {
        vector<int> factors;
        factors = getFactors(i);

        int sum = 0;
        for (int j : factors)
        {
            sum += j;
        }
        if (sum == i)
        {
            cout << i << ' ';
        }
    }
    cout << '\n';

    for (int i = 100; i <= 999; i++)
    {
        int hundreds = i / 100;
        int tens = i / 10 % 10;
        int units = i % 10;
        if (hundreds * hundreds * hundreds + tens * tens * tens + units * units * units == i)
        {
            cout << i << ' ';
        }
    }
    return 0;
}