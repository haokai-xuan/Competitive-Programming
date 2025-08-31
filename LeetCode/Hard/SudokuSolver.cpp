class Solution {
    bool validRowsCols(int r, int c, vector<vector<char>>& board) {
        bool seenR[10] = {false};
        bool seenC[10] = {false};
        for (int i = 0; i < 9; i++) {
            if (isdigit(board[r][i])) {
                if (seenR[board[r][i] - '0']) {
                    return false;
                }
                else {
                    seenR[board[r][i] - '0'] = true;
                }
            }

            if (isdigit(board[i][c])) {
                if (seenC[board[i][c] - '0']) {
                    return false;
                }
                else {
                    seenC[board[i][c] - '0'] = true;
                }
            }
        }
        return true;
    }
    bool validSubboxes(int r, int c, vector<vector<char>>& board) {
        int tr = (r / 3) * 3;
        int tc = (c / 3) * 3;
        bool seen[10] = {false};
        for (int i = tr; i < tr + 3; i++) {
            for (int j = tc; j < tc + 3; j++) {
                if (isdigit(board[i][j])) {
                    if (seen[board[i][j] - '0']) {
                        return false;
                    }
                    else {
                        seen[board[i][j] - '0'] = true;
                    }
                }
            }
        }
        return true;
    }
    bool validSudoku(int r, int c, vector<vector<char>>& board) {
        return validSubboxes(r, c, board) && validRowsCols(r, c, board);
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; k++) {
                        board[i][j] = k + '0';
                        if (validSudoku(i, j, board) && solve(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};