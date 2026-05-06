class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> rotated(n, vector<char>(m, '\0'));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][m - i - 1] = boxGrid[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            int obstacleRow = n;
            for (int j = n - 1; j >= 0; j--) {
                if (rotated[j][i] == '*') {
                    obstacleRow = j;
                }
                else if (rotated[j][i] == '#') {
                    if (j != obstacleRow - 1) {
                        rotated[obstacleRow - 1][i] = '#';
                        rotated[j][i] = '.';
                    }
                    obstacleRow--;
                }
            }
        }

        return rotated;
    }
};