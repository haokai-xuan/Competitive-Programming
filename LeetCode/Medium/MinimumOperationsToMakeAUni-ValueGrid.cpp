class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> flattened;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                flattened.push_back(grid[i][j]);
            }
        }

        int mid = rows * cols / 2;
        nth_element(flattened.begin(), flattened.begin() + mid, flattened.end());
        int median = flattened[mid];

        int cnt = 0;
        int model = flattened[0] % x;
        for (int i = 0; i < rows * cols; i++) {
            if (flattened[i] % x != model) return -1;
            cnt += abs(flattened[i] - median) / x;
        }

        return cnt;
    }
};