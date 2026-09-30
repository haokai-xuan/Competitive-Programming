class Solution {
    pair<int, int> indexToCoord(int cols, int i) {
        return {i / cols, i % cols};
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size() * matrix[0].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            pair<int, int> coord = indexToCoord(matrix[0].size(), mid);
            int val = matrix[coord.first][coord.second];
            if (val == target) return true;
            else if (val < target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};