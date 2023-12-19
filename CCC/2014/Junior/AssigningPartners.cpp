#include <bits/stdc++.h>
using namespace std;

int n;

int get_index(string arr[], string elem)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == elem)
        {
            return i;
            break;
        }
        i++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string list[n];
    string list2[n];

    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> list2[i];
    }

    int i = 0;
    bool state = true; // true = good; false = bad;
    while (i < n && state)
    {
        int pos = get_index(list, list2[i]);
        if (list[i] != list2[pos] || pos == i)
            state = false;
        i++;
    }
    if (state)
        cout << "good" << '\n';
    else
        cout << "bad" << '\n';
    return 0;
}