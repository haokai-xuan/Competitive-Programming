class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        vector<int> bestFrom(events.size(), 0);
        bestFrom[events.size() - 1] = events.back()[2];
        for (int i = events.size() - 2; i >= 0; i--) {
            bestFrom[i] = max(events[i][2], bestFrom[i + 1]);
        }
        
        int ans = 0;
        for (int i = 0; i < events.size(); i++) {
            int val = events[i][2];
            ans = max(ans, val);

            int end = events[i][1];

            int left = 0, right = events.size() - 1, idx = -1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (events[mid][0] >= end + 1) {
                    idx = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            if (idx != -1) {
                ans = max(ans, val + bestFrom[left]);
            }
        }
        return ans;
    }
};