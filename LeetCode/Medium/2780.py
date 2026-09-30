class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        majority = 0
        count = 0
        for candidate in nums:
            if count == 0:
                majority = candidate

            if candidate == majority:
                count += 1
            else:
                count -= 1

        total_count = nums.count(majority)
        
        count = 0
        for i in range(len(nums)):
            if nums[i] == majority:
                count += 1
            
            if count > (i + 1) // 2 and (total_count - count) > (len(nums) - (i + 1)) // 2:
                return i

        return -1