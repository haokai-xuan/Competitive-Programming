class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            while (j < s.size() && s[j] == s[i]) j++;
            j--;
            prev = curr;
            curr = j - i + 1;
            ans += min(curr, prev);
            i = j;
        }
        return ans;
    }
};