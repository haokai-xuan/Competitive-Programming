class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> prevHeights(cols);
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            vector<int> heights = matrix[i];
            for (int j = 0; j < cols; j++) {
                heights[j] = heights[j] ? prevHeights[j] + 1 : 0;
            }
            vector<int> sorted = heights;
            sort(sorted.begin(), sorted.end(), greater<int>());

            for (int j = 0; j < cols; j++) {
                ans = max(ans, sorted[j] * (j + 1));
            }

            prevHeights = heights;
        }

        return ans;
    }
};