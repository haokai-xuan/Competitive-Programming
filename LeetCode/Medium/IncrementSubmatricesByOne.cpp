class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        vector<vector<int>> ps(n, vector<int>(n + 1, 0));
        for (auto& q : queries) {
            int tr = q[0], tc = q[1], br = q[2], bc = q[3];
            for (int r = tr; r <= br; r++) {
                ps[r][tc]++;
                ps[r][bc + 1]--;
            }
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += ps[i][j];
                mat[i][j] = sum;
            }
        }
        return mat;
    }
};