#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, j, k;
    cin >> i >> j >> k;

    if (i == 60 && j == 60 && k == 60)
        cout << "Equilateral" << '\n';
    else if (i + j + k == 180 && (i == k || i == j || k == j))
        cout << "Isosceles" << '\n';
    else if (i + j + k == 180 && (i != k || k != j || i != j))
        cout << "Scalene" << '\n';
    else
        cout << "Error" << '\n';
    return 0;
}