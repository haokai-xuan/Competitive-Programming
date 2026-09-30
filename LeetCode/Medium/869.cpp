class Solution {
    bool check(const string& s1, const string& s2) {
        if (s1.size() != s2.size())
            return false;
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for (int i = 0; i < s1.size(); i++) {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }

        for (int i = 0; i < s1.size(); i++) {
            if (m1[s1[i]] != m2[s1[i]])
                return false;
        }

        return true;
    }
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        int curr = 1;
        for (int i = 0; i <= 29; i++) {
            if (check(s, to_string(curr)))
                return true;
            curr *= 2;
        }

        return false;
    }
};