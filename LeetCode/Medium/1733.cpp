class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<unordered_set<int>> knows(languages.size() + 1);
        for (int i = 0; i < languages.size(); i++) {
            for (auto& l : languages[i]) {
                knows[i + 1].insert(l);
            }
        }

        unordered_set<int> problemUsers;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canComm = false;
            for (auto& l : knows[u]) {
                if (knows[v].count(l)) {
                    canComm = true;
                    break;
                }
            }

            if (!canComm) {
                problemUsers.insert(u);
                problemUsers.insert(v);
            }
        }

        if (problemUsers.size() == 0) return 0;
        int ans = INT_MAX;
        for (int l = 1; l <= n; l++) {
            int toTeach = 0;
            for (auto& u : problemUsers) {
                if (!knows[u].count(l)) toTeach++;
            }
            ans = min(ans, toTeach);
        }

        return ans;
    }
};