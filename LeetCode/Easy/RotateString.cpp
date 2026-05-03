class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int n = s.size();
        s += s;
        return s.find(goal) != string::npos;
    }
};