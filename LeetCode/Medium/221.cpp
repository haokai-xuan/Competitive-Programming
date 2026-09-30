class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    continue;
                }

                int left = (j > 0) ? memo[i][j - 1] : 0;
                int top = (i > 0) ? memo[i - 1][j] : 0;
                int diag = (i > 0 && j > 0) ? memo[i - 1][j - 1] : 0;

                memo[i][j] = 1 + min(left, min(top, diag));
            }
        }
        
        int side_len = 0;
        for (vector<int> v : memo) {
            for (int i : v) {
                side_len = max(side_len, i);
            }
        }
        return side_len * side_len;
    }
};