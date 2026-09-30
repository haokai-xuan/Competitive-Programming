class DSU {
    vector<int> parent;
public:
    DSU(int n) : parent(n + 1) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (x == parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        
        int a = min(px, py);
        if (py == a) {
            py = px;
            px = a;
        } // ensure px <= py
        
        parent[py] = px;
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n);
        for (auto& r : roads) {
            dsu.unite(r[0], r[1]);
        }

        int ans = 1e4;
        for (auto& r : roads) {
            if (dsu.find(r[0]) == 1) {
                ans = min(ans, r[2]);
            }
        }

        return ans;
    }
};