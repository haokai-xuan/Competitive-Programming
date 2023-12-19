#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);                   // read the entre line
    int happy = 0, sad = 0;            // initialize each count of happy and sad to 0
    for (int i = 0; i < s.size(); i++) // loop through the line to check for faces
    {
        if (s[i] == ':' && s[i + 1] == '-' && s[i + 2] == ')') // if found ':-)'
            happy++;                                           // increment happy by 1
        if (s[i] == ':' && s[i + 1] == '-' && s[i + 2] == '(') // if found ':-('
            sad++;                                             // increment sad by 1
    }
    if (happy == 0 && sad == 0)   // if happy nor sad faces appear
        cout << "none" << '\n';   // print 'none'
    else if (happy == sad)        // if happy and sad faces appear the same amount of times
        cout << "unsure" << '\n'; // print 'unsure'
    else if (happy > sad)         // if happy faces appear more than sad faces
        cout << "happy" << '\n';  // print 'happy'
    else                          // if sad faces appear more than happy faces
        cout << "sad" << '\n';    // print 'sad'

    return 0;
}