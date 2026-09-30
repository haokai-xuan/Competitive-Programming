class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y]) parent[x] = y;
        else if (rank[y] < rank[x]) parent[y] = x;
        else {
            parent[y] = x;
            rank[x]++;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;

        // virtual bodes representing top and bottom rows
        int TOP = n;
        int BOTTOM = n + 1;

        DSU dsu(n + 2);

        vector<vector<bool>> land(row, vector<bool>(col, false));
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        for (int day = cells.size() - 1; day >= 0; day--) {
            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;
            land[r][c] = true;

            int id = r * col + c;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && land[nr][nc]) {
                    dsu.unite(id, nr * col + nc);
                }
            }

            if (r == 0) dsu.unite(id, TOP);
            if (r == row - 1) dsu.unite(id, BOTTOM);

            if (dsu.connected(TOP, BOTTOM)) return day;
        }
        return 0;
    }
};