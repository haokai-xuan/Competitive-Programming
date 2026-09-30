class NumMatrix {
    vector<vector<int>> matrix;
    vector<vector<int>> prefix;
    int getMatrixSum(int tr, int tc, int br, int bc) {
        // inclusion exclusion principle
        int sum = prefix[br][bc];
        sum -= prefix[tr - 1][bc];
        sum -= prefix[br][tc - 1];
        sum += prefix[tr - 1][tc - 1];

        return sum;
    }
public:
    NumMatrix(vector<vector<int>>& matrix) : matrix{vector<vector<int>>(200, vector<int>(200, 0))}, prefix{vector<vector<int>>(201, vector<int>(201, 0))} {
        for (int i = 0; i < matrix.size(); i++) {
            int curr = 0;
            for (int j = 0; j < matrix[0].size(); j++) {
                this->matrix[i][j] = matrix[i][j];
                prefix[i + 1][j + 1] = prefix[i][j + 1] + curr + matrix[i][j];
                curr += matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getMatrixSum(row1 + 1, col1 + 1, row2 + 1, col2 + 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */