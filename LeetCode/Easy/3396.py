class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        N = len(nums)
        seen = set()

        for i in range(N - 1, -1, -1):
            if nums[i] in seen:
                return math.ceil((i + 1) / 3)

            seen.add(nums[i])

        return 0