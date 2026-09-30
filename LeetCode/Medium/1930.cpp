class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for (char outer = 'a'; outer <= 'z'; outer++) {
            int first = s.find(outer);
            int last = s.rfind(outer);
            if (first != last) {
                unordered_set<char> middle;
                for (int i = first + 1; i < last; i++) {
                    middle.insert(s[i]);
                }
                ans += middle.size();
            }
        }
        return ans;
    }
};