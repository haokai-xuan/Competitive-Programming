class Solution {
public:
    int minOperations(string s) {
        string orig = s;
        int ans = 0, ans2 = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                s[i] = s[i] == '1' ? '0' : '1';
                ans++;
            }
        }
        
        s = orig;
        s[0] = s[0] == '1' ? '0' : '1';
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                s[i] = s[i] == '1' ? '0' : '1';
                ans2++;
            }
        }
        cout << ans << ' ' << ans2;
        return min(ans, ans2);
    }
};