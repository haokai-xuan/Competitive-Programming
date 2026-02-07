class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> aSuf(n, 0), bPre(n, 0);
        int aCnt = 0, bCnt = 0;
        for (int i = 0; i < s.size(); i++) {
            bPre[i] = bCnt;
            if (s[i] == 'b') bCnt++;
        }
        for (int i = n - 1; i >= 0; i--) {
            aSuf[i] = aCnt;
            if (s[i] == 'a') aCnt++;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, aSuf[i] + bPre[i]);
        }
        return ans;
    }
};