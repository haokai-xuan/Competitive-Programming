class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxFreqSum(string s) {
        int maxVowel = 0;
        int maxCons = 0;

        unordered_map<char, int> vowels;
        unordered_map<char, int> cons;

        for (auto& c : s) {
            if (isVowel(c)) {
                vowels[c]++;
                maxVowel = max(maxVowel, vowels[c]);
            }
            else {
                cons[c]++;
                maxCons = max(maxCons, cons[c]);
            }
        }

        return maxVowel + maxCons;
    }
};