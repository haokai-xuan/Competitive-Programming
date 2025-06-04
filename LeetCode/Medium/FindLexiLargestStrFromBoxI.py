class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends == 1:
            return word

        n = len(word)
        longest_len = n - numFriends + 1
        
        ans = ""
        for i in range(n):
            substr = word[i:i + longest_len]
            ans = max(ans, substr)
        return ans