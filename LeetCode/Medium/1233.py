class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.isEnd = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def getFolders(self):
        res = []

        def dfs(node, path):
            if node.isEnd:
                res.append('/' + '/'.join(path))
                return
            for s, ch in node.children.items():
                dfs(ch, path + [s])

        dfs(self.root, [])
        return res

    def insert(self, s):
        lst = []
        curr = []
        for c in s:
            if c == '/' and len(curr):
                lst.append(''.join(curr))
                curr = []
            elif c != '/':
                curr.append(c)
        lst.append(''.join(curr))

        temp = self.root
        for name in lst:
            if name in temp.children:
                node = temp.children[name]
                if node.isEnd:
                    return
                temp = temp.children[name]
                continue
            temp.children[name] = TrieNode()
            temp = temp.children[name]
        temp.isEnd = True


class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        T = Trie()
        for f in folder:
            T.insert(f)

        return T.getFolders()