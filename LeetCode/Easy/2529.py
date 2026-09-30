class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1

        pos = 0
        neg = 0

        while right >= left:
            mid = (left + right) // 2
            
            if nums[mid] == 0:
                neg_end = mid
                pos_start = mid
                while neg_end >= 0 and nums[neg_end] == 0:
                    neg_end -= 1
                neg += neg_end - left + 1

                while pos_start <= len(nums) - 1 and nums[pos_start] == 0:
                    pos_start += 1
                pos += right - pos_start + 1

                return max(pos, neg)

            if nums[mid] < 0:
                neg += mid - left + 1
                left = mid + 1
            elif nums[mid] > 0:
                pos += right - mid + 1
                right = mid - 1

        return max(pos, neg)