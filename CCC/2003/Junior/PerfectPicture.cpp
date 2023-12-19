#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int c;
        cin >> c;
        if (c == 0)
        {
            break;
        }
        for (int i = (int)sqrt(c); i > 0; i--)
        {
            if (c % i == 0)
            {
                int width = int(c / i);
                int perimeter = 2 * width + 2 * i;
                cout << "Minimum perimeter is " << perimeter << " with dimensions " << width << " x " << i << '\n';
                break;
            }
        }
    }

    return 0;
}