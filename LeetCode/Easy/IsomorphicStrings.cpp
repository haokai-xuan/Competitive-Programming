class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> map_s_to_t;
        map<char, char> map_t_to_s;

        for (int i = 0; i < s.length(); i++) {
            if (map_s_to_t[s[i]] == NULL) {
                map_s_to_t[s[i]] = t[i];
            } else if (map_s_to_t[s[i]] != NULL) {
                if (map_s_to_t[s[i]] != t[i]) {
                    return false;
                }
            }

            if (map_t_to_s[t[i]] == NULL) {
                map_t_to_s[t[i]] = s[i];
            } else if (map_t_to_s[t[i]] != NULL) {
                if (map_t_to_s[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
