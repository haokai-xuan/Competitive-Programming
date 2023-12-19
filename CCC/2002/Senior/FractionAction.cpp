#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int numerator, denomenator;
    cin >> numerator >> denomenator;

    if (numerator % denomenator == 0)
    {
        cout << numerator / denomenator << '\n';
    }

    else
    {
        int temp = numerator / denomenator;
        if (temp > 0)
        {
            cout << temp << ' ';
        }
        numerator -= temp * denomenator;

        int result = min(numerator, denomenator);
        while (result > 0)
        {
            if (numerator % result == 0 && denomenator % result == 0)
            {
                numerator /= result, denomenator /= result;
            }
            result--;
        }
        cout << numerator << '/' << denomenator << '\n';
    }

    return 0;
}