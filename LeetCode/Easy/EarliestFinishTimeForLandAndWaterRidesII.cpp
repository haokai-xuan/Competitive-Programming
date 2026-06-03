class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int landEnd = landStartTime[i] + landDuration[i];
            for (int j = 0; j < m; j++) {
                // land first
                int landFirstTime = max(0, waterStartTime[j] - landEnd) + landEnd + waterDuration[j];

                // water first
                int waterEnd = waterStartTime[j] + waterDuration[j];
                int waterFirstTime = max(0, landStartTime[i] - waterEnd) + waterEnd + landDuration[i];

                ans = min(ans, min(landFirstTime, waterFirstTime));
            }
        }
        return ans;
    }
};