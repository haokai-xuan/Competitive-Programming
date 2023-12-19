#include <bits/stdc++.h>
using namespace std;

int n, friends[10000] = {0}, distance_;

void bfs()
{
    int x, y;
    cin >> x >> y;
    while (!(x == 0 && y == 0))
    {
        bool visited[10000] = {false};
        distance_ = -1;

        while (!visited[x] && x != y)
        {
            visited[x] = true;
            distance_++;
            x = friends[x];
        }
        if (x == y)
        {
            cout << "Yes" << ' ' << distance_ << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
        cin >> x >> y;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        friends[x] = y;
    }
    bfs();
    return 0;
}