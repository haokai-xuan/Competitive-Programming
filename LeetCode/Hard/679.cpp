class Solution {
    double EPS = 1e-6;
    bool dfs(vector<double> nums) {
        if (nums.size() == 1)
            return abs(nums[0] - 24.0) < EPS;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }
                for (double val : candidates(nums[i], nums[j])) {
                    next.push_back(val);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
    vector<double> candidates(double a, double b) {
        vector<double> v;
        v.push_back(a + b);
        v.push_back(a - b);
        v.push_back(b - a);
        v.push_back(a * b);
        v.push_back(a / b);
        v.push_back(b / a);
        return v;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int& n : cards) nums.push_back(static_cast<double>(n));
        return dfs(nums);
    }
};