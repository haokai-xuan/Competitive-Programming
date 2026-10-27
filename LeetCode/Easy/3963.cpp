class Solution {
public:
    vector<string> createGrid(int m, int n) {
        set<pair<int, int>> s; // stores path cells
        vector<string> ans;

        int mid = n / 2;
        for (int i = 0; i <= mid; i++) {
            s.insert({0, i});
            s.insert({m - 1, n - i});
        }
        for (int i = 0; i < m; i++) s.insert({i, mid});

        for (int i = 0; i < m; i++) {
            string row = "";
            for (int j = 0; j < n; j++) {
                if (s.count({i, j})) row += '.';
                else row += '#';
            }
            ans.push_back(row);
        }

        return ans;
    }
};