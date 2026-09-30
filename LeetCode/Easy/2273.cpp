class Solution {
    bool isAnagram(string& s1, string& s2) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (char& c : s1) mp1[c]++;
        for (char& c : s2) mp2[c]++;

        return mp1 == mp2;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<bool> inRes(words.size(), true);
        for (int i = words.size() - 1; i >= 1; i--) {
            while (i >= 1 && isAnagram(words[i], words[i - 1])) {
                inRes[i] = false;
                i--;
            }
        }
        vector<string> ans;
        for (int i = 0; i < inRes.size(); i++) {
            if (inRes[i]) ans.push_back(words[i]);
        }
        return ans;
    }
};