class Solution {
    struct Cell {
        int t, r, c;
    };
    struct Compare {
        bool operator()(const Cell& a, const Cell& b) {
            return a.t > b.t;
        }
    };
    vector<Cell> getNeighbours(vector<vector<int>>& v, int t, int r, int c) {
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        vector<Cell> ans;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < v.size() && nc >= 0 && nc < v.size()) {
                ans.push_back(Cell{v[nr][nc], nr, nc});
            }
        }
        return ans;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int curr = grid[0][0];
        priority_queue<Cell, vector<Cell>, Compare> pq;
        pq.push(Cell{grid[0][0], 0, 0});
        while (!pq.empty()) {
            Cell c = pq.top();
            pq.pop();
            if (c.r == n - 1 && c.c == n - 1) break;
            vector<Cell> neighbours = getNeighbours(grid, curr, c.r, c.c);
            for (Cell& cell : neighbours) {
                if (!visited[cell.r][cell.c]) {
                    pq.push(cell);
                    visited[cell.r][cell.c] = true;
                }
            }
            curr = max(curr, pq.top().t);
        }

        return curr;
    }
};