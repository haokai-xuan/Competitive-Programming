class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        mp = defaultdict(int)
        for i in range(len(nums)):
            mp[nums[i]] += 1
        print(mp)
        heap = []
        heapify(heap)
        for key in mp:
            heappush(heap, (-mp[key], key))
        ans = []
        for i in range(k):
            element = heappop(heap)[1]
            ans.append(element)

        return ans