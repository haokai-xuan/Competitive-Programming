class DSU {
    vector<int> parent;
    vector<int> size;
public:
    DSU(int rows, int cols) : parent(rows * cols), size(rows * cols, 1) {
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int find(int pos) {
        if (parent[pos] == pos) return pos;
        parent[pos] = find(parent[pos]);
        return parent[pos];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b); // maintains invariant size[a] >= size[b]
        parent[b] = a;
        // size[a] += size[b];
        return true;
    }

    int getSize(int a) {
        return size[a];
    }
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        DSU dsu(rows, cols);
        int dr[2] = {1, 0};
        int dc[2] = {0, 1};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int curr = i * cols+ j;
                for (int k = 0; k < 2; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[i][j] == grid[nr][nc]) {
                        if (!dsu.unite(curr, nr * cols + nc)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};