class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> adj(n * n + 1, -1);

        bool left_to_right = true;
        int cnt = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (left_to_right) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] != -1) {
                        adj[cnt] = board[i][j];
                    }
                    cnt++;
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] != -1) {
                        adj[cnt] = board[i][j];
                    }
                    cnt++;
                }
            }
            left_to_right = !left_to_right;
        }

        queue<int> q;
        q.push(1);

        vector<int> dist(n * n + 1, -1);
        dist[1] = 0;

        vector<bool> vis(n * n + 1, false);
        vis[1] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();


            for (int i = 1; i <= 6; i++) {
                int next = curr + i;

                if (next > n * n) {
                    break;
                }

                int dest = (adj[next] != -1 ? adj[next] : next);

                if (!vis[dest]) {
                    vis[dest] = true;
                    q.push(dest);
                    dist[dest] = dist[curr] + 1;
                }

                if (dest == n * n) {
                    return dist[dest];
                }
            }
        }

        return -1;
    }
};