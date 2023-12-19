#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char turn;
    string place;

    deque<char> t;
    deque<string> p;

    while (place != "SCHOOL")
    {
        cin >> turn >> place;
        t.push_front(turn);
        p.push_front(place);
    }

    for (int i = 0; i < t.size(); i++)
    {
        cout << "Turn ";
        if (t[i] == 'R')
        {
            cout << "LEFT";
        }
        else
        {
            cout << "RIGHT";
        }

        if (i != t.size() - 1)
        {
            cout << " onto " << p[i + 1] << " street." << '\n';
        }
        else
        {
            cout << " into your HOME." << '\n';
        }
    }

    return 0;
}