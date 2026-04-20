class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left = 0, right = colors.size() - 1;
        int ans = 0;
        while (right > 0) {
            if (colors[left] != colors[right]) {
                ans = max(ans, right - left);
            }
            right--;
        }

        right = colors.size() - 1;

        while (left < colors.size() - 1) {
            if (colors[left] != colors[right]) {
                ans = max(ans, right - left);
            }
            left++;
        }

        return ans;
    }
};