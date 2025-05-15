class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = []
        ans = 0
        for i in range(len(heights)):
            start = i
            while stack and stack[-1][1] > heights[i]:
                index, height = stack.pop()
                width = i - index
                ans = max(ans, width * height)
                start = index
            stack.append((start, heights[i]))
        n = len(heights)
        while stack:
            index, height = stack.pop()
            width = n - index
            ans = max(ans, width * height)

        return ans