# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def getDirections(self, root, startValue, destValue):
        """
        :type root: Optional[TreeNode]
        :type startValue: int
        :type destValue: int
        :rtype: str
        """
        def LCA(root, p, q):
            if not root or root.val == p or root.val == q:
                return root
            
            left = LCA(root.left, p, q)
            right = LCA(root.right, p, q)

            if left and right:
                return root

            return left if left else right

        def dfs(root, end_val, path):
            if not root:
                return False
            if root.val == end_val:
                return True
            if dfs(root.left, end_val, path):
                path.append('L')
                return True
            elif dfs(root.right, end_val, path):
                path.append('R')
                return True

            return False
            

        pivot = LCA(root, startValue, destValue)
        s_path = []
        e_path = []
        dfs(pivot, startValue, s_path)
        dfs(pivot, destValue, e_path)
        e_path.reverse()
        ups = len(s_path)
        
        ans = "U" * ups
        for c in e_path:
            ans += c

        return ans