class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2] * 2});
        }
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0}); // {cost, node}
        while (!pq.empty()) {
            vector<int> container = pq.top();
            pq.pop();
            int cost = container[0];
            int u = container[1];
            if (cost > dist[u]) continue;
            for (auto neighbour : adj[u]) {
                int v = neighbour.first;
                int w = neighbour.second;
                int new_cost = cost + w;
                if (new_cost < dist[v]) {
                    dist[v] = new_cost;
                    pq.push({new_cost, v});
                }
            }
        }
        return dist[n - 1] != INT_MAX ? dist[n - 1] : -1;
    }
};