#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int coord1x = 101;
    int coord1y = 101;
    int coord2x = -1;
    int coord2y = -1;
    for (int i = 0; i < n; i++)
    {
        int coord1;
        string s;
        cin >> coord1 >> s;
        int coord2 = stoi(s.substr(1));
        coord1x = min(coord1x, coord1);
        coord1y = min(coord1y, coord2);
        coord2x = max(coord2x, coord1);
        coord2y = max(coord2y, coord2);
    }
    cout << coord1x - 1 << "," << coord1y - 1 << endl
         << coord2x + 1 << "," << coord2y + 1 << '\n';
}