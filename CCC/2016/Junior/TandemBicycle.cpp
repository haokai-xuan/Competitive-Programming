#include <bits/stdc++.h>
using namespace std;

void type1(int n)
{
    int dmoj[n];
    int peg[n];

    for (int i = 0; i < n; i++)
        cin >> dmoj[i];
    for (int i = 0; i < n; i++)
        cin >> peg[i];

    sort(dmoj, dmoj + n);
    sort(peg, peg + n);

    int maximum[n];
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        maximum[i] = max(dmoj[i], peg[i]);
        result += maximum[i];
    }
    cout << result << '\n';
}

void type2(int n)
{
    int dmoj[n];
    int peg[n];

    for (int i = 0; i < n; i++)
        cin >> dmoj[i];
    for (int i = 0; i < n; i++)
        cin >> peg[i];

    sort(dmoj, dmoj + n);
    sort(peg, peg + n, greater<int>());

    int maximum[n];
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        maximum[i] = max(dmoj[i], peg[i]);
        result += maximum[i];
    }
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int instruction;
    cin >> instruction;
    int n;
    cin >> n;

    if (instruction == 1)
        type1(n);
    else
        type2(n);

    return 0;
}