class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        curr_min = nums[0]
        stack = [(curr_min, float('inf'))]

        for num in nums[1:]:
            while stack and num >= stack[-1][0]:
                stack.pop()

            if stack and stack[-1][1] < num and num < stack[-1][0]:
                return True
            
            if stack:
                stack.append((num, curr_min))
            else:
                stack.append((num, curr_min))
            curr_min = min(curr_min, num)

        return False