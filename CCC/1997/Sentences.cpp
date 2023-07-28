#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int s, v, o;
        cin >> s >> v >> o;

        vector<string> subjects, verbs, objects;

        string str;
        for (int j = 0; j < s; j++)
        {
            getline(cin >> ws, str);
            subjects.push_back(str);
        }
        for (int j = 0; j < v; j++)
        {
            getline(cin >> ws, str);
            verbs.push_back(str);
        }
        for (int j = 0; j < o; j++)
        {
            getline(cin >> ws, str);
            objects.push_back(str);
        }

        vector<string> ans;
        for (int a = 0; a < s; a++)
        {
            for (int b = 0; b < v; b++)
            {
                for (int c = 0; c < o; c++)
                {
                    cout << subjects[a] << ' ' << verbs[b] << ' ' << objects[c] << '.' << '\n';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}