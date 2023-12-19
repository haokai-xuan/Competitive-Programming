#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cities[5];
    cities[0] = 0;
    int distances[4];

    cin >> distances[0] >> distances[1] >> distances[2] >> distances[3];

    for (int i = 1; i <= 5; i++)
    {
        cities[i] = cities[i - 1] + distances[i - 1];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int distance = abs(cities[i] - cities[j]);
            cout << distance << ' ';
        }
        cout << '\n';
    }

    return 0;
}