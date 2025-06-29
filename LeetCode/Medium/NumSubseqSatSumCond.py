class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        left = 0
        right = len(nums) - 1
        ans = 0
        MOD = int(1e9 + 7)

        while left <= right:
            if (nums[left] + nums[right] > target):
                right -= 1
                continue
            
            ans += (2 ** (right - left)) % MOD
            ans %= MOD
            left += 1

        return ans