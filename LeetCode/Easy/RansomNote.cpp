class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> ransomMp;
        for (int i = 0; i < ransomNote.size(); ++i) {
            ++ransomMp[ransomNote[i]];
        }

        map<char, int> magazineMp;
        for (int i = 0; i < magazine.size(); ++i) {
            ++magazineMp[magazine[i]];
        }

        for (const auto& u : ransomMp) {
            if (u.second > magazineMp[u.first]) {
                return false;
            }
        }

        return true;
    }
};
