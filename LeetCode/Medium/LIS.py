class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        lis = [1] * n
        msf = 1
        for i in range(n):
            for j in range(i + 1, n):
                if nums[j] > nums[i]:
                    if lis[i] + 1 > lis[j]:
                        lis[j] = lis[i] + 1
                        if lis[j] > msf:
                            msf = lis[j]

        return msf