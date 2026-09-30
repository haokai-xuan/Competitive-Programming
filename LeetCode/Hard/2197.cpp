class Solution {
    int gcd(int a, int b) {
        if (a == 0 || b == 0)
            return a == 0 ? b : a;
        return gcd(b, a % b);
    }
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;

        for (auto& num : nums) {
            s.push(num);
            while (s.size() >= 2) {
                int a = s.top();
                s.pop();
                int b = s.top();
                int GCD = gcd(a, b);
                if (GCD > 1) {
                    s.pop();
                    s.push(a / GCD * b);
                }
                else {
                    s.push(a);
                    break;
                }
            }
        }
        
        int len = s.size();
        vector<int> ans(len);
        while (!s.empty()) {
            ans[--len] = s.top();
            s.pop();
        }
        
        return ans;
    }
};