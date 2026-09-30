class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        vector<bool> visited(arr.size(), false);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (arr[node] == 0) return true;

            for (const int neighbour : {node + arr[node], node - arr[node]}) {
                if (neighbour >= 0 && neighbour < arr.size() && !visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

        return false;
    }
};