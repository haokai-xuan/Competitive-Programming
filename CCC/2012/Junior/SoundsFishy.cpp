#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }

    set<int> t;
    for (int i : arr)
    {
        t.insert(i);
    }

    if (is_sorted(arr, arr + 4) && t.size() == 4)
    {
        cout << "Fish Rising" << '\n';
    }
    else if (is_sorted(arr, arr + 4, greater<int>()) && t.size() == 4)
    {
        cout << "Fish Diving" << '\n';
    }
    else if (t.size() == 1)
    {
        cout << "Fish At Constant Depth" << '\n';
    }
    else
    {
        cout << "no Fish" << '\n';
    }

    return 0;
}