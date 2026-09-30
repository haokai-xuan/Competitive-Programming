class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        
        unordered_map<int, pair<int, int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            int dig_sum = get_digit_sum(nums[i]);
            if (mp.count(dig_sum)) {
                if (!mp[dig_sum].second) {
                    mp[dig_sum].second = nums[i];
                }
                else {
                    int bigger = max(mp[dig_sum].first, mp[dig_sum].second);
                    int smaller = min(mp[dig_sum].first, mp[dig_sum].second);

                    mp[dig_sum].first = bigger;
                    mp[dig_sum].second = max(smaller, nums[i]);
                }

                ans = max(ans, mp[dig_sum].first + mp[dig_sum].second);
            }
            else {
                mp[dig_sum] = {nums[i], 0};
            }
        }

        return ans;    
    }

private:
    int get_digit_sum(int n) {
        string s = to_string(n);
        
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += s[i] - '0';
        }

        return ans;
    }
};