#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string original;
    for (int i = 0; i < n; i++)
    {
        cin >> original;

        vector<int> num;
        for (char c : original)
        {
            num.push_back(c - '0');
        }

        for (int i : num)
        {
            cout << i;
        }
        cout << '\n';

        while (num.size() > 2)
        {
            int last = num.back();
            num.pop_back();
            if (last <= num.back())
            {
                num.back() -= last;
            }
            else
            {
                num.back() = num.back() - last + 10;
                int pos = num.size() - 2;
                while (num[pos] == 0)
                {
                    num[pos] = 9;
                    pos--;
                }
                num[pos]--;
            }
            while (num.front() == 0)
            {
                num.erase(num.begin() + 0);
            }
            for (int i : num)
            {
                cout << i;
            }
            cout << '\n';
        }

        if (num.size() == 1)
            num.push_back(0);
        int final = num[0] * 10 + num[1];

        cout << "The number ";
        for (char c : original)
        {
            cout << c;
        }
        if (final % 11 == 0)
        {
            cout << " is divisible by 11." << '\n';
        }
        else
        {
            cout << " is not divisible by 11." << '\n';
        }
        if (i != n - 1)
        {
            cout << '\n';
        }
    }
    return 0;
}
