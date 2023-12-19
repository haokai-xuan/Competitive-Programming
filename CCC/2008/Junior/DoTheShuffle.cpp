#include <bits/stdc++.h>
using namespace std;

vector<char> output = {
    'A', 'B', 'C', 'D', 'E'};

void button1()
{
    char cp = output[0];
    output.push_back(cp);
    output.erase(begin(output));
}

void button2()
{
    char cp = output[4];
    output.erase(output.begin() + 4);
    output.insert(begin(output), cp);
}
void button3()
{
    swap(output[0], output[1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> inputs;

    while (true)
    {
        int b, n;
        cin >> b >> n;

        if (b == 4)
        {
            break;
        }
        else
        {
            inputs.push_back({b, n});
        }
    }

    for (auto a : inputs)
    {
        int b = a.first;
        int n = a.second;

        for (int i = 0; i < n; i++)
        {
            if (b == 1)
            {
                button1();
            }
            if (b == 2)
            {
                button2();
            }
            if (b == 3)
            {
                button3();
            }
        }
    }

    for (char c : output)
    {
        cout << c << ' ';
    }

    return 0;
}
