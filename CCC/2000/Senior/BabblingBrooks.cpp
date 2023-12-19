#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<float> streams;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        streams.push_back(val);
    }

    int input;
    cin >> input;

    while (input != 77)
    {
        int pos, percentage;
        if (input == 99)
        {
            cin >> pos >> percentage;
            pos--;

            float curr = streams[pos];

            streams[pos] = curr * ((float)percentage / 100);
            streams.insert(streams.begin() + pos + 1, curr - (curr * ((float)percentage / 100)));
        }
        else if (input == 88)
        {
            cin >> pos;
            pos--;

            streams[pos + 1] += streams[pos];
            streams.erase(streams.begin() + pos);
        }

        cin >> input;
    }

    for (auto i : streams)
    {
        cout << (int)i << ' ';
    }

    return 0;
}