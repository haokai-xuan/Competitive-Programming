class DSU {
    vector<int> parent;
public:
    DSU(int cells) : parent(cells) {
        for (int i = 0; i < cells; i++) parent[i] = i;
    }
    int find(int pos) {
        if (parent[pos] == pos) return pos;
        parent[pos] = find(parent[pos]);
        return parent[pos];
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a > b) swap(a, b); // maintains invariant a <= b
        parent[b] = a;
    }
};

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        unordered_map<int, vector<pair<int, int>>> mp = {
            {1, {{0, -1}, {0, 1}}},
            {2, {{-1, 0}, {1, 0}}},
            {3, {{0, -1}, {1, 0}}},
            {4, {{1, 0}, {0, 1}}},
            {5, {{-1, 0}, {0, -1}}},
            {6, {{-1, 0}, {0, 1}}},
        };

        int rows = grid.size(), cols = grid[0].size();
        DSU dsu(rows * cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (auto& [dr, dc] : mp[grid[i][j]]) {
                    int nr = i + dr, nc = j + dc;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                        for (auto& [dr2, dc2] : mp[grid[nr][nc]]) {
                            int nr2 = nr + dr2, nc2 = nc + dc2;
                            if (nr2 == i && nc2 == j) {
                                dsu.unite(i * cols + j, nr * cols + nc);
                                break;
                            }
                        }
                    }
                }
            }
        }

        return dsu.find(rows * cols - 1) == 0;
    }
};