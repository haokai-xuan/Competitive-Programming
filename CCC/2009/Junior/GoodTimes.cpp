#include <bits/stdc++.h>
using namespace std;

int local_time(int t, int c)
{
    int time = t + c;
    if (time > 2400)
        time -= 2400;
    else if (time < 0)
    {
        time += 2400;
    }

    if (time % 100 >= 60)
    {
        time = int(time / 100) * 100 + 100 + (time % 100 - 60);
    }
    return time;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int time;
    cin >> time;
    cout << local_time(time, 0) << " in Ottawa" << '\n';
    cout << local_time(time, -300) << " in Victoria" << '\n';
    cout << local_time(time, -200) << " in Edmonton" << '\n';
    cout << local_time(time, -100) << " in Winnipeg" << '\n';
    cout << local_time(time, 0) << " in Toronto" << '\n';
    cout << local_time(time, 100) << " in Halifax" << '\n';
    cout << local_time(time, 130) << " in St. John's" << '\n';

    return 0;
}