class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int cnt = 0;
        int rightmost = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> b = intervals[i];
            vector<int> a = intervals[i - 1];
            if ((a[0] <= b[0] && b[1] <= a[1]) || b[1] <= rightmost) cnt++;
            rightmost = max(rightmost, b[1]);
        }
        return intervals.size() - cnt;
    }
};