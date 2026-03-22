class Solution {
    vector<vector<int>> rotate90CW(vector<vector<int>>& v, vector<vector<int>>& target, bool& good) {
        int n = v.size();
        vector<vector<int>> rotated(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ni = j;
                int nj = n - i - 1;
                rotated[ni][nj] = v[i][j];
                if (rotated[ni][nj] != target[ni][nj]) good = false;
            }
        }
        return rotated;
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int i = 0; i < 4; i++) {
            bool good = true;
            vector<vector<int>> rotated = rotate90CW(mat, target, good);
            if (good) return true;
            mat = move(rotated);
        }
        return false;
    }
};