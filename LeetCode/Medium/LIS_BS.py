class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def custom_bisect_left(arr, num):
            left = 0
            right = len(arr) - 1
            while left < right:
                mid = (left + right) // 2
                if arr[mid] >= num:
                    right = mid
                else:
                    left = mid + 1

            return left



        sub = []
        for i in range(len(nums)):
            if len(sub) == 0 or nums[i] > sub[-1]:
                sub.append(nums[i])
            else:
                index = custom_bisect_left(sub, nums[i])
                sub[index] = nums[i]

        return len(sub)