#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int quarters;
    cin >> quarters;

    int machine1, machine2, machine3;
    cin >> machine1 >> machine2 >> machine3;

    int cnt;
    while (quarters > 0)
    {
        quarters--;
        cnt++;
        machine1++;
        if (machine1 == 35)
        {
            quarters += 30;
            machine1 = 0;
        }
        if (quarters == 0)
        {
            break;
        }

        quarters--;
        cnt++;
        machine2++;
        if (machine2 == 100)
        {
            quarters += 60;
            machine2 = 0;
        }
        if (quarters == 0)
        {
            break;
        }

        quarters--;
        cnt++;
        machine3++;
        if (machine3 == 10)
        {
            quarters += 9;
            machine3 = 0;
        }
        if (quarters == 0)
        {
            break;
        }
    }
    cout << "Martha plays " << cnt << " times before going broke." << '\n';
    return 0;
}
