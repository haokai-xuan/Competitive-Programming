class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        mp = defaultdict(int)
        for i in range(len(nums)):
            mp[nums[i]] += 1
        for i in range(len(nums)):
            if mp[0] > 0:
                mp[0] -= 1
                nums[i] = 0
            elif mp[1] > 0:
                mp[1] -= 1
                nums[i] = 1
            elif mp[2] > 0:
                mp[2] -= 1
                nums[i] = 2