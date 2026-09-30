class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1);
        for (auto& v : connections) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        unordered_map<int, int> idToGrid;
        vector<bool> status(c + 1, true);
        vector<set<int>> grid(c);
        vector<bool> visited(c + 1, false);
        int gridNum = -1;
        for (int i = 1; i <= c; i++) {
            if (!visited[i]) {
                gridNum++;
                vector<bool> v(c + 1, false);
                queue<int> q;
                idToGrid[i] = gridNum;
                q.push(i);
                grid[gridNum].insert(i);
                while (!q.empty()) {
                    int top = q.front();
                    q.pop();
                    for (auto& neighbour : adj[top]) {
                        if (!visited[neighbour]) {
                            visited[neighbour] = true;
                            idToGrid[neighbour] = gridNum;
                            q.push(neighbour);
                            grid[gridNum].insert(neighbour);
                        }
                    }
                }
            }
        }

        vector<int> ans;

        for (auto& v : queries) {
            int type = v[0], id = v[1];
            int gNum = idToGrid[id];
            if (type == 2) {
                grid[gNum].erase(id);
                status[id] = false;
            }
            else {
                if (grid[gNum].empty())
                    ans.push_back(-1);
                else if (status[id])
                    ans.push_back(id);
                else
                    ans.push_back(*grid[gNum].begin());
            }
        }
        return ans;
    }
};