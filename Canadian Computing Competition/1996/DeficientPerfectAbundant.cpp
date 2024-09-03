#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        vector<int> divisors;
        for (int i = 1; i <= num - 1; i++)
        {
            if (num % i == 0)
            {
                divisors.push_back(i);
            }
        }
        int total = 0;
        for (int i : divisors)
        {
            total += i;
        }
        if (total == num)
        {
            cout << num << " is a perfect number." << '\n';
        }
        else if (total < num)
        {
            cout << num << " is a deficient number." << '\n';
        }
        else
        {
            cout << num << " is an abundant number." << '\n';
        }
    }
    return 0;
}
