class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;

        int i = s.size() - 1;
        while (s[i] == ' ') {
            --i;
        }
        for (int j = i; j >= 0; --j) {
            if (s[j] == ' ') {
                break;
            }
            cnt++;
        }
        return cnt;
    }
};
