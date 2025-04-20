class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        mp = defaultdict(int)
        N = len(answers)

        ans = 0

        for i in range(N):
            if answers[i] == 0:
                ans += 1
            elif answers[i] in mp:
                mp[answers[i]] += 1
                if mp[answers[i]] >= answers[i]:
                    del mp[answers[i]]
            else:
                mp[answers[i]] = 0
                ans += 1 + answers[i]

        return ans