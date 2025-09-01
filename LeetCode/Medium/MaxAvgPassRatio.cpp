class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq; // max heap, {first, second}, storing change in pass ratio with one passing student increase, first, for class index, second.
        for (int i = 0; i < classes.size(); i++) {
            double change = (double)(classes[i][0] + 1) / (classes[i][1] + 1) - (double)(classes[i][0]) / (classes[i][1]);
            pq.push(make_pair(change, i));
        }

        while (extraStudents) {
            pair<double, int> p = pq.top();
            pq.pop();

            

            classes[p.second][0]++;
            classes[p.second][1]++;

            double change = (double)(classes[p.second][0] + 1) / (classes[p.second][1] + 1) - (double)(classes[p.second][0]) / (classes[p.second][1]);
            
            pq.push(make_pair(change, p.second));
            
            extraStudents--;
        }

        double ans = 0.0;
        for (auto& v : classes) {
            ans += (double)v[0] / v[1];
        }
        ans /= classes.size();

        return ans;
    }
};