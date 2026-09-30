class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for (int i = 0; i < s.size(); ++i) {
            if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')) {
                newStr += s[i];
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                newStr += s[i] + 32;
            }
        }

        string firstHalf = "", secondHalf = "";
        for (int i = 0; i < newStr.size() / 2; ++i) {
            firstHalf += newStr[i];
            secondHalf += newStr[newStr.size() - i - 1];
        }

        return firstHalf == secondHalf ? true : false;
    }
};
