#include <bits/stdc++.h>
using namespace std;

const unsigned int rows = 10, cols = 9;
vector<vector<string>> original(rows, vector<string>(cols));
vector<vector<int>> value(rows, vector<int>(cols));

int solve(string s)
{
    int v;
    if (s[0] >= 'A' && s[1] <= 'Z')
    {
        v = value[s[0] - 'A'][s[1] - '1'];
    }
    else
    {
        v = stoi(s);
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> original[i][j];
            value[i][j] = -1;
        }
    }

    bool change = true;
    while (change)
    {
        change = false;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                istringstream iss(original[i][j]);
                string token;
                int v = 0, x = 0;

                while (getline(iss, token, '+') && x != -1)
                {
                    x = solve(token);
                    if (x == -1)
                    {
                        v = -1;
                    }
                    else
                    {
                        v += x;
                    }
                }
                if (value[i][j] != v)
                {
                    change = true;
                    value[i][j] = v;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (value[i][j] == -1)
            {
                cout << "* ";
            }
            else
            {
                cout << value[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}