class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ans = 0;
        int cols = mat[0].size(), rows = mat.size();
        for (int i = 0; i < cols; i++) {
            int prevNumOnes = INT_MAX;
            for (int j = 0; j < rows; j++) {
                int minWidth = INT_MAX;
                for (int k = j; k < rows; k++) {
                    int cnt = 0;
                    int col = i;
                    while (col < cols && mat[k][col] == 1) {
                        col++;
                        cnt++;
                    }
                    minWidth = min(minWidth, cnt);
                    if (minWidth == 0) break;
                    ans += minWidth;
                }
            }
        }
        return ans;
    }
};