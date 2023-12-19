#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int sCnt = 0, tCnt = 0;
    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin >> ws, line);
        for (char c : line)
        {
            if (c == 't' || c == 'T')
            {
                tCnt++;
            }
            else if (c == 's' || c == 'S')
            {
                sCnt++;
            }
        }
    }

    if (sCnt > tCnt)
    {
        cout << "French" << '\n';
    }
    else if (tCnt > sCnt)
    {
        cout << "English" << '\n';
    }
    else if (sCnt == tCnt)
    {
        cout << "French" << '\n';
    }
    return 0;
}