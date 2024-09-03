class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mp_c_to_s;
        map<string, char> mp_s_to_c;

        int cnt = 0;
        for (char c : s) {
            if (c == ' ') {
                cnt++;
            }
        }

        if (pattern.size() != cnt + 1) {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++) {
            int j = 0;
            string str = "";
            while (s[j] != ' ') {
                str += s[j];
                if (j == s.size() - 1) {
                    break;
                }
                j++;
            }
            s = s.substr(j + 1);

            if (mp_c_to_s.find(pattern[i]) == mp_c_to_s.end()) {
                mp_c_to_s[pattern[i]] = str;
            } else if (mp_c_to_s.find(pattern[i]) != mp_c_to_s.end()) {
                if (str != mp_c_to_s[pattern[i]]) {
                    return false;
                }
            }

            if (mp_s_to_c.find(str) == mp_s_to_c.end()) {
                mp_s_to_c[str] = pattern[i];
            } else if (mp_s_to_c.find(str) != mp_s_to_c.end()) {
                if (pattern[i] != mp_s_to_c[str]) {
                    return false;
                }
            }
        }
        return true;
    }
};
