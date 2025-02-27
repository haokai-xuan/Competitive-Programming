class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int len = arr.size();
        vector<vector<int>> dp(len, vector<int>(len));
        unordered_map<int, int> arr_map;

        for (int i = 0; i < len; i++) {
            arr_map[arr[i]] = i;
        }
        
        int ans = 0;
        for (int i = len - 2; i >= 0; i--) {
            for (int j = len - 1; j >= i + 1; j--) {
                int prev = arr[i];
                int curr = arr[j];
                int next = prev + curr;
                int length = 2;
                if (arr_map.count(next)) {
                    length = 1 + dp[j][arr_map[next]];
                    ans = max(ans, length);
                }
                dp[i][j] = length;
            }
        }

        return ans;
    }
};