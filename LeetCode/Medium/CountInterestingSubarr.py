class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        N = len(nums)
        prefix_sum = 0
        mp = defaultdict(int)
        mp[0] = 1

        ans = 0

        for i in range(N):
            if nums[i] % modulo == k:
                prefix_sum += 1
            ans += mp[(prefix_sum - k + modulo) % modulo]
            mp[prefix_sum % modulo] += 1

        return ans