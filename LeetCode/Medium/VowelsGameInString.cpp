class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    bool doesAliceWin(string s) {
        for (auto& c : s) {
            if (isVowel(c))
                return true;
        }
        return false;
    }
};