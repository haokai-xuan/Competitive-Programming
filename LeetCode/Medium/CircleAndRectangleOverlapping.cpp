class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closest_x = max(x1, min(xCenter, x2));
        int closest_y = max(y1, min(yCenter, y2));

        int diff_x = closest_x - xCenter;
        int diff_y = closest_y - yCenter;

        return diff_x * diff_x + diff_y * diff_y <= radius * radius;
    }
};