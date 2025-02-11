class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;

        while (left < right) {
                            ans = max(ans, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            } else if (height[right] < height[left]) {
                right--;
            }
            else {
                if (left + 1 < height.size() && right - 1 >= 0 && height[left + 1] > height[right - 1]) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }

        return ans;
    }
};