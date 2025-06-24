class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = []
        for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[j] == key and abs(i - j) <= k:
                    ans.append(i)
                    break

        return ans