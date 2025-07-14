# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        def solve(node):
            if not node.next:
                return (0, node.val * 1)

            index, curr = solve(node.next)
            index += 1
            return (index, node.val * pow(2, index) + curr)

        return solve(head)[1]