class Solution {
    int lb = 10;
    int ub = 1e9;
    void updateSeqNums(int curr, vector<int>& seqNums) {
        int last = curr % 10;
        if (last == 9) return;

        curr = curr * 10 + last + 1;
        if (curr >= lb && curr <= ub)
            seqNums.push_back(curr);
        updateSeqNums(curr, seqNums);
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> seqNums;

        for (int i = 1; i <= 9; i++) {
            updateSeqNums(i, seqNums);
        }
        
        vector<int> ans;
        for (auto& n : seqNums) {
            if (n >= low && n <= high) ans.push_back(n);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};