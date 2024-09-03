class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        string curr;
        for (int i = 1; i < strs.size(); ++i) {
            curr = strs[i];

            while (curr.find(prefix) != 0) {
                prefix.pop_back();
                if (prefix == "") {
                    return "";
                }
            }
        }
        return prefix;
    }
};
