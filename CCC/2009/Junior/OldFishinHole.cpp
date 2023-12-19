#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int brown_trout, northern_pike, yellow_pickerel, total, cnt = 0;
    cin >> brown_trout >> northern_pike >> yellow_pickerel >> total;

    for (int i = 0; i <= total / brown_trout; i++)
    {
        for (int j = 0; j <= total / northern_pike; j++)
        {
            for (int k = 0; k <= total / yellow_pickerel; k++)
            {
                if (i == 0 && j == 0 && k == 0)
                {
                    continue;
                }
                if (i * brown_trout + j * northern_pike + k * yellow_pickerel <= total)
                {
                    cout << i << " Brown Trout, " << j << " Northern Pike, " << k << " Yellow Pickerel" << '\n';
                    cnt++;
                }
            }
        }
    }
    cout << "Number of ways to catch fish: " << cnt << '\n';
    return 0;
}