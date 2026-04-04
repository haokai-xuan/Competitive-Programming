class Solution {
    void rstrip(string& s) {
        int last = s.find_last_not_of(" ");
        s.erase(last + 1);
    }
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size() / rows;
        vector<vector<char>> mat(rows, vector<char>(cols, '\0'));
        for (int i = 0; i < encodedText.size(); i++) {
            int r = i / cols;
            int c = i % cols;
            mat[r][c] = encodedText[i];
        }

        string ans = "";

        for (int diag = 0; diag < cols; diag++) {
            int c = diag;
            for (int r = 0; r < rows; r++) {
                if (c >= cols) break;
                if (mat[r][c] != '\0')
                    ans += mat[r][c];
                c++;
            }
        }

        rstrip(ans);
        return ans;
    }
};