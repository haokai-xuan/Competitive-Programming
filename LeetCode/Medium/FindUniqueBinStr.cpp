class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, bool> mp;
        for (const string &str : nums) {
            mp[str] = true;
        }
        string ans = "";
        int len = nums[0].size();
        solve(mp, ans, len);
        return ans;
    }

private:
    bool solve(unordered_map<string, bool> &mp, string &curr, const int &len) {
        if (curr.size() == len) {
            if (mp.count(curr) == 0)
                return true;
            return false;
        }

        for (char c = '0'; c <= '1'; c++) {
            curr += c;
            if (solve(mp, curr, len))
                return true;
            curr.pop_back();
        }

        return false;
    }
};