#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map<int, int> readings;

    for (int i = 0; i <= 1000; i++)
    {
        readings.insert({i, 0});
    }

    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        readings[r]++;
    }

    // Print the values of the readings map
    // for (auto it = readings.begin(); it != readings.end(); it++)
    // {
    //     cout << "Key: " << it->first << ", Value: " << it->second << '\n';
    // }

    int highest = 0;
    int second_highest = 0;

    for (const auto &[key, value] : readings)
    {
        if (value > highest)
        {
            second_highest = highest;
            highest = value;
        }
        else if (value > second_highest)
        {
            second_highest = value;
        }
    }

    // cout << highest << ' ' << second_highest;

    set<int> highestReadings;
    for (const auto &[key, value] : readings)
    {
        if (value == highest)
        {
            highestReadings.insert(key);
        }
    }

    // for (auto a : highestReadings)
    // {
    //     cout << a << ' ';
    // }

    int largestAbsoluteDifference = 0;
    for (int reading : highestReadings)
    {
        for (int otherReading : highestReadings)
        {
            int absoluteDifference = abs(reading - otherReading);
            if (absoluteDifference > largestAbsoluteDifference)
            {
                largestAbsoluteDifference = absoluteDifference;
            }
        }
    }

    if (highest = second_highest)
    {
        for (const auto &[key, value] : readings)
        {
            if (value == second_highest)
            {
                for (int reading : highestReadings)
                {
                    int diff = abs(reading - key);
                    if (diff > largestAbsoluteDifference)
                    {
                        largestAbsoluteDifference = diff;
                    }
                }
            }
        }
    }

    cout << largestAbsoluteDifference << '\n';
    return 0;
}
