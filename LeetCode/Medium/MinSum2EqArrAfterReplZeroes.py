class Solution(object):
    def minSum(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        sum1 = 0
        sum2 = 0
        zero_cnt1 = 0
        zero_cnt2 = 0
        for i in range(len(nums1)):
            if nums1[i] == 0:
                sum1 += 1
                zero_cnt1 += 1
            else:
                sum1 += nums1[i]
        for i in range(len(nums2)):
            if nums2[i] == 0:
                sum2 += 1
                zero_cnt2 += 1
            else:
                sum2 += nums2[i]
        target_sum = max(sum1, sum2)
        if target_sum == sum1:
            if zero_cnt2 == 0 and target_sum != sum2:
                return -1
            else:
                return target_sum
        else:
            if zero_cnt1 == 0 and target_sum != sum1:
                return -1
            else:
                return target_sum