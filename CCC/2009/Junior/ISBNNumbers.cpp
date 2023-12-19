#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;
    int tot = 91 + x + y * 3 + z;
    cout << "The 1-3-sum is " << tot;
    return 0;
}