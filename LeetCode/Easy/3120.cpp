class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s;
        for (char& c : word) {
            s.insert(c);
        }
        int ans = 0;
        vector<bool> counted(26, false);
        for (char c : word) {
            char cLower = tolower(c);
            if (!counted[cLower - 'a']) {
                if ('a' <= c && c <= 'z') {
                    if (s.count(c - 32)) {
                        ans++;
                        counted[cLower - 'a'] = true;
                    }
                }
                else {
                    if (s.count(c + 32)) {
                        ans++;
                        counted[cLower - 'a'] = true;
                    }
                }
            }
        }

        return ans;
    }
};