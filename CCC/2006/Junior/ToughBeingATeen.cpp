#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> task(8);
    vector<vector<int>> prereq(8);

    prereq[1].push_back(7);
    task[7]++;
    prereq[1].push_back(4);
    task[4]++;
    prereq[2].push_back(1);
    task[1]++;
    prereq[3].push_back(4);
    task[4]++;
    prereq[3].push_back(5);
    task[5]++;

    while (true)
    {
        int x, y;
        cin >> x >> y;

        if (x == 0 && y == 0)
            break;
        else
        {
            prereq[x].push_back(y);
            task[y]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    queue<int> seq;

    for (int i = 1; i <= 7; i++)
    {
        if (task[i] == 0)
            pq.push(i); // can complete immediately
    }

    while (!pq.empty())
    {
        int key = pq.top();
        seq.push(key);
        pq.pop();

        for (int i = 0; i < prereq[key].size(); i++)
        {
            int taskNum = prereq[key][i];
            task[taskNum]--;
            if (task[taskNum] == 0)
                pq.push(taskNum); // no tasks needs to be completed before this, ready to process node
        }
    }

    if (seq.size() == 7)
    {
        while (!seq.empty())
        {
            cout << seq.front() << ' ';
            seq.pop();
        }
    }
    else
    {
        cout << "Cannot complete these tasks. Going to bed." << '\n';
    }

    return 0;
}