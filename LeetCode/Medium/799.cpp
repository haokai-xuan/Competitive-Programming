class Solution {
    double pour(vector<vector<double>>& tower, int row, int glass) {
        if (row == 0) return tower[0][0];
        if (tower[row][glass] >= 0) return tower[row][glass];
        double leftParent = glass > 0 ? max(0.0, (pour(tower, row - 1, glass - 1) - 1) / 2) : 0;
        double rightParent = glass < row ? max(0.0, (pour(tower, row - 1, glass) - 1) / 2) : 0;
        tower[row][glass] = leftParent + rightParent;
        return tower[row][glass];
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(100);
        for (int i = 0; i < 100; i++) {
            tower[i].resize(i + 1, -1);
        }
        tower[0][0] = poured;
        return min(1.0, pour(tower, query_row, query_glass));
    }
};