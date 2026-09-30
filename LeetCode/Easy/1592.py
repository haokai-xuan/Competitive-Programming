class Solution:
    def reorderSpaces(self, text: str) -> str:
        words = text.split()
        spaces = 0
        for c in text:
            if c == ' ':
                spaces += 1
        if spaces == 0:
            return text
        if len(words) == 1:
            return words[0] + ' ' * spaces
        ans = []
        for i in range(len(words)):
            ans.append(words[i])
            if i != len(words) - 1:
                ans.append((spaces // (len(words) - 1)) * ' ')
        
        if spaces % (len(words) - 1):
            ans.append((spaces - (len(words) - 1) * (spaces // (len(words) - 1))) * ' ')

        s = "".join(ans)
        return s