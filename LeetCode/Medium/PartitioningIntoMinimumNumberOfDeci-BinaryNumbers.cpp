class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (int i = n.size(); i >= 0; i--) {
            int digit = n[i] - '0';
            ans = max(ans, digit);
        }
        return ans;
    }
};