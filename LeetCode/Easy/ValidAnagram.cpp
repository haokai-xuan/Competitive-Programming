class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp_s;
        map<char, int> mp_t;

        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            mp_s[s[i]]++;
            mp_t[t[i]]++;
        }
        return mp_s == mp_t ? true : false;
    }
};
