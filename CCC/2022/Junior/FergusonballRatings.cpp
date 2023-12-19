#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> score;

    for (int i = 0; i < n; i++)
    {
        int num, num2;
        cin >> num >> num2;
        score.push_back(make_pair(num, num2));
    }

    for (int i = 0; i < n; i++)
    {
        score[i].first *= 5;
        score[i].second *= 3;
    }
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (score[i].first - score[i].second > 40)
        {
            total++;
        }
    }
    cout << total;
    if (total == n)
        cout << '+';
    return 0;
}