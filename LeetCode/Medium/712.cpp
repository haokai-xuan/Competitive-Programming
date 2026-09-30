class Solution {
    vector<vector<int>> memo;
    int asciiSum(string s) {
        int sum = 0;
        for (char& c : s) sum += c;
        return sum;
    }
    int dfs(int i, int j, string& s1, string& s2) {
        if (i == s1.size() || j == s2.size()) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        
        if (s1[i] == s2[j]) memo[i][j] = s1[i] + dfs(i + 1, j + 1, s1, s2);
        else memo[i][j] = max(dfs(i + 1, j, s1, s2), dfs(i, j+ 1, s1, s2));
        
        return memo[i][j];
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        memo.assign(s1.size(), vector<int>(s2.size(), -1));
        int maxCommonAscii = dfs(0, 0, s1, s2);
        return asciiSum(s1) + asciiSum(s2) - 2 * maxCommonAscii;
    }
};