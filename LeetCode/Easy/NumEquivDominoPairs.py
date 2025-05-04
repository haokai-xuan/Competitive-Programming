class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        mp = defaultdict(int)
        N = len(dominoes)
        for i in range(N):
            mp[(min(dominoes[i][0], dominoes[i][1]), max(dominoes[i][0], dominoes[i][1]))] += 1

        ans = 0
        i = 0
        while i < N and mp:
            key = max(mp, key=mp.get)
            ans += mp[key] * (mp[key] - 1) // 2
            del mp[key]
            i += 1
        return ans