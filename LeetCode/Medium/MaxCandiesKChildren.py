class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        def is_valid(test_k: int):
            num_groups = sum(c // test_k for c in candies)
            return num_groups >= k

        left = 1
        s = sum(candies)

        if s < k:
            return 0

        right = s // k

        while left <= right:
            mid = left + (right - left) // 2
            if is_valid(mid):
                left = mid + 1
            else:
                right = mid - 1

        return left - 1