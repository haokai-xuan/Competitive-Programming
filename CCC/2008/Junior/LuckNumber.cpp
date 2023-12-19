#include <bits/stdc++.h>
using namespace std;

int main()
{
    // faster i/o for c++ users
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;                   // read the number of cases
    for (int i = 0; i < n; i++) // loop through each number
    {
        string num; // read the number as string for easier manipulation
        cin >> num;

        int curr = 0;
        int ans = 69;
        while (true)
        {
            curr = 0;
            for (int i = 0; i < num.size(); i++) // loop through each character of the number (which is of type string)
            {
                curr += num[i] - '0'; // add each character to the current sum by converting it to an int first using their ASCII values
            }
            ans = curr; // set the answer to the current number
            num = to_string(curr);
            if (ans <= 9) // if the number is has 1 digit...
            {
                cout << ans << '\n'; // print the answer
                break;               // end the loop
            }
            // if the answer has more than 1 digit, continue the process again
        }
    }

    return 0;
}