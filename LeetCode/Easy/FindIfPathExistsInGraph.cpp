class DSU {
    vector<int> parent;
public:
    DSU(int n) : parent(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
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
        else parent[max(x, y)] = min(x, y);
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu = DSU(n);
        for (auto& e : edges) dsu.unite(e[0], e[1]);

        return dsu.find(source) == dsu.find(destination);
    }
};