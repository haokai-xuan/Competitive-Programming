class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> mp;
        for (char& c : s) mp[c]++;
        if (mp['a'] < k || mp['b'] < k || mp['c'] < k)
            return -1;
        int n = s.size();
        int maxWindow = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            mp[s[right]]--;
            while (mp[s[right]] < k) {
                mp[s[left]]++;
                left++;
            }
            maxWindow = max(maxWindow, right - left + 1);
        }
        return n - maxWindow;
    }
};