class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        ans = []

        i = 0
        j = 0
        n = len(nums1)
        m = len(nums2)
        while i < n and j < m:
            if nums1[i][0] == nums2[j][0]:
                ans.append([nums1[i][0], nums1[i][1] + nums2[j][1]])
                i += 1
                j += 1
            elif nums1[i][0] < nums2[j][0]:
                ans.append([nums1[i][0], nums1[i][1]])
                i += 1
            else:
                ans.append([nums2[j][0], nums2[j][1]])
                j += 1
        
        if i < n:
            ans += nums1[i:]
        elif j < m:
            ans += nums2[j:]
        return ans