class Solution {
    double getAreaBottom(vector<vector<int>>& squares, double line) {
        double area = 0;
        for (auto& s : squares) {
            if (s[1] < line) area += min(static_cast<double>(s[2]), line - s[1]) * s[2];
        }
        return area;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        for (auto& s : squares) totalArea += static_cast<double>(s[2]) * s[2];

        double bottom = 0, top = 1e9 + 5 * 1e4;
        while (top - bottom >= 1e-5) {
            double mid = bottom + (top - bottom) / 2;
            double areaBottom = getAreaBottom(squares, mid);
            if (areaBottom >= totalArea / 2) top = mid;
            else bottom = mid;
        }
        return top;
    }
};