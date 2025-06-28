class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        heap = []
        for i, num in enumerate(nums):
            heappush(heap, (-num, i))

        ans = []
        for i in range(k):
            ans.append(heappop(heap))

        ans.sort(key=lambda x: x[1])

        return [-tup[0] for tup in ans]
