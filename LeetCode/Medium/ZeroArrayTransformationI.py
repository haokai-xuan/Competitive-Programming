class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        diff = [0] * (n + 1)

        for start, end in queries:
            diff[start] += 1
            diff[end + 1] -= 1
        
        curr = 0
        for i in range(n):
            curr += diff[i]
            if curr < nums[i]:
                return False

        return True