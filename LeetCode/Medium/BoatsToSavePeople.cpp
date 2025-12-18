class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0, right = people.size() - 1;
        int ans = 0;
        sort(people.begin(), people.end());
        while (left <= right) {
            if (people[right] == limit) {
                ans++;
                right--;
            }
            else if (people[right] + people[left] > limit) {
                ans++;
                right--;
            }
            else {
                right--;
                left++;
                ans++;
            }
        }
        return ans;
    }
};