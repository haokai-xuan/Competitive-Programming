#include <bits/stdc++.h>
using namespace std;

int d;
int t = 1200, thousands, hundreds, tens, minutes, total = 0;

int add_time(int time)
{
    time++;
    if ((time % 100) >= 60)
        time += 40;
    if (time >= 1300)
        time -= 1200;
    return time;
}

int main()
{
    cin >> d;
    total = (d / 720) * 31;

    for (int i = 0; i < d % 720; i++)
    {
        t = add_time(t);
        if (t < 1000)
        {
            hundreds = t / 100;
            tens = (t % 100) / 10;
            minutes = t % 10;
            if (hundreds - tens == tens - minutes)
                total++;
        }
        else
        {
            thousands = t / 1000;
            hundreds = t % 1000 / 100;
            tens = (t % 100) / 10;
            minutes = t % 10;
            if ((thousands - hundreds == hundreds - tens) && (hundreds - tens == tens - minutes))
                total++;
        }
    }
    cout << total << '\n';
    return 0;
}