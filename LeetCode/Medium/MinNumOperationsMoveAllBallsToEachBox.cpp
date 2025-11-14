class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int cnt = 0, moves = 0;
        for (int i = 0; i < n; i++) {
            left[i] = moves;
            if (boxes[i] == '1') cnt++;
            moves += cnt;
        }
        cnt = 0, moves = 0;
        for (int i = n - 1; i >= 0; i--) {
            right[i] = moves;
            if (boxes[i] == '1') cnt++;
            moves += cnt;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(left[i] + right[i]);
        }
        return ans;
    }
};