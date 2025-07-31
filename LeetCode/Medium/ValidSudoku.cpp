class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check sub-boxes
        int row;
        int col;
        for (int i = 0; i < 9; i++) {
            if (i % 3 == 0) {
                row = i;
                col = 0;
            }
            vector<bool> seen(10, false);
            for (int j = row; j <= row + 2; j++) {
                for (int k = col; k <= col + 2; k++) {
                    if (isdigit(board[j][k])) {
                        if (seen[board[j][k]])
                            return false;
                        seen[board[j][k]] = true;
                    }
                }
            }
            col += 3;
        }

        // check rows and cols
        for (int i = 0; i < 9; i++) {
            vector<bool> seenRows(10, false);
            vector<bool> seenCols(10, false);
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j])) {
                    if (seenRows[board[i][j]])
                        return false;
                    seenRows[board[i][j]] = true;
                }
                if (isdigit(board[j][i])) {
                    if (seenCols[board[j][i]])
                        return false;
                    seenCols[board[j][i]] = true;
                }
            }
        }

        return true;
    }
};