class DSU {
    vector<int> parent;

public:
    DSU(int n) : parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (px > py) {
            swap(px, py);
        } // ensure px, the smaller, becomes the root

        parent[py] = px;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        vector<int> degrees(n, 0);
        for (auto& e : edges) {
            dsu.unite(e[0], e[1]);
            degrees[e[0]]++;
            degrees[e[1]]++;
        }

        vector<vector<int>> components(n); // [root: [vertices of component]]
        for (int i = 0; i < n; i++) {
            components[dsu.find(i)].push_back(i);
        }

        // num edges in a connected graph with k vertices is k choose 2 = k(k - 1)/2
        // number of edges of a subgraph = sum of all degrees of vertices / 2
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (components[i].empty()) continue;
            int k = components[i].size();
            int degSum = 0;
            for (auto& v : components[i]) {
                degSum += degrees[v];
            }
            if ((k * (k - 1)) / 2 == degSum / 2) ans++;
        }

        return ans;
    }
};