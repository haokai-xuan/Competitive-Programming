class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        def is_valid(capability: int):
            cnt = 0

            index = 0
            while index < len(nums):
                if nums[index] <= capability:
                    cnt += 1
                    index += 2
                else:
                    index += 1

            return cnt >= k

        left = min(nums)
        right = max(nums)
        while left != right:
            mid = (left + right) // 2
            if is_valid(mid):
                right = mid
            else:
                left = mid + 1
        
        return right