class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        N = len(nums)
        nums.sort()
        dp = [[] for _ in nums]

        for i in range(N - 1, -1, -1):
            if i == N - 1:
                dp[i].append(nums[i])
            else:
                res = []
                for j in range(i + 1, N):
                    if nums[j] % nums[i] == 0:
                        res = dp[j] if len(dp[j]) > len(res) else res
                if res:
                    dp[i] = [nums[i]] + res
                else:
                    dp[i].append(nums[i])

        res = []
        for i in range(N):
            res = dp[i] if len(dp[i]) > len(res) else res

        return res
