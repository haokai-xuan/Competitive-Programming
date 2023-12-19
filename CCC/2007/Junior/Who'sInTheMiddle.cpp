#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int nums[3];
    cin >> nums[0] >> nums[1] >> nums[2];

    sort(nums, nums + 3);
    cout << nums[1];

    return 0;
}