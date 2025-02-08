class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix[0][0] == target) {
            return true;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int row;
        vector<int> v;
        for (int i = 0; i < m; i++) {
            v.push_back(matrix[i][0]);
            v.push_back(matrix[i][n - 1]);
        }
        bool found = find_row(v, 2 * m, m, target, row);

        if (found) {
            return true;
        }

        // search row
        if (row == -1) {
            return false;
        }
        // cout << "Row: " << row << '\n';
        v = matrix[row];
        bool in_row = find_row(v, n, m, target, row);
        return (in_row ? true : false);
    }

private:
    bool find_row(vector<int> &v, int size, int num_rows, int target, int& row) {
        int mid = size / 2;
        int left = mid - 1;
        int right = mid + 1;
        int lb = 0;
        int ub = size;
        while (true) {
            if (v[mid] == target) {
                return true;
            }

            if (left >= 0 && right < size) {
                if (v[left] < target && target < v[right]) {
                    if (left == 0)
                        row = 0;
                    else if (right == size - 1)
                        row = num_rows - 1;
                    else
                        row = (left % 2 == 0 ? left / 2 : left / 2 + 1);
                    return false;
                }
                else if (target < v[mid]) {
                    ub = mid;
                    mid = (mid - lb) / 2 + lb;
                }
                else if (target > v[mid]) {
                    lb = mid;
                    mid = (ub - mid) / 2 + mid;
                }
                left = mid - 1;
                right = mid + 1;
            }
            else if (mid == 0) {
                if (target < v[mid])
                    row = -1;
                else
                    row = 0;
                return false;
            }
            else if (mid == size - 1) {
                if (target > v[mid])
                    row = -1;
                else if (target < v[mid]) {
                    mid /= 2;
                    left = mid - 1;
                    right = mid + 1;
                    continue;
                }
                else
                    row = num_rows - 1;
                return false;
            }
        }

        return false;
    }
};