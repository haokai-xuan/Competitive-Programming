#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    if ((n1 == 8 || n1 == 9) && (n4 == 8 || n4 == 9) && (n2 == n3))
    {
        cout << "ignore" << '\n';
    }
    else
    {
        cout << "answer" << '\n';
    }

    return 0;
}