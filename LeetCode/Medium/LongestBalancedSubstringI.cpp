class Solution {
    bool isBalanced(unordered_map<char, int>& mp) {
        int occ = -1;
        for (auto& [ch, freq] : mp) {
            if (occ == -1) occ = freq;
            else if (freq != occ) return false;
        }
        return true;
    }
public:
    int longestBalanced(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < s.size(); j++) {
                mp[s[j]]++;
                if (isBalanced(mp)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};