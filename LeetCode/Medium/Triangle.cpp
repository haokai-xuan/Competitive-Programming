class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size() - 2;

        while (row >= 0) {
            for (int i = 0; i <= row; i++) {
                triangle[row][i] += min(triangle[row + 1][i], triangle[row + 1][i + 1]);
            }
            row--;
        }

        return triangle[0][0];
    }
};