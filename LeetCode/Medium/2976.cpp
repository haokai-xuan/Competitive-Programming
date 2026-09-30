class Solution {
    void dijkstra(int start, vector<vector<int>>& dist, vector<vector<pair<int, int>>>& adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[start][start] = 0;
        pq.push({0, start});
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            int w = p.first, u = p.second;
            if (w > dist[start][u]) continue;
            for (auto& neighbour : adj[u]) {
                int new_w = w + neighbour.first;
                int v = neighbour.second;
                if (new_w < dist[start][v]) {
                    dist[start][v] = new_w;
                    pq.push({new_w, v});
                }
            }
        }
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> adj(26);
        for (int i = 0; i < original.size(); i++) {
            adj[original[i] - 'a'].push_back({cost[i], changed[i] - 'a'});
        }
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        long long ans = 0;
        for (int i = 0; i < 26; i++) dijkstra(i, dist, adj);
        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) continue;
            int res = dist[source[i] - 'a'][target[i] - 'a'];
            if (res == INT_MAX) return -1;
            ans += res;
        }
        return ans;
    }
};