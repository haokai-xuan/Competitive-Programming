class TrieNode:
    def __init__(self):
        self.arr = [None] * 10

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, num):
        node = self.root
        for digit in str(num):
            pos = int(digit)
            if not node.arr[pos]:
                node.arr[pos] = TrieNode()
            node = node.arr[pos]

    def lex_list(self, node, temp, lst):
        if temp:
            lst.append(int(temp))
        for i in range(10):
            if node.arr[i]:
                self.lex_list(node.arr[i], temp + str(i), lst)

class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        T = Trie()
        for i in range(1, n + 1):
            T.insert(i)
        
        ans = []
        T.lex_list(T.root, "", ans)
        return ans