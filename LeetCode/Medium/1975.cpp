class Solution {
    long long getAbsSum(vector<vector<int>>& m) {
        long long res = 0;
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m.size(); j++) {
                res += abs(m[i][j]);
            }
        }
        return res;
    }
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negCntParity = 0;
        int smallestAbsNum = INT_MAX;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[i][j] < 0) negCntParity = (negCntParity + 1) % 2;
                if (abs(matrix[i][j]) < smallestAbsNum) smallestAbsNum = abs(matrix[i][j]);
            }
        }
        cout << smallestAbsNum;
        long long ans = getAbsSum(matrix);
        if (!negCntParity) return ans;
        return ans - 2 * smallestAbsNum;
    }
};