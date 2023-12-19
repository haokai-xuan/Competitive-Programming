#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int pink_cost, green_cost, red_cost, orange_cost;
    int total;
    cin >> pink_cost >> green_cost >> red_cost >> orange_cost >> total;

    int ways = 0;
    int least = INFINITY;

    for (int i = 0; i <= total / pink_cost; i++)
    {
        for (int j = 0; j <= total / green_cost; j++)
        {
            for (int k = 0; k <= total / red_cost; k++)
            {
                for (int l = 0; l <= total / orange_cost; l++)
                {
                    if (i * pink_cost + j * green_cost + k * red_cost + l * orange_cost == total)
                    {
                        cout << "# of PINK is " << i << " # of GREEN is " << j << " # of RED is " << k << " # of ORANGE is " << l << '\n';
                        ways++;
                        if (i + j + k + l < least)
                        {
                            least = i + j + k + l;
                        }
                    }
                }
            }
        }
    }

    cout << "Total combinations is " << ways << '.' << '\n';
    cout << "Minimum number of tickets to print is " << least << '.' << '\n';

    return 0;
}