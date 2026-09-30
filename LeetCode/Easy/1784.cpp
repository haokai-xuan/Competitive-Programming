class Solution {
public:
    bool checkOnesSegment(string s) {
        bool segDone = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0' && !segDone) segDone = true;
            else if (s[i] == '1' && segDone) return false;
        }
        return true;
    }
};