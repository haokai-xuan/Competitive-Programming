class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        left = 0
        ans = 0
        curr = 0
        mp = defaultdict(int)
        for right in range(len(nums)):
            curr += nums[right]
            mp[nums[right]] += 1
            while mp[nums[right]] >= 2:
                curr -= nums[left]
                mp[nums[left]] -= 1
                left += 1

            ans = max(ans, curr)

        return ans