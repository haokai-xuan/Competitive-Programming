class Solution {
    bool validPermute(unordered_map<char, int>& mp, unordered_map<char, int>& mpS1) {
        for (auto& [c, freq] : mp)
            if (freq != mpS1[c]) return false;
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int> mpS1;
        for (char& c : s1) mpS1[c]++;

        for (auto& [c, freq] : mpS1)
            cout << c << ": " << freq << '\n';

        int left = 0;
        unordered_map<char, int> mp;
        for (int right = 0; right < s2.size(); right++) {
            mp[s2[right]]++;
            int len = right - left + 1;
            if (len > s1.size()) {
                mp[s2[left]]--;
                if (mp[s2[left]] <= 0)
                    mp.erase(s2[left]);
                left++;
                len = right - left + 1;
            }
            if (len == s1.size() && mp == mpS1) return true;
        }

        return false;
    }
};