class Solution {
public:
    string smallestPalindrome(string s) {
        if (s.size() <= 2) return s;
        unordered_map<char, int> mp;
        for (char& c : s) mp[c]++;
        string ans = "";
        string middle = "";

        for (char c = 'a'; c <= 'z'; c++) {
            if (mp[c] % 2) middle = c;

            mp[c] /= 2;

            while (mp[c]) {
                ans += c;
                mp[c]--;
            }
        }

        string rev = ans;
        reverse(rev.begin(), rev.end());
        ans += middle + rev;

        return ans;
    }
};