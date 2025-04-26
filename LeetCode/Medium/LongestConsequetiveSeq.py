class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_set = set(nums)

        lcs = 0
        for num in nums_set:
            if num - 1 not in nums_set:
                curr = num
                temp = 1
                while curr + 1 in nums_set:
                    curr += 1
                    temp += 1
                lcs = max(lcs, temp)

        return lcs