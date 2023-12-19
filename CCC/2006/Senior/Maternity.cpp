#include <bits/stdc++.h>
using namespace std;

bool possibleBaby(string mother, string father, string baby)
{
    bool possible = true;
    for (int i = 0; i < 5 && possible; i++)
    {
        if (isupper(baby[i]))
        {
            possible = ((isupper(father[i * 2]) || isupper(father[i * 2 + 1])) || (isupper(mother[i * 2]) || isupper(mother[i * 2 + 1])));
        }
        else if (islower(baby[i]))
        {
            possible = ((islower(father[i * 2]) || islower(father[i * 2 + 1])) && (islower(mother[i * 2]) || islower(mother[i * 2 + 1])));
        }
    }
    return possible;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string mother, father;
    cin >> mother >> father;

    int n;
    cin >> n;

    string genes[n];
    for (int i = 0; i < n; i++)
    {
        cin >> genes[i];
        if (possibleBaby(mother, father, genes[i]))
        {
            cout << "Possible baby." << '\n';
        }
        else
        {
            cout << "Not their baby!" << '\n';
        }
    }

    return 0;
}