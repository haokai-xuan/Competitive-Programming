class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mpST;
        unordered_map<char, char> mpTS;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (mpST.count(s[i])) {
                if (mpST[s[i]] != t[i])
                    return false;
            }
            else
                mpST[s[i]] = t[i];

            if (mpTS.count(t[i])) {
                if (mpTS[t[i]] != s[i])
                    return false;
            }
            else
                mpTS[t[i]] = s[i];
        }
        return true;
    }
};