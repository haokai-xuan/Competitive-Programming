#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int yodellerscores[n] = {0};
    int worst[n] = {1};
    int rank[n];

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            yodellerscores[j] += num;
        }

        int temp[n];
        copy(yodellerscores, yodellerscores + n, temp);
        sort(temp, temp + n, greater<int>());

        for (int j = 0; j < n; j++)
        {
            auto it = find(temp, temp + n, yodellerscores[j]);
            rank[j] = distance(temp, it) + 1;

            if (rank[j] > worst[j])
            {
                worst[j] = rank[j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (rank[i] == 1)
        {
            cout << "Yodeller " << i + 1 << " is the TopYodeller: score " << yodellerscores[i] << ", worst rank " << worst[i] << '\n';
        }
    }
    return 0;
}