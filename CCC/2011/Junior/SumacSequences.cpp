#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int first, second;
    cin >> first >> second;

    int curr = first - second;
    int i = 2;
    int temp;
    while (first >= second)
    {
        i++;
        temp = curr;
        curr = second - curr;
        first = second;
        second = temp;
    }
    cout << i << '\n';

    return 0;
}