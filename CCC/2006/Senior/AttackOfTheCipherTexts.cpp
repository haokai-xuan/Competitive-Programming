#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string original, encrypted, to_decode;
    getline(cin >> ws, original);
    getline(cin >> ws, encrypted);
    getline(cin >> ws, to_decode);

    for (int i = 0; i < to_decode.size(); i++)
    {
        int x = encrypted.find(to_decode[i]);
        if (x == -1)
        {
            cout << '.';
        }
        else
        {
            cout << original[x];
        }
    }

    return 0;
}