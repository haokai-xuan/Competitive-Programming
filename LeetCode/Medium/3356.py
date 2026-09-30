class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        def can_form_zero_array(k):
            n = len(nums)
            total_sum = 0
            diff = [0] * (n + 1)

            for i in range(k):
                start, end, val = queries[i]

                diff[start] += val
                diff[end + 1] -= val

            for i in range(n):
                total_sum += diff[i]
                if total_sum < nums[i]:
                    return False

            return True

        left = 0
        right = len(queries)

        if not can_form_zero_array(right):
            return -1

        while left <= right:
            mid = left + (right - left) // 2

            if can_form_zero_array(mid):
                right = mid - 1
            else:
                left = mid + 1

        return left