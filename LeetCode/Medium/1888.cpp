class Solution {
    string getTarget(int x, int start) {
        string s = "";
        for (int i = 0; i < 2 * x; i++) {
            s += '0' + start;
            start = (start + 1) % 2;
        }
        return s;
    }
public:
    int minFlips(string s) {
        int n = s.size();
        string t1 = getTarget(n, 0);
        string t2 = getTarget(n, 1);
        s += s;

        int left = 0;
        int ans1 = 0, ans2 = 0, ans = INT_MAX;
        for (int right = 0; right < n * 2; right++) {
            if (s[right] != t1[right]) ans1++;
            if (s[right] != t2[right]) ans2++;
            
            if (right - left + 1 == n) {
                ans = min(ans, min(ans1, ans2));
                if (s[left] != t1[left]) ans1--;
                if (s[left] != t2[left]) ans2--;
                left++;
            }
        }

        return ans;
    }
};