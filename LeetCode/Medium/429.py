"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        if not root:
            return []

        ans = []
        q = deque([root])
        while q:
            lvl_size = len(q)
            lvl = []
            for i in range(lvl_size):
                node = q.popleft()
                lvl.append(node.val)
                for j in range(len(node.children)):
                    q.append(node.children[j])
            ans.append(lvl)
        
        return ans