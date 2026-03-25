class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = sandwiches.size();
        queue<int> q;
        for (auto& s : students) q.push(s);
        
        int i = 0;
        int cnt = 0;

        while (!q.empty()) {
            if (q.front() == sandwiches[i]) {
                i++;
                q.pop();
                cnt = 0;
            }
            else {
                int st = q.front();
                q.pop();
                q.push(st);
                cnt++;
                if (cnt == n - i) return cnt;
            }
        }

        return 0;
    }
};