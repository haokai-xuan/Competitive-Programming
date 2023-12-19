#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    char actual_ans[n];
    char ans[n];

    for (int i = 0; i < n; i++)
    {
        cin >> actual_ans[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
    }

    int ans_correctly = 0;

    for (int i = 0; i < n; i++)
    {
        if (actual_ans[i] == ans[i])
        {
            ans_correctly++;
        }
    }
    cout << ans_correctly << '\n';
    return 0;
}