class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        vector<string> words(strs.size(), "");
        for (int i = 0; i < strs[0].size(); i++) {
            bool valid = true;
            bool repeat = false;
            for (int j = 0; j < strs.size(); j++) {
                if (j > 0 && strs[j][i] == strs[j - 1][i]) repeat = true;
                words[j].push_back(strs[j][i]);
                if (j > 0 && words[j] < words[j - 1]) {
                    valid = false;
                    for (int k = j; k >= 0; k--) {
                        words[k].pop_back();
                    }
                    break;
                }
            }
            if (!valid) ans++;
            else if (repeat) continue;
            else return ans;
        }
        return ans;
    }
};