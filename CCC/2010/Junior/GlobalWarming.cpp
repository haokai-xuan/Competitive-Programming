#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (true)
    {
        cin >> n;

        int seq[n];
        if (n == 0)
            break;
        else
        {
            for (int i = 0; i < n; i++)
                cin >> seq[i];

            int diff[n - 1];
            for (int i = 0; i < n - 1; i++)
            {
                diff[i] = seq[i + 1] - seq[i];
            }

            // for (int i : diff)
            //     cout << i << ' ';
            // cout << '\n';

            if (n != 1)
            {
                for (int size = 1; size <= n - 1; size++)
                {
                    int currPos = 0;
                    bool works = true;

                    for (int i = 0; i < n - 1; i++)
                    {
                        if (diff[currPos] != diff[i])
                        {
                            works = false;
                            break;
                        }
                        currPos++;
                        currPos %= size;
                    }
                    if (works)
                    {
                        cout << size << '\n';
                        break;
                    }
                }
            }
            else
            {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}