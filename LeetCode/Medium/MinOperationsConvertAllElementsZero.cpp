class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> s;
        int ans = 0;
        for (int& n : nums) {
            while (!s.empty() && n < s.top()) {
                s.pop();
            }
            if (!n) continue;
            if (s.empty() || n > s.top()) {
                ans++;
                s.push(n);
            }
        }
        return ans;
    }
};