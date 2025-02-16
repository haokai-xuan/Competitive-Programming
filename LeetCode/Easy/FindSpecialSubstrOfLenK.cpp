class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int len = s.size();
        if (k > len)
            return false;
        if (len == 1 && k == 1)
            return true;
        
        for (int i = 0; i <= len - k; i++) {
            char c = s[i];
            bool maybe = true;
            for (int j = 1; j < k; j++) {
                if (s[i + j] == c) {
                    maybe = true;
                    continue;
                }
                maybe = false;
                break;
            }
            if (maybe) {
                if (len == k)
                    return true;
                else if (i == 0 && i + k < len && s[i + k] != c)
                    return true;
                else if (i == len - k && i - 1 >= 0 && s[i - 1] != c)
                    return true;
                else if (i - 1 >= 0 && i + k < len && s[i - 1] != c && s[i + k] != c)
                    return true;
            }
        }

        return false;
    }
}