class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        if (nums.size() <= 2) return nums;
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }

        vector<int> ans = arr1;
        ans.reserve(arr1.size() + arr2.size());
        ans.insert(ans.end(), arr2.begin(), arr2.end());

        return ans;
    }
};