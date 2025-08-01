class Solution {
    void getRows(int numRows, vector<vector<int>>& v) {
        if (numRows == 1) {
            v.push_back({1});
            return;
        }
        else if (numRows == 2) {
            v.push_back({1});
            v.push_back({1, 1});
            return;
        }
        getRows(numRows - 1, v);
        vector<int> row;
        row.push_back(1);
        for (int i = 0; i < v.back().size() - 1; i++)
            row.push_back(v.back()[i] + v.back()[i + 1]);
        row.push_back(1);
        
        v.push_back(row);
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        getRows(numRows, v);
        return v;
    }
};