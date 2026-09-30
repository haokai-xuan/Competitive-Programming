class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> cntCol(n, 0);
        vector<int> cntRow(m, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) {
                    cntCol[j]++;
                    cntRow[i]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] && cntRow[i] == 1 && cntCol[j] == 1) {
                    ans++;
                    cout << i << ' ' << j << '\n';
                }
            }
        }
        return ans;
    }
};