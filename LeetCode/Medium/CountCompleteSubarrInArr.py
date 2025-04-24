class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        left = 0
        N = len(nums)
        distinct = defaultdict(int)
        for i in range(N):
            if nums[i] not in distinct:
                distinct[nums[i]] = 1
        num_distinct = len(distinct)
        
        ans = 0
        curr = defaultdict(int)
        for right in range(N):
            curr[nums[right]] += 1

            while left <= right and len(curr) == num_distinct:
                ans += N - right
                curr[nums[left]] -= 1
                if curr[nums[left]] == 0:
                    del curr[nums[left]]
                left += 1

        return ans