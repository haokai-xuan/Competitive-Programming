#include <bits/stdc++.h>
using namespace std;

struct quad
{
    int l, w, h;
    int volume = l * w * h;
};

bool volumeSorter(quad boxA, quad boxB)
{
    if (boxA.volume != boxB.volume)
    {
        return boxA.volume < boxB.volume;
    }
};

bool itemvolumeSorter(quad itemA, quad itemB)
{
    if (itemA.volume != itemB.volume)
    {
        return itemA.volume < itemB.volume;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<quad> boxes;
    vector<quad> items;

    int l, w, h;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> w >> h;
        boxes.push_back({l, w, h, l * w * h});
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> w >> h;
        items.push_back({l, w, h, l * w * h});
    }

    sort(boxes.begin(), boxes.end(), volumeSorter);
    // sort(items.begin(), items.end(), itemvolumeSorter);
    // after they're in ascending order, we can compare each smallest with each smallest

    for (int i = 0; i < n; i++)
    {
        int length, width, height;
        length = boxes[i].l;
        width = boxes[i].w;
        height = boxes[i].h;

        int temp[3] = {length, width, height};
        sort(temp, temp + 3);

        boxes[i].l = temp[0];
        boxes[i].w = temp[1];
        boxes[i].h = temp[2];
    }

    for (int i = 0; i < m; i++)
    {
        int length, width, height;
        length = items[i].l;
        width = items[i].w;
        height = items[i].h;

        int temp[3] = {length, width, height};
        sort(temp, temp + 3);

        items[i].l = temp[0];
        items[i].w = temp[1];
        items[i].h = temp[2];
    }

    // testing code
    // for (auto i : boxes)
    // {
    //     cout << i.l << ' ' << i.w << ' ' << i.h << ' ' << i.volume << '\n';
    // }

    for (int i = 0; i < m; i++)
    {
        bool gotans = false;
        int ans;
        for (int j = 0; j < n; j++)
        {
            if (boxes[j].l >= items[i].l && boxes[j].w >= items[i].w && boxes[j].h >= items[i].h)
            {
                gotans = true;
                ans = boxes[j].volume;
                break;
            }
        }
        if (gotans)
        {
            cout << ans << '\n';
        }
        else
        {
            cout << "Item does not fit." << '\n';
        }
    }

    return 0;
}