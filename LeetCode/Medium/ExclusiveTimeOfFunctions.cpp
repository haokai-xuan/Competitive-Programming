class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<int> cs;
        int prevTime = 0;
        for (string& s : logs) {
            int firstColonPos = s.find(':');
            int lastColonPos = s.rfind(':');
            int func = stoi(s.substr(0, firstColonPos));
            string type = s.substr(firstColonPos + 1, lastColonPos - firstColonPos - 1);
            int time = stoi(s.substr(lastColonPos + 1));
            // cout << func << ' ' << type << ' ' << time << '\n';
            
            if (type == "start") {
                if (!cs.empty()) ans[cs.top()] += time - prevTime;
                cs.push(func);
                prevTime = time;
            }
            else {
                ans[cs.top()] += time - prevTime + 1;
                cs.pop();
                prevTime = time + 1;
            }
        }
        return ans;
    }
};