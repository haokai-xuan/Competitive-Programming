class Solution {
    double getArea(vector<int> a, vector<int> b, vector<int> c) {
        // Area is half of absolute value of determinant of matrix of two vectors
        vector<int> v1 = {c[0] - a[0], c[1] - a[1]};
        vector<int> v2 = {c[0] - b[0], c[1] - b[1]};
        return 0.5 * abs(v1[0] * v2[1] - v2[0] * v1[1]);
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    double area = getArea(points[i], points[j], points[k]);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};