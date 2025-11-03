class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        char currColor;
        int currMax = 0;
        int runningSum = 0;
        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] != currColor) {
                ans += runningSum - currMax;
                currColor = colors[i];
                currMax = neededTime[i];
                runningSum = neededTime[i];
            }
            else {
                currMax = max(currMax, neededTime[i]);
                runningSum += neededTime[i];
            }
        }
        ans += runningSum - currMax;
        return ans;
    }
};