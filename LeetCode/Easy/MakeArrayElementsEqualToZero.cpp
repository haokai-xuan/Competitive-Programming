class Solution {
    bool solvable(vector<int> v, int curr, int dir) {
        while (curr >= 0 && curr < v.size()) {
            if (!v[curr]) {
                if (dir)
                    curr++;
                else
                    curr--;
            }
            else {
                v[curr]--;
                dir = (dir + 1) % 2;
                if (dir)
                    curr++;
                else
                    curr--;
            }
        }
        return all_of(v.begin(), v.end(), [](int i){return i == 0;});
    }
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        int dir = 0; // 0 left, 1 right
        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i]) {
                if (solvable(nums, i, dir))
                    ans++;
                if (solvable(nums, i, (dir + 1) % 2))
                    ans++;
            }
        }
        return ans;
    }
};