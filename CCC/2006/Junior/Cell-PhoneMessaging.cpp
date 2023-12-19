#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string text;
    int keypresses = 0;
    cin >> text;

    string one_press = "adgjmptw", two_press = "behknqux", three_press = "cfilorvy", four_press = "sz";
    string key1 = "abc", key2 = "def", key3 = "ghi", key4 = "jkl", key5 = "mno", key6 = "pqrs", key7 = "tuv", key8 = "wxyz";

    while (text != "halt")
    {
        for (int i = 0; i < text.size(); i++)
        {
            if (one_press.find(text[i]) != string::npos)
            {
                keypresses++;
            }
            else if (two_press.find(text[i]) != string::npos)
            {
                keypresses += 2;
            }
            else if (three_press.find(text[i]) != string::npos)
            {
                keypresses += 3;
            }
            else if (four_press.find(text[i]) != string::npos)
            {
                keypresses += 4;
            }

            if (i > 0)
            {
                if (key1.find(text[i]) != string::npos && key1.find(text[i - 1]) != string::npos)
                {
                    keypresses += 2;
                }
                else if (key2.find(text[i]) != string::npos && key2.find(text[i - 1]) != string::npos)
                {
                    keypresses += 2;
                }
                else if (key3.find(text[i]) != string::npos && key3.find(text[i - 1]) != string::npos)
                {
                    keypresses += 2;
                }
                if (key4.find(text[i]) != string::npos && key4.find(text[i - 1]) != string::npos)
                {
                    keypresses += 2;
                }
                if (key5.find(text[i]) != string::npos && key5.find(text[i - 1]) != string::npos)
                {
                    keypresses += 2;
                }
                if (key6.find(text[i]) != string::npos && key6.find(text[i - 1]) != string::npos)
                {
                    keypresses += 2;
                }
                if (key7.find(text[i]) != string::npos && key7.find(text[i - 1]) != string::npos)
                {
                    keypresses += 2;
                }
                if (key8.find(text[i]) != string::npos && key8.find(text[i - 1]) != string::npos)
                {
                    keypresses += 2;
                }
            }
        }

        cout << keypresses << '\n';
        cin >> text;
        keypresses = 0;
    }

    return 0;
}