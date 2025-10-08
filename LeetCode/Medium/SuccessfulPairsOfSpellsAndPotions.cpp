class Solution {
    int bisectLeft(vector<int>& v, long long target) {
        int left = 0, right = v.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (v[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int& s : spells) {
            long long p = success % s ? success / s + 1 : success / s;
            int index = bisectLeft(potions, p);
            int val = potions.size() - index;
            ans.push_back(val);
        }
        return ans;
    }
};