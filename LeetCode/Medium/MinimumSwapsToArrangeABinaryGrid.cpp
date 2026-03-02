class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxRight(n);
        for (int i = 0; i < n; i++) {
            int rightMost1 = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) rightMost1 = j;
            }
            maxRight[i] = rightMost1;
        }

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int minNumZeros = n - i - 1;
            int rightMost1 = n - minNumZeros - 1;
            bool swapped = false;

            for (int j = i; j < n; j++) {
                if (maxRight[j] > rightMost1) continue;
                swapped = true;
                swaps += j - i;
                while (j > i) {
                    int temp = maxRight[j];
                    maxRight[j] = maxRight[j - 1];
                    maxRight[j - 1] = temp;
                    j--;
                }
                break;
            }
            if (!swapped) return -1;
        }

        return swaps;
    }
};