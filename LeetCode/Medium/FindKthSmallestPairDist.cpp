class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.back() - nums.front();

        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0; // number of pairs with distance <= mid

            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    int dist = abs(nums[i] - nums[j]);
                    if (dist > mid) {
                        break;
                    }
                    else{
                        cnt++;
                    }
                }
            }
            if (cnt >= k){
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
