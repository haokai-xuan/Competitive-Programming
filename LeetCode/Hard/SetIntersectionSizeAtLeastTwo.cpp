class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        int ans = 0;
        int p1 = -1, p2 = -1;
        for (auto& v : intervals) {
            int start = v[0], end = v[1];
            int cnt = (p1 >= start ? 1 : 0)  + (p2 >= start ? 1 : 0);
            if (cnt == 2) continue;
            if (cnt == 1) {
                ans++;
                if (p1 < p2) p1 = p2;
                p2 = end;
            }
            else {
                ans += 2;
                p1 = end;
                p2 = end - 1;
            }
        }
        return ans;
    }
};