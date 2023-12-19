#include <bits/stdc++.h>
using namespace std;

void print_time(int t)
{
    int hours = t / 60;
    int minutes = t % 60;
    if (hours >= 24)
        hours -= 24;
    if (hours <= 9)
        cout << '0';
    cout << hours << ':';
    if (minutes <= 9)
        cout << '0';
    cout << minutes << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t1 = 7 * 60, t2 = 10 * 60, t3 = 15 * 60, t4 = 19 * 60;
    int distance = 120;
    string s;
    cin >> s;

    int hours = stoi(s.substr(0, 2));
    int minutes = stoi(s.substr(3, 2));
    int time_begin = hours * 60 + minutes;

    while (distance > 0)
    {
        time_begin += 10;
        if ((time_begin > t1 && time_begin <= t2) || (time_begin > t3 && time_begin <= t4))
            distance -= 5;
        else
            distance -= 10;
    }
    print_time(time_begin);
    return 0;
}