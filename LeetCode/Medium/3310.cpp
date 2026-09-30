class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> ans;
        unordered_set<int> sus;

        vector<vector<int>> adj(n);
        vector<vector<int>> incoming(n); // incoming[i] stores vector of nodes directed at node i
        for (auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
            incoming[inv[1]].push_back(inv[0]);
        }

        queue<int> q;
        vector<bool> visited(n, false);
        visited[k] = true;
        q.push(k);
        sus.insert(k);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    sus.insert(neighbour);
                }
            }
        }

        bool canRemove = true;
        for (auto& inv : invocations) {
            if (!sus.count(inv[0]) && sus.count(inv[1])) {
                canRemove = false;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!canRemove || !sus.count(i))
                ans.push_back(i);
        }

        return ans;
    }
};