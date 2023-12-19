#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string instruction;
    getline(cin >> ws, instruction);

    int a = 0, b = 0;

    while (instruction != "7")
    {
        if (instruction[0] == '1')
        {
            if (instruction[2] == 'A')
            {
                if (instruction[4] == '-')
                {
                    string temp = "";
                    int i = 5;
                    while (isdigit(instruction[i]))
                    {
                        temp.push_back(instruction[i]);
                        i++;
                    }
                    a = -1 * stoi(temp);
                }
                else
                {
                    string temp = "";
                    int i = 4;
                    while (isdigit(instruction[i]))
                    {
                        temp.push_back(instruction[i]);
                        i++;
                    }
                    a = stoi(temp);
                }
            }
            else if (instruction[2] == 'B')
            {
                if (instruction[4] == '-')
                {
                    string temp = "";
                    int i = 5;
                    while (isdigit(instruction[i]))
                    {
                        temp.push_back(instruction[i]);
                        i++;
                    }
                    b = -1 * stoi(temp);
                }
                else
                {
                    string temp = "";
                    int i = 4;
                    while (isdigit(instruction[i]))
                    {
                        temp.push_back(instruction[i]);
                        i++;
                    }
                    b = stoi(temp);
                }
            }
        }
        else if (instruction[0] == '2')
        {
            if (instruction[2] == 'A')
            {
                cout << a << '\n';
            }
            else
            {
                cout << b << '\n';
            }
        }
        else if (instruction[0] == '3')
        {
            if (instruction[2] == 'A')
            {
                if (instruction[4] == 'A')
                {
                    a += a;
                }
                else
                {
                    a += b;
                }
            }
            else
            {
                if (instruction[4] == 'A')
                {
                    b += a;
                }
                else
                {
                    b += b;
                }
            }
        }
        else if (instruction[0] == '4')
        {
            if (instruction[2] == 'A')
            {
                if (instruction[4] == 'A')
                {
                    a *= a;
                }
                else
                {
                    a *= b;
                }
            }
            else
            {
                if (instruction[4] == 'A')
                {
                    b *= a;
                }
                else
                {
                    b *= b;
                }
            }
        }
        else if (instruction[0] == '5')
        {
            if (instruction[2] == 'A')
            {
                if (instruction[4] == 'A')
                {
                    a -= a;
                }
                else
                {
                    a -= b;
                }
            }
            else
            {
                if (instruction[4] == 'A')
                {
                    b -= a;
                }
                else
                {
                    b -= b;
                }
            }
        }
        else if (instruction[0] == '6')
        {
            if (instruction[2] == 'A')
            {
                if (instruction[4] == 'A')
                {
                    a /= a;
                }
                else
                {
                    a /= b;
                }
            }
            else
            {
                if (instruction[4] == 'A')
                {
                    b /= a;
                }
                else
                {
                    b /= b;
                }
            }
        }
        getline(cin >> ws, instruction);
    }
    return 0;
}