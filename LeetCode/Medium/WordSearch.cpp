class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        return existHelper(board, word, {-1, -1});
    }

    bool existHelper(vector<vector<char>>& board, string word,
                     pair<int, int> prevpos) {
        if (word == "") {
            return true;
        }

        int rows = board.size();
        int cols = board[0].size();

        if (prevpos == make_pair(-1, -1)) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j] == word[0]) {
                        char temp = word[0];
                        board[i][j] = '#';
                        if (existHelper(board, word.substr(1), {i, j})) {
                            return true;
                        }
                        board[i][j] = temp;
                    }
                }
            }
        } else {
            int dr[4] = {0, 0, 1, -1};
            int dc[4] = {1, -1, 0, 0};

            for (int i = 0; i < 4; i++) {
                int r = prevpos.first + dr[i];
                int c = prevpos.second + dc[i];
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    if (board[r][c] == word[0]) {
                        char temp = word[0];
                        board[r][c] = '#';
                        if (existHelper(board, word.substr(1), {r, c})) {
                            return true;
                        }
                        board[r][c] = temp;
                    }
                }
            }
        }

        return false;
    }
}