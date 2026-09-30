class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int prevX = points[0][0];
        int prevY = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            int x =  points[i][0];
            int y =  points[i][1];
            ans += max(abs(x - prevX), abs(y - prevY));
            prevX = x;
            prevY = y;
        }
        return ans;
    }
};