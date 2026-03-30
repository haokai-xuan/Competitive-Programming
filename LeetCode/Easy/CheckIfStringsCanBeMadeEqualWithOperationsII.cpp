class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even1(26), odd1(26);
        vector<int> even2(26), odd2(26);

        for (int i = 0; i < s1.size(); i++) {
            if (i % 2) {
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            }
            else {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            }
        }

        return even1 == even2 && odd1 == odd2;
    }
};