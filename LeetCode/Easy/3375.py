class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        min_val = min(nums)
        if min_val < k:
            return -1

        mp = set()
        for i in range(len(nums)):
            if nums[i] > k:
                mp.add(nums[i])
            
        return len(mp)