class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int ones = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '1') ones++;
            int j = i;
            while (j < s.size() && s[j] == '0') {
                j++;
            }
            if (i != j) {
                ans += ones;
                i = j - 1;
            }
        }
        return ans;
    }
};