class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto& n : nums) {
            vector<int> v;
            while (n) {
                v.push_back(n % 10);
                n /= 10;
            }
            while (!v.empty()) {
                ans.push_back(v.back());
                v.pop_back();
            }
        }
        return ans;
    }
};