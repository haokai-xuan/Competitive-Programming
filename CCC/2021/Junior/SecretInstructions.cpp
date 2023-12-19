#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(nULL);
    cin.tie(0);

    string instruction;
    string previous_instruction = "";

    while (instruction != "99999")
    {
        cin >> instruction;
        if (instruction == "99999")
        {
            break;
        }

        int sum = (instruction[0] - '0') + (instruction[1] - '0');

        if (sum % 2 == 1)
        {
            cout << "left ";
            previous_instruction = "left ";
        }
        else if (sum == 0)
        {
            cout << previous_instruction;
        }
        else
        {
            cout << "right ";
            previous_instruction = "right ";
        }
        cout << instruction[2] << instruction[3] << instruction[4] << '\n';
    }

    return 0;
}