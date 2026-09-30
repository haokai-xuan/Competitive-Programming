class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int index = 0, ans = 0;
        bool broken[26] = {false};
        for (char& c : brokenLetters) {
            broken[c - 'a'] = true;
        }
        while (index < text.size()) {
            if (text[index] == ' ') {
                ans++;
            }
            else if (broken[text[index] - 'a']) {
                while (index < text.size() && text[index] != ' ')
                    index++;
                if (index == text.size())
                    return ans;
            }
            index++;
        }

        return ans + 1;
    }
};