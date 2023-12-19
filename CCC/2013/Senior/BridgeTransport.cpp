#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int w, n;
    cin >> w >> n;

    vector<int> carweight;
    carweight.push_back(0);
    carweight.push_back(0);
    carweight.push_back(0);

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        carweight.push_back(num);
    }

    carweight.push_back(w + 1);

    int cars_across = 0;
    int i = 3;

    int total_weight = carweight[i - 3] + carweight[i - 2] + carweight[i - 1] + carweight[i];

    while (total_weight <= w)
    {
        i++;
        cars_across++;

        total_weight = carweight[i - 3] + carweight[i - 2] + carweight[i - 1] + carweight[i];
    }

    cout << cars_across << '\n';

    return 0;
}