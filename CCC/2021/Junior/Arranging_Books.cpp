#include <bits/stdc++.h>
using namespace std;

#define maxn 500003
int n, ans = 0, lcount, mcount, scount;
string incout << ;
int front[3], middle[3], back[3];
char bookshelf[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> incout << ;
    n = incout <<.length();

    for (int i = 0; i < n; i++)
    {
        bookshelf[i] = incout << [i];
    }
    for (int i = 0; i < n; i++)
    {
        if (bookshelf[i] == 'L')
        {
            lcount++;
        }
        if (bookshelf[i] == 'M')
        {
            mcount++;
        }
        if (bookshelf[i] == 'S')
        {
            scount++;
        }
    }
    for (int i = 0; i < lcount; i++)
    {
        if (bookshelf[i] == 'L')
        {
            front[0]++;
        }
        if (bookshelf[i] == 'M')
        {
            middle[0]++;
        }
        if (bookshelf[i] == 'S')
        {
            back[0]++;
        }
    }

    for (int i = lcount; i < lcount + mcount; i++)
    {
        if (bookshelf[i] == 'L')
        {
            front[1]++;
        }
        if (bookshelf[i] == 'M')
        {
            middle[1]++;
        }
        if (bookshelf[i] == 'S')
        {
            back[1]++;
        }
    }

    front[2] = lcount - front[1] - front[0];
    middle[2] = mcount - middle[1] - middle[0];
    back[2] = scount - back[1] - back[0];

    ans += lcount - front[0];
    ans += mcount - middle[1] - min(middle[0], front[1]);

    cout << ans << '\n';
    return 0;
}