class Solution {
    int n1, n2;
    vector<int> nums1;
    vector<int> nums2;
    vector<vector<int>> memo;
    int dp(int i, int j) {
        if (i == n1 || j == n2) return INT_MIN;
        if (memo[i][j] != INT_MIN) return memo[i][j];
        int take = nums1[i] * nums2[j] + max(0, dp(i + 1, j + 1));
        int skip1 = dp(i + 1, j);
        int skip2 = dp(i, j + 1);
        memo[i][j] = max({take, skip1, skip2});
        return memo[i][j];
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size();
        n2 = nums2.size();
        this->nums1 = nums1;
        this->nums2 = nums2;
        memo.assign(n1, vector<int>(n2, INT_MIN));
        return dp(0, 0);
    }
};