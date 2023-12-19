#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    // scanf("%d", &t);

    for (int test = 0; test < t; test++)
    {
        vector<int> mountain;
        vector<int> branch;

        int n;
        cin >> n;
        // scanf("%d", &n);

        mountain.reserve(n);

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            // scanf("%d", &x);
            mountain.push_back(x);
        }

        int curr = 1;
        while (true)
        {
            if (!mountain.empty())
            {
                if (mountain.back() == curr)
                {
                    curr++;
                    mountain.pop_back();
                }
                else if (!branch.empty())
                {
                    if (branch.back() == curr)
                    {
                        curr++;
                        branch.pop_back();
                    }
                    else
                    {
                        int num = mountain.back();
                        mountain.pop_back();
                        branch.push_back(num);
                    }
                }
                else
                {
                    int num = mountain.back();
                    mountain.pop_back();
                    branch.push_back(num);
                }
            }
            else if (!branch.empty())
            {
                if (branch.back() == curr)
                {
                    curr++;
                    branch.pop_back();
                }
                else
                {
                    cout << 'N' << '\n';
                    // printf("%c\n", 'N');
                    break;
                }
            }
            else
            {
                cout << 'Y' << '\n';
                // printf("%c\n", 'Y');
                break;
            }
        }
    }
    return 0;
}