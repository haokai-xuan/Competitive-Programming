#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    char parking_space[n];
    char parking_space2[n];

    for (int i = 0; i < n; i++)
    {
        cin >> parking_space[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> parking_space2[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (parking_space[i] == 'C' && parking_space2[i] == 'C')
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
}