class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    dfs(i, j, land, temp);

                    // for (int el : temp) {
                    //     cout << el << ' ';
                    // }
                    // cout << '\n';

                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }

private:
    int m;
    int n;

    const int dr[4] = {1, -1, 0, 0};
    const int dc[4] = {0, 0, 1, -1};

    void dfs(int r, int c, vector<vector<int>> &land, vector<int> &temp) {
        land[r][c] = -1;

        if (r == m - 1 && c != n - 1 && land[r][c + 1] == 0) {
            temp.push_back(r);
            temp.push_back(c);
            return;
        }
        else if (c == n - 1 && r != m - 1 && land[r + 1][c] == 0) {
            temp.push_back(r);
            temp.push_back(c);
            return;
        }
        else if (r == m - 1 && c == n - 1) {
            temp.push_back(r);
            temp.push_back(c);
            return;
        }
        else if (r + 1 < m && c + 1 < n && land[r + 1][c] == 0 && land[r][c + 1] == 0) {
            temp.push_back(r);
            temp.push_back(c);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (land[nr][nc] == 1) {
                    dfs(nr, nc, land, temp);
                }
            }
        }
    }
};