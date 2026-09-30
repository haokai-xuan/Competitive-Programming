class DSU {
    vector<int> parent;
    vector<int> area;
public:
    DSU (vector<vector<int>>& grid) : parent(grid.size() * grid[0].size()), area(grid.size() * grid[0].size(), 0) {
        for (int i = 0; i < grid.size() * grid[0].size(); i++) parent[i] = i;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) area[grid[0].size() * i + j] = 1;
            }
        }
    }
    int find(int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        parent[min(x, y)] = max(x, y);
        area[max(x, y)] += area[min(x, y)];
    }
    int getMax() {
        int ans = 0;
        for (auto& a : area) ans = max(ans, a);
        return ans;
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() * grid[0].size();
        DSU dsu = DSU(grid);

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] != 1) continue;
                int pos = grid[0].size() * r + c;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()) {
                        if (grid[nr][nc] == 1) dsu.unite(pos, nr * grid[0].size() + nc);
                    }
                }
            }
        }

        return dsu.getMax();
    }
};