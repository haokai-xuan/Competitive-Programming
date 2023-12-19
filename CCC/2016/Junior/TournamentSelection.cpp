#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char arr[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    int cntW = 0;
    for (char c : arr)
    {
        if (c == 'W')
            cntW++;
    }
    if (cntW == 6 || cntW == 5)
        cout << 1 << '\n';
    else if (cntW == 4 || cntW == 3)
        cout << 2 << '\n';
    else if (cntW == 2 || cntW == 1)
        cout << 3 << '\n';
    else
        cout << -1 << '\n';
}