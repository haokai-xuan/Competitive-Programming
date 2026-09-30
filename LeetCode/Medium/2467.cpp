class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<int> bob_steps(amount.size(), -1); // bob_steps[i] denotes node at step i
        vector<int> bob_stepped(amount.size(), -1); // bob_stepped[i] denotes step number at node i
        int bob_step = 0;

        vector<vector<int>> adj(amount.size());

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        vector<int> visited(amount.size(), false);
        visited[bob] = true;
        q.push(bob);
        bob_steps[0] = bob;
        bob_stepped[bob] = 0;
        vector<int> parent(amount.size(), -1);
        vector<int> bob_path;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            bool exit = false;

            for (const int &neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    bob_stepped[neighbour] = bob_stepped[node] + 1;
                    parent[neighbour] = node;
                }
                if (neighbour == 0)
                    exit = true;
            }
            if (exit)
                break;
        }
        

        int step = bob_stepped[0];
        int curr = 0;
        while (step != -1) {
            bob_path.push_back(curr);
            bob_steps[step] = curr;
            curr = parent[curr];
            step--;
        }

        // for (int i = 0; i < bob_steps.size(); i++) {
        //     cout << "STEP: " << i << ' ' << bob_steps[i] << '\n';
        // }

        // for (int i = 0; i < bob_steps.size(); i++) {
        //     cout << "Node: " << i << ' ' << bob_stepped[i] << '\n';
        // }
        
        int ans = INT_MIN;
        dfs(adj, amount, bob_steps, bob_stepped, bob_path, -1, 0, 0, 0, ans);
        return ans;
    }

private:
    void dfs(vector<vector<int>> &adj, vector<int> &amount, vector<int> &bob_steps, vector<int> &bob_stepped, vector<int> &bob_path, int parent, int step, int node, int income, int &max_income) {
        auto it = find(bob_path.begin(), bob_path.end(), node);
        if (bob_steps[step] == node)
            income += amount[node] / 2;
        else if (it != bob_path.end() && bob_stepped[node] > step)
            income += amount[node];
        else if (it == bob_path.end())
            income += amount[node];

        cout << "Alice at node " << node << " at step " << step 
     << " with income " << income << '\n';
        
        bool is_leaf = true;
        for (const int &next : adj[node]) {
            if (next != parent) {
                is_leaf = false;
                dfs(adj, amount, bob_steps, bob_stepped, bob_path, node, step + 1, next, income, max_income);
            }
        }

        if (is_leaf)
            max_income = max(income, max_income);
    }
};