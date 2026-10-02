class Solution {
    vector<string> ans;
    int pairs;
    void backtrack(string curr, int openCnt, int closeCnt) {
        if (openCnt == pairs && closeCnt == pairs) {
            ans.push_back(curr);
            return;
        }

        if (openCnt < pairs) backtrack(curr + '(', openCnt + 1, closeCnt);
        if (closeCnt < openCnt) backtrack(curr + ')', openCnt, closeCnt + 1);
    }
public:
    vector<string> generateParenthesis(int n) {
        pairs = n;
        backtrack("", 0, 0);

        return ans;
    }
};