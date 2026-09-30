class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        N = len(nums)
        left = 0
        left_occ = -1
        max_cnt = 0
        max_num = max(nums)
        ans = 0
        for right in range(N):
            if nums[right] == max_num:
                max_cnt += 1
                if right > left_occ:
                    left_occ = right
            temp = 0
            while left <= left_occ and max_cnt >= k:
                temp += 1
                if nums[left] == max_num:
                    max_cnt -= 1
                left += 1
            mult = N - right
            ans += mult * temp

        return ans