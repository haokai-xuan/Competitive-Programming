# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def solve(root):
            if not root:
                return (0, None)

            left_height, left_lca = solve(root.left)
            right_height, right_lca = solve(root.right)

            if left_height > right_height:
                return left_height + 1, left_lca
            elif right_height > left_height:
                return right_height + 1, right_lca
            else:
                return left_height + 1, root

        return solve(root)[1]