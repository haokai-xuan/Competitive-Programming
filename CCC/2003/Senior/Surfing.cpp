#include <bits/stdc++.h>
using namespace std;

int n;
map<string, vector<string>> legend;

void bfs(string first, string second)
{
    set<string> visited[n];
    visited->insert(first);

    queue<string> q;
    q.push(first);

    while (!q.empty())
    {
        string s = q.front();
        q.pop();

        if (s == second)
        {
            cout << "Can surf from " << first << " to " << second << '.' << '\n';
            return;
        }

        for (auto u : legend[s])
        {
            if (visited->find(u) != visited->end())
                continue;
            visited->insert(u);
            q.push(u);
        }
    }
    cout << "Can't surf from " << first << " to " << second << '.' << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    string webpage;
    string HTML = "";
    int start, end;
    string link;
    int size;

    for (int i = 0; i < n; i++)
    {
        cin >> webpage;
        cin >> HTML;
        while (HTML != "</HTML>")
        {
            if (HTML.find("HREF") != string::npos)
            {
                start = HTML.find("HREF") + 6;
                end = HTML.find('>');
                size = end - start - 1;

                link = HTML.substr(start, size);
                legend[webpage].push_back(link);

                cout << "Link from " << webpage << " to " << link << '\n';
            }
            cin >> HTML;
        }
    }

    string first, second;

    while (true)
    {
        cin >> first >> second;
        if (second == "End")
            break;
        bfs(first, second);
    }

    return 0;
}