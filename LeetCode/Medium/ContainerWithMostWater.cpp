class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right) {
            int width = right - left;
            ans = max(ans,  width * min(height[left], height[right]));
            if (height[left] > height[right]) {
                right--;
            }
            else {
                left++;
            }
        }
        return ans;
    }
};