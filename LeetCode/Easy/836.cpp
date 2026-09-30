class Solution {
    long long area(vector<int>& rec) {
        return static_cast<long long>(rec[2] - rec[0]) * static_cast<long long>(rec[3] - rec[1]);
    }
    long long intersection(vector<int>& rec1, vector<int>& rec2) {
        long long x1 = max(rec1[0], rec2[0]);
        long long y1 = max(rec1[1], rec2[1]);
        long long x2 = min(rec1[2], rec2[2]);
        long long y2 = min(rec1[3], rec2[3]);

        if (x1 > x2 || y1 > y2) return 0;

        return (x2 - x1) * (y2 - y1);
    }
    long long unite(vector<int>& rec1, vector<int>& rec2) {
        return area(rec1) + area(rec2) - intersection(rec1, rec2);
    }
    double iou(vector<int>& rec1, vector<int>& rec2) {
        return static_cast<double>(intersection(rec1, rec2)) / unite(rec1, rec2);
    }
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return iou(rec1, rec2) > 0;
    }
};