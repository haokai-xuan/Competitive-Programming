class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int rows = strs.size(), cols = strs[0].size();
        for (int c = 0; c < cols; c++) {
            bool sorted = true;
            for (int r = 1; r < rows; r++) {
                if (strs[r][c] < strs[r - 1][c]) {
                    sorted = false;
                    break;
                }
            }
            ans += !sorted ? 1 : 0;
        }
        return ans;
    }
};