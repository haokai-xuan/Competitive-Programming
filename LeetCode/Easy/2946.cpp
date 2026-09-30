class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        int shifts = k % n;
        vector<vector<int>> copy = mat;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    copy[i][j] = mat[i][(j + shifts) % n];
                }
                else {
                    copy[i][j] = mat[i][(((j - shifts) % n) + n) % n];
                }
            }
        }

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (copy[i][j] != mat[i][j]) return false;
            }
        }

        return true;
    }
};