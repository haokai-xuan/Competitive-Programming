# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        while curr:
            if curr.next:
                temp_val = curr.val
                curr.val = curr.next.val
                curr.next.val = temp_val
                curr = curr.next.next
            else:
                break

        return head
            
