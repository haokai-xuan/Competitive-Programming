class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        ans = 0
        freq = defaultdict(int)
        total_pairs = 0
        left = 0
        
        N = len(nums)
        for right in range(N):
            total_pairs += freq[nums[right]]
            freq[nums[right]] += 1

            while total_pairs >= k:
                ans += N - right
                freq[nums[left]] -= 1
                total_pairs -= freq[nums[left]]
                if freq[nums[left]] == 0:
                    del freq[nums[left]]
                left += 1
                
        return ans