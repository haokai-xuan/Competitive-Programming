class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, bool> vis;
        unordered_map<string, int> dist;

        dist[startGene] = 0;

        queue<string> q;
        q.push(startGene);

        vis[startGene] = true;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            vector<string> neighbours = get_neighbours(curr, bank);

            for (string neighbour : neighbours) {
                if (vis.find(neighbour) == vis.end()) {
                    if (find(bank.begin(), bank.end(), neighbour) !=
                        bank.end()) {
                        vis[neighbour] = true;
                        q.push(neighbour);
                        dist[neighbour] = dist[curr] + 1;

                        if (neighbour == endGene) {
                            return dist[neighbour];
                        }
                    }
                }
            }
        }

        return -1;
    }

private:
    vector<string> get_neighbours(string s, vector<string> &bank) {
        vector<string> ans;
        vector<char> chrs = {'A', 'T', 'C', 'G'};
        for (int i = 0; i < s.size(); i++) {
            for (char c : chrs) {
                string temp = s;
                temp[i] = c;
                if (temp != s &&
                    find(bank.begin(), bank.end(), temp) != bank.end()) {
                        ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};