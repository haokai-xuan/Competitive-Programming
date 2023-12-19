#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int swift[n];
    int sema[n];
    for (int i = 0; i < n; i++)
    {
        cin >> swift[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> sema[i];
    }
    int k = 0, swift_sum = 0, sema_sum = 0;
    for (int i = 0; i < n; i++)
    {
        swift_sum += swift[i];
        sema_sum += sema[i];
        if (swift_sum == sema_sum)
        {
            k = i + 1;
        }
    }
    cout << k << '\n';
    return 0;
}