class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int globalMin = arrays[0][0];
        int globalMax = arrays[0].back();
        int maxDist = 0;

        int currMin, currMax;

        for (int i = 1; i < arrays.size(); ++i){
            currMin = arrays[i][0];
            currMax = arrays[i].back();
            maxDist = max(maxDist, max(abs(globalMax - currMin), abs(globalMin - currMax)));

            globalMax = max(globalMax, currMax);
            globalMin = min(globalMin, currMin);
        }
        return maxDist;
    }
};
