class Solution {
    bool isSorted(string& s) {
        char prev = 'a';
        for (auto& c : s) {
            if (c < prev) return false;
            prev = c;
        }
        return true;
    }
public:
    int minOperations(string s) {
        int n = s.size();
        if (isSorted(s)) return 0;
        if (n == 2) return -1;

        char minChar = *min_element(s.begin(), s.end());
        char maxChar = *max_element(s.begin(), s.end());

        if (minChar == s[0] || maxChar == s.back()) return 1;
        if (minChar == s.back() && maxChar == s[0] && (count(s.begin(), s.end(), maxChar) == 1 && count(s.begin(), s.end(), minChar) == 1)) return 3;
        return 2;
    }
};