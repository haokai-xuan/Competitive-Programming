class Solution {
public:
    bool hasSameDigits(string s) {
        if (s.size() == 2)
            return s[0] == s[1];
        string newS = "";
        for (int i = 0; i < s.size() - 1; i++) {
            newS += (((s[i] - '0') + (s[i + 1] - '0')) % 10) + '0';
        }
        cout << newS << '\n';
        return hasSameDigits(newS);
    }
};