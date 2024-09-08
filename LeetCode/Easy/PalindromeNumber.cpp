class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);

        if (s.size() == 1)
            return true;

        for (int i = 0, j = s.size() - 1; i <= s.size() / 2, j >= s.size() / 2;
             i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};
