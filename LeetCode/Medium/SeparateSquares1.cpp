class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double tot_area = total_area(squares);
        // cout << "Total area: " << tot_area << '\n';

        double ub = get_ub(squares);
        double lb = 0;
        double mid;
        double area_above;
        
        // # iterations = log2(range of vals / precision) + 1
        for (int i = 0; i < 48; i++) {
            mid = (lb + ub) / 2;
            // cout << "Mid: " << mid << ", ";
            area_above = upper_area(squares, mid);
            // cout << "Upper area: " << area_above << ", ";
            if (abs(area_above - 0.5 * tot_area) < 1e-5) {
                ub = mid;
            }

            else if (area_above > 0.5 * tot_area) {
                // cout << "Set lb to mid\n";
                lb = mid;
            }
            else {
                // cout << "Set ub to mid\n";
                ub = mid;
            }
        }
        return mid;
    }

private:
    double upper_area(vector<vector<int>> &squares, double y_line) {
        double area_above = 0;
        for (const auto &sq : squares) {
            if (sq[1] + sq[2] <= y_line) {
                continue;
            }
            double width = sq[2];
            double height = (sq[1] + sq[2]) - max((double)sq[1], y_line);
            area_above += width * height;
        }

        return area_above;
    }

    double total_area(vector<vector<int>> &squares) {
        double area = 0;
        for (const auto &sq : squares) {
            area += (double)sq[2] * sq[2];
        }
        return area;
    }

    double get_ub(vector<vector<int>> &squares) {
        double max_ = 0;
        for (const auto &sq : squares) {
            if (sq[1] + sq[2] > max_)
                max_ = sq[1] + sq[2];
        }

        return max_;
    }
};