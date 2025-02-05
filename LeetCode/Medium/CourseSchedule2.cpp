class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (vector<int> p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            in_degree[p[0]]++;
        }

        vector<bool> visited(numCourses, false);
        vector<bool> rec_stack(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (has_cycle(adj, i, visited, rec_stack)) {
                    return {};
                }
            }
        }
        
        vector<int> source_nodes = get_source_nodes(adj);
        return get_order(adj, source_nodes, in_degree);
    }

private:
    bool has_cycle(vector<vector<int>>& adj, int curr, vector<bool>& visited,
                   vector<bool>& rec_stack) {
        visited[curr] = true;
        rec_stack[curr] = true;
        for (int neighbour : adj[curr]) {
            if (!visited[neighbour]) {
                if (has_cycle(adj, neighbour, visited, rec_stack)) {
                    return true;
                }
            } else if (rec_stack[neighbour]) {
                return true;
            }
        }

        rec_stack[curr] = false;
        return false;
    }

    vector<int> get_source_nodes(vector<vector<int>>& adj) {
        vector<bool> visited(adj.size(), false);

        for (vector<int>& neighbours : adj) {
            for (int i : neighbours) {
                visited[i] = true;
            }
        }
        vector<int> ans;
        for (int i = 0; i < adj.size(); i++) {
            if (!visited[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    vector<int> get_order(vector<vector<int>> &adj, vector<int> &source_nodes, vector<int> &in_degree) {
        vector<int> ans;
        queue<int> q;
        
        for (int i = 0; i < in_degree.size(); i++) {
            if (in_degree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int n = q.front();
            ans.push_back(n);
            q.pop();

            for (int neighbour : adj[n]) {
                if (--in_degree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};