class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        N = len(nums)
        nums.sort()
        ans = 0

        def bs(left, cutoff):
            right = N

            while left < right:
                mid = (left + right) // 2
                if nums[mid] < cutoff:
                    left = mid + 1
                elif nums[mid] >= cutoff:
                    right = mid

            return left
                    

        for i in range(N):
            lowest = lower - nums[i]
            highest = upper - nums[i]

            ans += bs(i + 1, highest + 1) - bs(i + 1, lowest)

        return ans