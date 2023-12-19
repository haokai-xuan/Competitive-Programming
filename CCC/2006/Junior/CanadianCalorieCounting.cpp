#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<int, int> burger = {
        {1, 461},
        {2, 431},
        {3, 420},
        {4, 0}};

    map<int, int> side = {
        {1, 100},
        {2, 57},
        {3, 70},
        {4, 0}};

    map<int, int> drink = {
        {1, 130},
        {2, 160},
        {3, 118},
        {4, 0}};

    map<int, int> dessert = {
        {1, 167},
        {2, 266},
        {3, 75},
        {4, 0}};

    int calories = 0, a, b, c, d;
    cin >> a;
    calories += burger[a];
    cin >> b;
    calories += side[b];
    cin >> c;
    calories += drink[c];
    cin >> d;
    calories += dessert[d];

    cout << "Your total Calorie count is " << calories << '.' << '\n';

    return 0;
}