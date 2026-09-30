class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (vector<int> p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> rec_stack(numCourses, false);
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (hasCycle(adj, i, visited, rec_stack)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool hasCycle(vector<vector<int>>& adj, int curr, vector<bool>& visited,
                  vector<bool>& rec_stack) {
        rec_stack[curr] = true;
        visited[curr] = true;
        for (int course : adj[curr]) {
            if (!visited[course]) {
                if (hasCycle(adj, course, visited, rec_stack)) {
                    return true;
                }
            } else if (rec_stack[course]) {
                return true;
            }
        }
        rec_stack[curr] = false;
        return false;
    }
};