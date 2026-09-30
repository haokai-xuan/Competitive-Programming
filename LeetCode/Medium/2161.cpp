class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, pivot);
        int numLessThanPivot = 0;
        int pivotCnts = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans[numLessThanPivot++] = nums[i];
            }
            else if (nums[i] == pivot) pivotCnts++;
        }

        int j = numLessThanPivot + pivotCnts;
        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot) {
                ans[j++] = nums[i];
            }
        }

        return ans;
    }
};