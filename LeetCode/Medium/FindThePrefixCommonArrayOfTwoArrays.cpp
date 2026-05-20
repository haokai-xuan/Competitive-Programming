class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> a, b;
        vector<int> ans(A.size(), 0);
        for (int i = 0; i < A.size(); i++) {
            if (b.count(A[i])) {
                ans[i] = ans[i - 1] + 1;
                if (a.count(B[i])) ans[i]++;
            }
            else if (a.count(B[i]) || A[i] == B[i]) {
                if (!i) ans[i] = 1;
                else ans[i] = ans[i - 1] + 1;
            }
            else if (i > 0) ans[i] = ans[i - 1];

            a.insert(A[i]);
            b.insert(B[i]);
        }
        return ans;
    }
};