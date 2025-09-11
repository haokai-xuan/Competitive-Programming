class Solution {
    bool isVowel(char c) {
        string vowels = "AEIOU";
        
        for (auto& v : vowels) {
            if (c == v || c == v + 'a' - 'A')
                return true;
        }

        return false;
    }
public:
    string sortVowels(string s) {
        unordered_map<char, int> mp;
        for (auto& c : s) {
            if (isVowel(c))
                mp[c]++;
        }
        int ptr = 0;
        string candidates = "AEIOUaeiou";
        for (auto& c : candidates) {
            while (mp.find(c) != mp.end()) {
                if (isVowel(s[ptr])) {
                    s[ptr] = c;
                    mp[c]--;
                    if (mp[c] == 0) {
                        mp.erase(c);
                    }
                }
                ptr++;
            }
        }
        return s;
    }
};