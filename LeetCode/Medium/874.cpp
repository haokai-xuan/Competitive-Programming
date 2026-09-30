class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        int dist = 0;
        int dx[4] = {0, 1, 0, -1}; // N, E, S, W -> 0, 1, 2, 3
        int dy[4] = {1, 0, -1, 0};
        int dir = 0;
        set<pair<int, int>> obs;
        for (auto& v : obstacles) {
            obs.insert({v[0], v[1]});
        }
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] < 0) {
                if (commands[i] == -2) {
                    dir = (dir + 3) % 4;
                }
                else {
                    dir = (dir + 1) % 4;
                }
            }
            else {
                for (int j = 0; j < commands[i]; j++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (obs.count({nx, ny})) break;
                    x = nx;
                    y = ny;
                    dist = max(dist, x * x + y * y);
                }
            }
        }

        return dist;
    }
};