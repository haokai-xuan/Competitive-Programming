class Solution {
    bool isValid(int r, int c, vector<vector<int>>& mat) {
        return r >= 0 && r < mat.size() && c >= 0 && c < mat[0].size();
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool up = true;
        vector<pair<int, int>> starts;
        for (int i = 0; i < mat[0].size(); i++) {
            starts.push_back(make_pair(0, i));
        }
        for (int i = 1; i < mat.size(); i++) {
            starts.push_back(make_pair(i, mat[0].size() - 1));
        }

        vector<int> ans;

        for (auto& p : starts) {
            vector<int> temp;
            while (isValid(p.first, p.second, mat)) {
                temp.push_back(mat[p.first][p.second]);
                p.first++;
                p.second--;
            }
            if (up) {
                reverse(temp.begin(), temp.end());
            }
                ans.insert(ans.end(), temp.begin(), temp.end());
            up = !up;
        }

        return ans;
    }
};