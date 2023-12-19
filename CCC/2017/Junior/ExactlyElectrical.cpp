#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pair<int, int> start_pos;
    pair<int, int> destination;

    cin >> start_pos.first >> start_pos.second;
    cin >> destination.first >> destination.second;

    int electircal_charge;
    cin >> electircal_charge;

    int distance = abs(destination.first - start_pos.first) + abs(destination.second - start_pos.second);
    if ((distance <= electircal_charge && distance % 2 == 0 && electircal_charge % 2 == 0) || (distance <= electircal_charge && distance % 2 && electircal_charge % 2))
    {
        cout << 'Y' << '\n';
    }
    else
    {
        cout << 'n' << '\n';
    }
}