#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w;
    cin >> w;

    string input_string = "WELCOME TO CCC GOOD LUCK TODAY";
    stringstream ss(input_string);

    vector<string> strings;
    string line;
    string word;

    while (ss >> word)
    {
        if (line.size() + word.size() > w)
        {
            strings.push_back(line);
            line = word + ' ';
        }
        else if (line.size() + word.size() <= w)
        {
            line += word + ' ';
        }
    }
    strings.push_back(line);

    // for (string s : strings)
    // {
    //     cout << s << '\n';
    // }

    for (int x = 0; x < strings.size(); x++)
    {
        int dots = w - (strings[x].size() - count(strings[x].begin(), strings[x].end(), ' '));
        stringstream temp(strings[x]);
        vector<string> words;
        string w;
        while (temp >> w)
        {
            words.push_back(w);
        }
        int i = 0;
        while (dots > 0)
        {
            if (i == words.size() || i == words.size() - 1)
            {
                i = 0;
            }
            words[i] += '.';
            dots--;
            i++;
        }
        strings[x] = "";
        for (int i = 0; i < words.size(); i++)
        {
            strings[x] += words[i];
        }
    }

    for (int x = 0; x < strings.size(); x++)
    {
        cout << strings[x] << endl;
    }

    return 0;
}
