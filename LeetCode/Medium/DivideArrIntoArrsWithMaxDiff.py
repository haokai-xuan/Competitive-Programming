class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        ans = []

        for i in range(len(nums) // 3):
            if abs(nums[i * 3] - nums[i * 3 + 2]) <= k:
                ans.append(nums[i * 3:i * 3 + 3])

        return ans if len(ans) == len(nums) // 3 else []