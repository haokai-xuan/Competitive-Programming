#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int antennae, eye;
    cin >> antennae >> eye;

    if (antennae >= 3 && eye <= 4)
    {
        cout << "TroyMartian" << '\n';
    }
    if (antennae <= 6 && eye >= 2)
    {
        cout << "VladSaturnian" << '\n';
    }
    if (antennae <= 2 && eye <= 3)
    {
        cout << "GraemeMercurian" << '\n';
    }

    if (!(antennae >= 3 && eye <= 4) && !(antennae <= 6 && eye >= 2) && !(antennae <= 2 && eye <= 3))
    {
        cout << "\n";
    }

    return 0;
}