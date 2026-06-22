class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> cnt;
        for (char& c : text) cnt[c]++;
        int bCnt = cnt['b'];
        int aCnt = cnt['a'];
        int lCnt = cnt['l'] / 2;
        int oCnt = cnt['o'] / 2;
        int nCnt = cnt['n'];
        int ans = min(bCnt, min(aCnt, min(lCnt, min(oCnt, nCnt))));
        return ans;
    }
};