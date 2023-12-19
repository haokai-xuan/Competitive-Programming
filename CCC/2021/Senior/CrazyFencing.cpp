#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    double height[n + 1];
    double area = 0;
    for (int i = 0; i < n + 1; i++)
    {
        cin >> height[i];
    }
    double length[n];
    for (int i = 0; i < n; i++)
    {
        cin >> length[i];
    }
    for (int i = 0; i < n; i++)
    {
        area += length[i] * (height[i] + height[i + 1]) / 2;
    }
    cout << fixed << area << '\n';
    return 0;
}