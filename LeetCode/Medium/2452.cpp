class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n = queries[0].size();
        for (int i = 0; i < queries.size(); i++) {
            bool valid = false;
            for (int j = 0; j < dictionary.size(); j++) {
                int switchesNeeded = 0;
                for (int k = 0; k < n; k++) {
                    if (queries[i][k] != dictionary[j][k]) switchesNeeded++;
                    if (switchesNeeded > 2) break;
                }
                if (switchesNeeded <= 2) {
                    valid = true;
                    break;
                }
            }
            if (valid) ans.push_back(queries[i]);
        }
        return ans;
    }
};