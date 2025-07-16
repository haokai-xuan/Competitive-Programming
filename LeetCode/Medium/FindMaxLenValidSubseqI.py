class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        N = len(nums)
        ans = 0
        curr = 0

        for num in nums:
            if num % 2 == 0:
                curr += 1
        ans = max(ans, curr)
        curr = 0

        for num in nums:
            if num % 2:
                curr += 1
        ans = max(ans, curr)
        curr = 0

        prev = 1
        for num in nums:
            if not prev and num % 2 == 0:
                curr += 1
                prev = (prev + 1) % 2
            elif prev and num % 2:
                curr += 1
                prev = (prev + 1) % 2
        ans = max(ans, curr)
        curr = 0

        prev = 0
        for num in nums:
            if not prev and num % 2 == 0:
                curr += 1
                prev = (prev + 1) % 2
            elif prev and num % 2:
                curr += 1
                prev = (prev + 1) % 2
        ans = max(ans, curr)
        curr = 0

        return ans