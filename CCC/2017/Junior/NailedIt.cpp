#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // he length of the fence is the number of boards used to make it
    // the height of the fence is the length of each board in the fence

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> L(2001);
    vector<int> F(4001);

    for (int board : arr)
    {
        L[board]++;
    }

    for (int i = 0; i < L.size() - 1; i++)
    {
        for (int j = i; j < L.size(); j++)
        {
            if (i == j)
                F[i + j] += L[i] / 2;
            else
                F[i + j] += min(L[i], L[j]);
        }
    }

    int longest_length = 0, different_heights = 0;

    for (int fencelength : F)
    {
        if (fencelength > longest_length)
            longest_length = fencelength,
            different_heights = 1;
        else if (fencelength == longest_length)
        {
            different_heights++;
        }
    }
    cout << longest_length << ' ' << different_heights << '\n';
    return 0;
}